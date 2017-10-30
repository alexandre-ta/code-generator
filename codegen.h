/*************************************************************************
 Header CodeGen.h
 -------------------
 date                : december 2013
 auteur           	 : TA Alexandre
 *************************************************************************/

//---------------------------------------------------------------- INCLUDES
#include <stack>
#include <typeinfo>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/IRBuilder.h>
//---------------------------------------------------------------- NAMESPACES
using namespace llvm;

class LVBlock;
class LVVariableDeclaration;
//---------------------------------------------------------------- GLOBAL VARIABLES
typedef std::vector<LVVariableDeclaration*> VariableList;
//---------------------------------------------------------------- DECLARATION

/* This class represents a block */
class CodeGenBlock {
public:
	// Represents the whole block
    BasicBlock *block;
	
	// Returned value by the function
    Value *returnValue;
	
	// List of local variables
    std::map<std::string, Value*> locals;
};

/* This class represents the general context of building llvm assembly code */
class CodeGenContext {
	// Represents the list of browsed blocks
    std::stack<CodeGenBlock *> blocks;
	
	// Represents the main function
    Function *mainFunction;

public:
	// Module
    Module *module;
	
	// Builder
	IRBuilder<> builder;
	
	// Constructor
    CodeGenContext() : builder(getGlobalContext()) { module = new Module("main", getGlobalContext()); }
	
	// Get module
	Module& getModule(){return *module;}
    
	// Generate assembly code
	void generateCode(LVBlock& root, LVBlock *blockStmtsMain, VariableList *listMain, char *file);
	
	// Run code
    GenericValue runCode();
	
	// Get list of local variables
    std::map<std::string, Value*>& locals() { return blocks.top()->locals; }
	
	// Get current block
    BasicBlock *currentBlock() { return blocks.top()->block; }
	
	// Add block
    void pushBlock(BasicBlock *block) { blocks.push(new CodeGenBlock()); blocks.top()->returnValue = NULL; blocks.top()->block = block; }
    
	// Delete last block
	void popBlock() { CodeGenBlock *top = blocks.top(); blocks.pop(); delete top; }
	
	// Set current value to last block
    void setCurrentReturnValue(Value *value) { blocks.top()->returnValue = value; }
	
	// Get current return value
    Value* getCurrentReturnValue() { return blocks.top()->returnValue; }
	
	// Get main function
	Function* getFunction(){return mainFunction;}

};
