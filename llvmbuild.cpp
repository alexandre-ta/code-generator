/*************************************************************************
 Class LLVMBuild.cpp
 -------------------
 date                : december 2013
 auteur           	 : TA Alexandre
 *************************************************************************/

//---------------------------------------------------------------- INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring> //For C++
#include <string.h> //For C
#include <vector>
#include <list>
#include <set>
//----------------------------------------------------------------
#include "treenode.h"
#include "semantictree.h"
#include "llvmbuild.h"
#include "codegen.h"
//---------------------------------------------------------------- NAMESPACES
using namespace std;
//---------------------------------------------------------------- METHODS
void createCoreFunctions(CodeGenContext& context);

/* Main function for building llvm assembly */
void LLVMBuild::BuildLLVM(struct NodeT *node, char *file)
{
	// First things first, we need to check if the tree is semantically correct
	Semantictree::CheckVarFuncRule(node);
	Semantictree::CheckSemanticRules(node);
	if(Semantictree::GetContainedError())
	{
		return;
	}
	
	if(node->type == _PROGRAM)
	{
		node = node->Child[0];
	}
	
	// Split the tree with main function
	struct NodeT **mainNode;
	
	struct NodeT **extdefs = &node;
	
	while(*extdefs != NULL)
	{
		struct NodeT **extdef = &((*extdefs)->Child[0]);
		struct NodeT **extdefSibling = &((*extdefs)->Child[1]);
		if((*extdef)->Child[0] != NULL)
		{
			struct NodeT **func = &((*extdef)->Child[1]);
			if((*func)->type == _FUNC)
			{
				struct NodeT **idFunc = &((*func)->Child[0]);
				if(strcmp((*idFunc)->value, "main") == 0)
				{
					*mainNode = *extdef;
					break;
				}
			}
			extdefs = &(*extdefs)->Child[1];
		} else {
			extdefs = NULL;
		}
	}
	LVBlock *prog = new LVBlock();
	//Process
	while(node != NULL)
	{
		if(node->Child[0] != NULL)
		{
			if(node->Child[0]->type == _EXTDEF)
			{
				struct NodeT *extdef = node->Child[0];
				if(extdef->Child[0]->type == _SPEC && extdef->Child[1]->type == _FUNC && extdef->Child[2]->type == _STMTBLOCK)
				{
					struct NodeT *typeNode = extdef->Child[0]->Child[0];
					struct NodeT *idNode = extdef->Child[1]->Child[0];
					struct NodeT *parasNode = extdef->Child[1]->Child[2];
					struct NodeT *stmtblockNode = extdef->Child[2];
					
					if(strcmp(idNode->value, "main") != 0){
						LVFunctionDeclaration *funcDecl;
						LVIdentifier *type;
						LVIdentifier *id;
						VariableList *list;
						LVBlock *blockStmts;
						
						if(typeNode->type == _TYPE)
						{
							type = new LVIdentifier("int");
						}
						if(idNode->type == _ID)
						{
							string myId = idNode->value;
							id = new LVIdentifier(myId);
						}
						if(parasNode->type == _PARAS)
						{
							list = GetVariableList(parasNode);
						}
						if(stmtblockNode->type == _STMTBLOCK)
						{
							blockStmts = GetStmtBlock(stmtblockNode);
						}
						funcDecl = new LVFunctionDeclaration(*type, *id, *list, *blockStmts);
						prog->statements.push_back(funcDecl);
					} else {
						LVBlock *blockStmts = GetStmtBlock(stmtblockNode);
						
						std::vector<LVStatement*>::iterator it;
						for(it = blockStmts->statements.begin(); it != blockStmts->statements.end(); it++)
						{
							prog->statements.push_back(*it);
						}
					}
				} else if(extdef->Child[0]->type == _SPEC && extdef->Child[1]->type == _EXTVARS && extdef->Child[2]->type == _SEMI)
				{
					struct NodeT *specNode = extdef->Child[0];
					struct NodeT *extvarsNode = extdef->Child[1];
					struct NodeT *semiNode = extdef->Child[2];
					
					LVIdentifier *type;
					if(specNode->Child[0]->type == _TYPE)
					{
						type = new LVIdentifier("int");
					} else if(specNode->type == _STSPEC)
					{
						// TODO
					}
					LVBlock *blc = GetExtvars(extvarsNode, type);
					std::vector<LVStatement*>::iterator it;
					for(it = blc->statements.begin(); it != blc->statements.end(); it++)
					{
						prog->statements.push_back(*it);
					}
				}
			}
			node = node->Child[1];
		} else {
			node = NULL;
		}
	}
	// Process Block Main
	LVBlock *maiLVBlock = new LVBlock();
	LVIdentifier *typeMain = new LVIdentifier("int");
	LVIdentifier *idMain = new LVIdentifier("main");
	VariableList *listMain = GetVariableList((*mainNode)->Child[1]->Child[2]);
	struct NodeT *stmtblock = (*mainNode)->Child[2];
	LVBlock *blockStmtsMain = GetStmtBlock(stmtblock);
	
	// Initialise target LLVM
	InitializeNativeTarget();
	CodeGenContext context;
	createCoreFunctions(context);
	context.generateCode(*prog, blockStmtsMain, listMain, file);
	// Run code
	context.runCode();
}

/* Browse EXTVARS node */
LVBlock* LLVMBuild::GetExtvars(struct NodeT *extvars, LVIdentifier *type)
{
	LVBlock *list = new LVBlock();
	if(extvars != NULL)
	{
		while(extvars != NULL)
		{
			if(extvars->Child[0] != NULL && extvars->Child[0]->type == _DEC) // True
			{
				struct NodeT *dec = extvars->Child[0];
				if(dec->Child[0] != NULL && dec->Child[0]->type == _VAR) // True
				{
					LVExpression *myExp;
					LVIdentifier *id;
					long long value = 0;
					LVVariableGlobalDeclaration *varGlo;
					TypeGlobal decGlob = _NONE;
					if(dec->Child[1] != NULL && dec->Child[2] != NULL && dec->Child[1]->type == _ASSIGN && dec->Child[2]->type == _EXP)
					{
						// By default, exp node is a number
						struct NodeT *varExp = dec->Child[2];
						value = atoi(varExp->Child[0]->value);
						decGlob = _INT;
					}
					struct NodeT *var = dec->Child[0];
					if(var->Child[0]->type == _ID)
					{
						struct NodeT *idNode = var->Child[0];
						id = new LVIdentifier(idNode->value);
					} else if(var->Child[0]->type == _VAR && var->Child[1]->type == _LB && (var->Child[2]->type == _DECIMAL || var->Child[2]->type == _OCTAL || var->Child[2]->type == _HEXADECIMAL) && var->Child[3]->type == _RB)
					{
						struct NodeT *varC = var->Child[0];
						id = new LVIdentifier(varC->value);
						value = atoi(var->Child[2]->value);
						decGlob = _TAB;
					}
					list->statements.push_back(new LVVariableGlobalDeclaration(*type, *id, decGlob, value));
				}
				extvars = extvars->Child[2];
			} else {
				extvars = NULL;
			}
		}
	}
	return list;
}

/* Get list of variables for a function */
VariableList* LLVMBuild::GetVariableList(struct NodeT *node)
{
	VariableList *list = new VariableList();
	if(node != NULL)
	{
		struct NodeT *paras = node;
		while(paras != NULL)
		{
			if(paras->Child[0] != NULL){
				if(paras->Child[0]->type == _PARA)
				{
					struct NodeT *tmp = paras->Child[0];

					LVIdentifier *type = new LVIdentifier("int");
			
					string myId = tmp->Child[1]->Child[0]->value;
				
					LVIdentifier *id = new LVIdentifier(myId);
					LVVariableDeclaration *dec = new LVVariableDeclaration(*type, *id);
					list->push_back(dec);
				}
				paras = paras->Child[2];
			} else {
				paras = NULL;
			}
		}
	}
	return list;
}

/* Browse DEFS node */
LVBlock* LLVMBuild::GetDefs(struct NodeT *node)
{
	LVBlock *list = new LVBlock();
	LVVariableDeclaration *vardec;
	if(node != NULL)
	{
		struct NodeT *defs = node;
		while(defs != NULL)
		{
			if(defs->Child[0] != NULL)
			{
				if(defs->Child[0]->type == _DEF)
				{
					struct NodeT *def = defs->Child[0];
					LVIdentifier *type = new LVIdentifier("int");
					
					struct NodeT *decs = def->Child[1];
					// foreach def
					while(decs != NULL)
					{
						if(decs->Child[0] != NULL && decs->Child[0]->type == _DEC)
						{
							struct NodeT *dec = decs->Child[0];
							// Get VAR
							struct NodeT *var = dec->Child[0];
							
							string varValue = var->Child[0]->value;
							LVIdentifier *id = new LVIdentifier(varValue);
							
							if(dec->Child[2] != NULL && dec->Child[2]->type == _INIT)
							{
								struct NodeT *init = dec->Child[2];
								struct NodeT *exp = init->Child[0];
								LVExpression *myExp = GetExp(exp);
								vardec = new LVVariableDeclaration(*type, *id, myExp);
							} else
							{
								vardec = new LVVariableDeclaration(*type, *id);
							}
							list->statements.push_back(vardec);
						 	decs = decs->Child[2];
						} else {
							decs = NULL;
						}
					}
				}
				defs = defs->Child[1];
			} else {
				defs = NULL;
			}
		}
	}
	return list;
}

/* Browse STMTS node */
LVBlock* LLVMBuild::GetStmts(struct NodeT *node)
{
	LVBlock *list = new LVBlock();
	if(node != NULL)
	{
		struct NodeT *stmts = node;
		while(stmts != NULL)
		{
			if(stmts->Child[0] != NULL && stmts->Child[0]->type == _STMT)
			{
				struct NodeT *stmt = stmts->Child[0];

				LVBlock *blc = GetStmt(stmt);
				std::vector<LVStatement*>::iterator it;
				for(it = blc->statements.begin(); it != blc->statements.end(); it++)
				{
					list->statements.push_back(*it);
				}
				stmts = stmts->Child[1];
			} else {
				stmts = NULL;
			}
		}
	}
	return list;
}

/* Browse STMT node */
LVBlock * LLVMBuild::GetStmt(struct NodeT *stmt)
{
	LVBlock * res;
	if(stmt->Child[0] != NULL)
	{
		if(stmt->Child[0]->type == _STMTBLOCK)
		{
			res = GetStmtBlock(stmt->Child[0]);
		}
	}
	if(stmt->Child[0] != NULL && stmt->Child[1] != NULL)
	{
		if(stmt->Child[0]->type == _EXP && stmt->Child[1]->type == _SEMI)
		{
			res = new LVBlock();
			LVExpression *tmp = GetExp(stmt->Child[0]);
			LVExpressionStatement *nst = new LVExpressionStatement(*tmp);
			res->statements.push_back(nst);
		}
		if(stmt->Child[0]->type == _CONTINUE && stmt->Child[1]->type == _SEMI)
		{
			// TODO
		}
		if(stmt->Child[0]->type == _BREAK && stmt->Child[1]->type == _SEMI)
		{
			// TODO
		}
	}
	if(stmt->Child[0] != NULL && stmt->Child[1] != NULL && stmt->Child[2] != NULL)
	{
		if(stmt->Child[0]->type == _RETURN && stmt->Child[1]->type == _EXP && stmt->Child[2]->type == _SEMI)
		{
			res = new LVBlock();
			LVExpression *tmp = GetExp(stmt->Child[1]);
			LVReturnStatement *nst = new LVReturnStatement(*tmp);
			res->statements.push_back(nst);
		}
	}
	if(stmt->Child[0] != NULL && stmt->Child[1] != NULL && stmt->Child[2] != NULL && stmt->Child[3] != NULL && stmt->Child[4] != NULL && stmt->Child[5] != NULL)
	{
		if(stmt->Child[0]->type == _IF && stmt->Child[1]->type == _LP && stmt->Child[2]->type == _EXP && stmt->Child[3]->type == _RP && stmt->Child[4]->type == _STMT && stmt->Child[5]->type == _ESTMT)
		{
			res = new LVBlock();
			LVExpression *cond = GetExp(stmt->Child[2]);
			//
			LVBlock *listElse;
			//
			struct NodeT *stmtThen = stmt->Child[4];
	
			LVBlock *listThen = GetStmt(stmtThen);

			if(stmt->Child[5]->Child[0] != NULL && stmt->Child[5]->Child[1]->type == _STMT)
			{
				struct NodeT *stmtElse = stmt->Child[5]->Child[1];
				listElse = GetStmt(stmtElse);
				LVIfElseStatement *nif = new LVIfElseStatement(cond, listThen, listElse);
				res->statements.push_back(nif);
			} else {
				LVIfStatement *nif = new LVIfStatement(cond, listThen);
				res->statements.push_back(nif);
			}
		}
	}
	if(stmt->Child[0] != NULL && stmt->Child[1] != NULL && stmt->Child[2] != NULL && stmt->Child[3] != NULL && stmt->Child[4] != NULL && stmt->Child[5] != NULL && stmt->Child[6] != NULL && stmt->Child[7] != NULL && stmt->Child[8] != NULL)
	{
		if(stmt->Child[0]->type == _FOR && stmt->Child[1]->type == _LP && stmt->Child[2]->type == _EXP && stmt->Child[3]->type == _SEMI && stmt->Child[4]->type == _EXP && stmt->Child[5]->type == _SEMI && stmt->Child[6]->type == _EXP && stmt->Child[7]->type == _RP && stmt->Child[8]->type == _STMT)
		{
			res = new LVBlock();
			LVExpression *init = GetExp(stmt->Child[2]);
			LVExpression *cond = GetExp(stmt->Child[4]);
			LVExpression *end = GetExp(stmt->Child[6]);
			//
			struct NodeT *stmtNode = stmt->Child[8];
			
			LVBlock *listNode = GetStmt(stmtNode);
			
			LVForStatement *nif = new LVForStatement(init, cond, end, listNode);
			res->statements.push_back(nif);
		}
	}
	return res;
}

/* Browse STMTBLOCK node */
LVBlock* LLVMBuild::GetStmtBlock(struct NodeT *node)
{
	std::vector<LVStatement*>::iterator it;
	LVBlock* left = GetDefs(node->Child[1]);
	LVBlock* right = GetStmts(node->Child[2]);
	for(it = right->statements.begin(); it != right->statements.end(); it++)
	{
		left->statements.push_back(*it);
	}
	return left;
}

/* Browse EXP node */
LVExpression* LLVMBuild::GetExp(struct NodeT *node)
{
	LVExpression *exp;
	// INT
	if(node->Child[0] != NULL)
	{
		if(node->Child[0]->type == _OCTAL || node->Child[0]->type == _HEXADECIMAL || node->Child[0]->type == _DECIMAL)
		{
			exp = new LVInteger(atoi(node->Child[0]->value));
		}
	}
	// UNARYOP EXP or ID ARRS
	if(node->Child[0] != NULL && node->Child[1] != NULL)
	{
		if(node->Child[1]->type == _EXP)
		{
			// TODO
		}
		if(node->Child[0]->type == _ID && node->Child[1]->type == _ARRS)
		{
			LVIdentifier *id = new LVIdentifier(node->Child[0]->value);
			exp = new LVIdentifier(*id);
		}
	}
	// EXP BIN EXP or LP EXP RP or EXP DOT ID
	if(node->Child[0] != NULL && node->Child[1] != NULL && node->Child[2] != NULL)
	{
		if(node->Child[0]->type == _EXP && node->Child[2]->type == _EXP)
		{
			LVExpression *left = GetExp(node->Child[0]);
			LVExpression *right = GetExp(node->Child[2]);
			exp =  new LVBinaryOperator(*left, node->Child[1]->type, *right);
		}
		if(node->Child[0]->type == _LP && node->Child[1]->type == _EXP && node->Child[2]->type == _RP)
		{
			// TODO
		}
		if(node->Child[0]->type == _EXP && node->Child[1]->type == _DOT && node->Child[2]->type == _ID)
		{
			// TODO
		}
	}
	// ID LP ARGS RP
	if(node->Child[0] != NULL && node->Child[1] != NULL && node->Child[2] != NULL && node->Child[3] != NULL)
	{
		if(node->Child[0]->type == _ID && node->Child[1]->type == _LP && node->Child[2]->type == _ARGS && node->Child[3]->type == _RP)
		{
			LVIdentifier *id = new LVIdentifier(node->Child[0]->value);
			ExpressionList *args = GetArgs(node->Child[2]);
			exp = new LVMethodCall(*id, *args);
		}
	}
	return exp;
}

/* Get list of arguments for method call */
ExpressionList* LLVMBuild::GetArgs(struct NodeT *node)
{
	ExpressionList *list;
	if(node != NULL)
	{
		list = new ExpressionList();
		struct NodeT *args = node;
		while(args != NULL)
		{
			if(args->Child[0] != NULL && args->Child[0]->Child[0] != NULL)
			{
				LVExpression *exp = GetExp(args->Child[0]);
				list->push_back(exp);
				args = args->Child[2];
			} else {
				args = NULL;
			}
		}
	}
	return list;
}
