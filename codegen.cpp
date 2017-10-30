/*************************************************************************
 Class CodeGen.cpp
 -------------------
 date                : december 2013
 auteur           	 : TA Alexandre
 *************************************************************************/

//---------------------------------------------------------------- INCLUDES
#include <sstream>
//----------------------------------------------------------------
#include "codegen.h"
#include "scc.hpp"
#include "treenode.h"
//---------------------------------------------------------------- NAMESPACES
using namespace std;
//---------------------------------------------------------------- GLOBAL VARIABLES
static IRBuilder<> Builder(getGlobalContext());
string ERROR_FILE = "error.txt";
//---------------------------------------------------------------- METHODS

/* Returns an LLVM type based on the identifier */
static Type *typeOf(const LVIdentifier& type)
{
	if (type.name.compare("int") == 0) {
		return Type::getInt64Ty(getGlobalContext());
	}
	else if (type.name.compare("double") == 0) {
		return Type::getDoubleTy(getGlobalContext());
	}
	return Type::getVoidTy(getGlobalContext());
}


/* Compile the AST into a module */
void CodeGenContext::generateCode(LVBlock& root, LVBlock *blockStmtsMain, VariableList *listMain, char *file)
{
	/* Create the top level interpreter function to call as entry */
	vector<Type*> argTypes;
	VariableList::const_iterator it;
	for (it = listMain->begin(); it != listMain->end(); it++) {
		argTypes.push_back(typeOf((**it).type));
	}
	
	FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), makeArrayRef(argTypes), false);
	mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", mainFunction, 0);
	
	/* Push a new variable/block context */
	pushBlock(bblock);
	
	root.codeGen(*this); /* emit bytecode for the toplevel block */
	ReturnInst::Create(getGlobalContext(), bblock);
	popBlock();
	
	/* Print the bytecode in a human-readable format
	 to see if our program compiled properly
	 */
	PassManager pm;
    llvm::raw_fd_ostream fileStream(file, ERROR_FILE);
    pm.add(llvm::createPrintModulePass(& fileStream));
	pm.run(*module);
}

/* Executes the AST by running the main function */
GenericValue CodeGenContext::runCode() {
	ExecutionEngine *ee = EngineBuilder(module).create();
	vector<GenericValue> noargs;
	GenericValue v = ee->runFunction(mainFunction, noargs);
	return v;
}

/* -- Code Generation -- */

/* Code for integer bytecode */
Value* LVInteger::codeGen(CodeGenContext& context)
{
	return ConstantInt::get(Type::getInt32Ty(getGlobalContext()), value);
}

/* Code for double bytecode */
Value* LVDouble::codeGen(CodeGenContext& context)
{
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), value);
}

/* Code for identifier bytecode */
Value* LVIdentifier::codeGen(CodeGenContext& context)
{
	if (context.locals().find(name) == context.locals().end()) {
		std::cerr << "undeclared variable " << name << endl;
		return NULL;
	}
	return new LoadInst(context.locals()[name], "", false, context.currentBlock());
}

/* Code for method call bytecode */
Value* LVMethodCall::codeGen(CodeGenContext& context)
{
	Function *function = context.module->getFunction(id.name.c_str());
	if (function == NULL) {
		std::cerr << "no such function " << id.name << endl;
	}
	std::vector<Value*> args;
	if(!arguments.empty()){
		ExpressionList::const_iterator it;
		for (it = arguments.begin(); it != arguments.end(); it++) {
			args.push_back((**it).codeGen(context));
		}
	}
	CallInst *call = CallInst::Create(function, makeArrayRef(args), "", context.currentBlock());
	return call;
}

/* Code for binary operator bytecode */
Value* LVBinaryOperator::codeGen(CodeGenContext& context)
{
	Instruction::BinaryOps instr;
	Value *L = lhs.codeGen(context);
	Value *R = rhs.codeGen(context);
	if (L == 0 || R == 0) return 0;
	
	switch (op) {
		case _PLUS: 	instr = Instruction::Add; goto math;
		case _MINUS: 	instr = Instruction::Sub; goto math;
		case _MULT: 	instr = Instruction::Mul; goto math;
		case _DIV: 		instr = Instruction::SDiv; goto math;
			
		case _ASSIGN:
			LVAssignment assn((LVIdentifier&)lhs, rhs);
			assn.codeGen(context);
	}
	
	return NULL;
math:
	return BinaryOperator::Create(instr, lhs.codeGen(context),
								  rhs.codeGen(context), "", context.currentBlock());
}

/* Code for assignment bytecode */
Value* LVAssignment::codeGen(CodeGenContext& context)
{
	if (context.locals().find(lhs.name) == context.locals().end()) {
		std::cerr << "undeclared variable " << lhs.name << endl;
		return NULL;
	}
	return new StoreInst(rhs.codeGen(context), context.locals()[lhs.name], false, context.currentBlock());
}

/* Code for block bytecode */
Value* LVBlock::codeGen(CodeGenContext& context)
{
	StatementList::const_iterator it;
	Value *last = NULL;
	for (it = statements.begin(); it != statements.end(); it++) {
		last = (**it).codeGen(context);
	}
	return last;
}

/* Code for expression statement bytecode */
Value* LVExpressionStatement::codeGen(CodeGenContext& context)
{
	return expression.codeGen(context);
}

/* Code for return bytecode */
Value* LVReturnStatement::codeGen(CodeGenContext& context)
{
	Value *returnValue = expression.codeGen(context);
	context.setCurrentReturnValue(returnValue);
	return returnValue;
}

/* Code for variable declaration bytecode */
Value* LVVariableDeclaration::codeGen(CodeGenContext& context)
{
	AllocaInst *alloc = new AllocaInst(typeOf(type), id.name.c_str(), context.currentBlock());
	context.locals()[id.name] = alloc;
	if (assignmentExpr != NULL) {
		LVAssignment assn(id, *assignmentExpr);
		assn.codeGen(context);
	}
	return alloc;
}

/* Code forglobal variable bytecode */
Value* LVVariableGlobalDeclaration::codeGen(CodeGenContext& context)
{
	// LLVM context.
	LLVMContext &Context = getGlobalContext();
	GlobalVariable *data;
	if(typeGlobal == _INT || typeGlobal == _NONE)
	{
		data = new GlobalVariable(
								  context.getModule(), Type::getInt64Ty(getGlobalContext()), false /* constant */,
								  GlobalVariable::ExternalLinkage, ConstantInt::get(Type::getInt32Ty(getGlobalContext()), value),
								  id.name.c_str());
	} else if(typeGlobal == _TAB)
	{
		ArrayType *DataType = ArrayType::get(Type::getInt64Ty(Context), value);
		data = new GlobalVariable(
								  context.getModule(), DataType, false /* constant */,
								  GlobalVariable::ExternalLinkage, ConstantInt::get(Type::getInt32Ty(getGlobalContext()), value),
								  id.name.c_str());
	}
	AllocaInst *alloc = new AllocaInst(Type::getInt64Ty(getGlobalContext()), id.name.c_str(), context.currentBlock());
	context.locals()[id.name] = alloc;
	return data;
}

/* Code for function declaration bytecode */
Value* LVFunctionDeclaration::codeGen(CodeGenContext& context)
{
	vector<Type*> argTypes;
	VariableList::const_iterator it;
	for (it = arguments.begin(); it != arguments.end(); it++) {
		argTypes.push_back(typeOf((**it).type));
	}
	FunctionType *ftype = FunctionType::get(typeOf(type), makeArrayRef(argTypes), false);
	Function *function = Function::Create(ftype, GlobalValue::InternalLinkage, id.name.c_str(), context.module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", function, 0);
	
	context.pushBlock(bblock);
	
	Function::arg_iterator argsValues = function->arg_begin();
    Value* argumentValue;
	
	for (it = arguments.begin(); it != arguments.end(); it++) {
		(**it).codeGen(context);
		
		argumentValue = argsValues++;
		argumentValue->setName((*it)->id.name.c_str());
		StoreInst *inst = new StoreInst(argumentValue, context.locals()[(*it)->id.name], false, bblock);
	}
	
	block.codeGen(context);
	ReturnInst::Create(getGlobalContext(), context.getCurrentReturnValue(), bblock);
	
	context.popBlock();
	return function;
}

/* Code for if-then statement bytecode */
Value* LVIfStatement::codeGen(CodeGenContext& context)
{
	// TODO
	return NULL;
}

/* Code for if-then-else statement bytecode */
Value* LVIfElseStatement::codeGen(CodeGenContext& context)
{
	// TODO
	return NULL;
}

/* Code for for statement bytecode */
Value* LVForStatement::codeGen(CodeGenContext& context)
{
	// TODO
	return NULL;
}
