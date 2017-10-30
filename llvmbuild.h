/*************************************************************************
 Header LLVMBuild.h
 -------------------
 date                : december 2013
 auteur           	 : TA Alexandre
 *************************************************************************/

#ifndef LLVMBUILD_H
#define LLVMBUILD_H
//---------------------------------------------------------------- INCLUDES
#include <stdio.h>
#include <list>
#include <map>
#include <set>
//----------------------------------------------------------------
#include "treenode.h"
//---------------------------------------------------------------- NAMESPACES
using namespace std;
//---------------------------------------------------------------- DECLARATION
/* This class consists in building the assembly code from the parse tree */
class LLVMBuild {
	private:
	
	// Get list of variables
	static VariableList* GetVariableList(struct NodeT *node);
	
	// Browse DEFS node
	static LVBlock* GetDefs(struct NodeT *node);
	
	// Browse STMTS node
	static LVBlock* GetStmts(struct NodeT *node);
	
	// Browse STMTBLOCK node
	static LVBlock* GetStmtBlock(struct NodeT *node);
	
	// Browse EXP node
	static LVExpression* GetExp(struct NodeT *node);
	
	// Browse STMT node
	static LVBlock * GetStmt(struct NodeT *stmt);
	
	// Browse ARGS node
	static ExpressionList* GetArgs(struct NodeT *node);
	
	// Browse EXTVARS node
	static LVBlock* GetExtvars(struct NodeT *extvars, LVIdentifier *type);
	
	public:
	// Constructor
	LLVMBuild(){}
	
	// Main function
	static void BuildLLVM(struct NodeT * node, char *file);

	
};
#endif