/*************************************************************************
 Header node.h
 -------------------
 date                : december 2013
 auteur           	 : TA Alexandre
 *************************************************************************/

//---------------------------------------------------------------- INCLUDES
#include <iostream>
#include <vector>
#include <llvm/IR/Value.h>
//---------------------------------------------------------------- NAMESPACES
using namespace std;
//---------------------------------------------------------------- DECLARATIONS
class CodeGenContext;
class LVStatement;
class LVExpression;
class LVVariableDeclaration;
//---------------------------------------------------------------- GLOBAL VARIABLES
typedef enum {_TAB, _INT, _NONE} TypeGlobal;

typedef vector<LVStatement*> StatementList;
typedef vector<LVExpression*> ExpressionList;
typedef vector<LVVariableDeclaration*> VariableList;
//---------------------------------------------------------------- METHODS
/* This class is the superclass representing a node */
class Node {
public:
	virtual ~Node() {}
	virtual llvm::Value* codeGen(CodeGenContext& context) { return NULL; }
};

/* This class represents a expression */
class LVExpression : public Node {

};

/* This class represents a statement */
class LVStatement : public Node {
};

/* This class represents an integer */
class LVInteger : public LVExpression {
public:
	long long value;
	LVInteger(long long value) : value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents a double */
class LVDouble : public LVExpression {
public:
	double value;
	LVDouble(double value) : value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents an identifier */
class LVIdentifier : public LVExpression {
public:
	std::string name;
	LVIdentifier(const std::string& name) : name(name) { }
	LVIdentifier* getIdentifier();
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents a method call */
class LVMethodCall : public LVExpression {
public:
	const LVIdentifier& id;
	ExpressionList arguments;
	LVMethodCall(const LVIdentifier& id, ExpressionList& arguments) :
		id(id), arguments(arguments) { }
	LVMethodCall(const LVIdentifier& id) : id(id) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the binary operator */
class LVBinaryOperator : public LVExpression {
public:
	int op;
	LVExpression& lhs;
	LVExpression& rhs;
	LVBinaryOperator(LVExpression& lhs, int op, LVExpression& rhs) :
		lhs(lhs), rhs(rhs), op(op) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the assignment */
class LVAssignment : public LVExpression {
public:
	LVIdentifier& lhs;
	LVExpression& rhs;
	LVAssignment(LVIdentifier& lhs, LVExpression& rhs) : 
		lhs(lhs), rhs(rhs) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the block */
class LVBlock : public LVExpression {
public:
	StatementList statements;
	LVBlock() { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the if-then statement */
class LVIfStatement : public LVStatement {
	LVExpression *cond;
	LVBlock *then;
public:
	LVIfStatement(LVExpression *cond, LVBlock *then)
	: cond(cond), then(then) {}
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the if-then-else statement */
class LVIfElseStatement : public LVStatement {
	LVExpression *cond;
	LVBlock *then, *_else;
public:
	LVIfElseStatement(LVExpression *cond, LVBlock *then, LVBlock *_else)
	: cond(cond), then(then), _else(_else) {}
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the for loop statement */
class LVForStatement : public LVStatement {
	LVExpression *init, *cond, *end;
	LVBlock *body;
public:
	LVForStatement(LVExpression *init, LVExpression *cond, LVExpression *end, LVBlock *body)
	: init(init), cond(cond), end(end), body(body) {}
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the expression statement */
class LVExpressionStatement : public LVStatement {
public:
	LVExpression& expression;
	LVExpressionStatement(LVExpression& expression) :
		expression(expression) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the return statement */
class LVReturnStatement : public LVStatement {
public:
	LVExpression& expression;
	LVReturnStatement(LVExpression& expression) :
		expression(expression) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the declaration of a variable */
class LVVariableDeclaration : public LVStatement {
public:
	const LVIdentifier& type;
	LVIdentifier& id;
	LVExpression *assignmentExpr;
	LVVariableDeclaration(const LVIdentifier& type, LVIdentifier& id) :
		type(type), id(id) { }
	LVVariableDeclaration(const LVIdentifier& type, LVIdentifier& id, LVExpression *assignmentExpr) :
		type(type), id(id), assignmentExpr(assignmentExpr) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the declaration of a global variable */
class LVVariableGlobalDeclaration : public LVStatement {
public:
	const LVIdentifier& type;
	LVIdentifier& id;
	long long value;
	TypeGlobal typeGlobal;
	
	LVVariableGlobalDeclaration(const LVIdentifier& type, LVIdentifier& id) :
	type(type), id(id) { }
	LVVariableGlobalDeclaration(const LVIdentifier& type, LVIdentifier& id, TypeGlobal typeGlobal, long long value) :
	type(type), id(id), typeGlobal(typeGlobal), value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/* This class represents the declaration of a function */
class LVFunctionDeclaration : public LVStatement {
public:
	const LVIdentifier& type;
	const LVIdentifier& id;
	VariableList arguments;
	LVBlock& block;
	LVFunctionDeclaration(const LVIdentifier& type, const LVIdentifier& id, 
			const VariableList& arguments, LVBlock& block) :
		type(type), id(id), arguments(arguments), block(block) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};
