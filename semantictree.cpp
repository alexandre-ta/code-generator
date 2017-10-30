/*************************************************************************
 Class SemanticTree.cpp
 -------------------
 date                : december 2013
 auteur           	 : TA Alexandre
 *************************************************************************/

//---------------------------------------------------------------- INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "codegen.h"
#include <cstring> //For C++
#include <string.h> //For C
#include <vector>
#include <list>
#include <set>
//----------------------------------------------------------------
#include "semantictree.h"
//---------------------------------------------------------------- NAMESPACES
using namespace std;
//---------------------------------------------------------------- GLOBAL VARIABLES
bool containedError;
//---------------------------------------------------------------- METHODS

/* Variables and functions should be declared before usage and only once in a block */
void Semantictree::CheckVarFuncRule(struct NodeT * node)
{
	map<string, list<VariableType> > functionsName;
	map<string, set<VariableType> > globalVariables;
	struct NodeT *extdefs = node->Child[0];
	while(extdefs != NULL)
	{
		if(extdefs->Child[0] != NULL) // EXTDEFS -> E
		{
			struct NodeT *extdef = extdefs->Child[0];
			// EXTDEF -> SPEC FUNC STMTBLOCK
			if(extdef->Child[0]->type == _SPEC && extdef->Child[1]->type == _FUNC && extdef->Child[2]->type == _STMTBLOCK)
			{
				struct NodeT *func = extdef->Child[1];
				string funcName = func->Child[0]->value;
				
				if(functionsName.find(funcName) == functionsName.end())
				{
					// Function name doesn't exist : add into the set
					// 1 : Get all parameters type
					struct NodeT *paras = func->Child[2];
					list<VariableType> variableTypeFunc;
					while(paras != NULL)
					{
						if(paras->Child[0] != NULL){
							struct NodeT *para = paras->Child[0];
							struct NodeT *spec = para->Child[0];
							struct NodeT *var = para->Child[1];
							
							VariableType type;
							// Get the type
							switch(spec->Child[0]->type)
							{
								case _TYPE:
									type = _TYPE_INT;
									break;
								case _STSPEC:
									type = _TYPE_STRUCT;
									break;
								default:
									break;
							}
							switch(var->Child[0]->type)
							{
								case _VAR:
									type = _TYPE_ARRAYS;
									break;
								default:
									break;
							}
							variableTypeFunc.push_back(type);
							// Next
							paras = paras->Child[2];
						} else {
							paras = NULL;
						}
					}
					// 2 : Add function and list parameters type into the set
					functionsName[funcName] = variableTypeFunc;
				} else {
					containedError = true;
					cerr << "Error this function already exists" << endl;
				}
				CheckVarFuncRuleFunction(extdef, functionsName, globalVariables);
			} else { // EXTDEF -> SPEC EXTVARS SEMI : global variable
				struct NodeT *spec = extdef->Child[0];
				struct NodeT *extvars = extdef->Child[1];
				
				if(extvars != NULL)
				{
					while(extvars != NULL)
					{
						if(extvars->Child[0] != NULL && extvars->Child[0]->type == _DEC)
						{
							struct NodeT *dec = extvars->Child[0];
							struct NodeT *var = dec->Child[0];

							VariableType type;
							// Get the type
							switch(spec->Child[0]->type)
							{
								case _TYPE:
									type = _TYPE_INT;
									break;
								case _STSPEC:
									type = _TYPE_STRUCT;
									break;
								default:
									break;
							}
							
							string varName;
							switch(var->Child[0]->type)
							{
								case _ID:
									varName = var->Child[0]->value;
									break;
								case _VAR:
									varName = var->Child[0]->Child[0]->value; // 1 dimensionnal array
									type = _TYPE_ARRAYS;
									break;
								default:
									break;
							}
							
							// Check if global parameter is single
							if(globalVariables.find(varName) == globalVariables.end())
							{
								globalVariables[varName].insert(type);
							} else {
								// exist but check the type
								if(globalVariables[varName].find(type) == globalVariables[varName].end())
								{
									globalVariables[varName].insert(type);
								} else {
									containedError = true;
								}
							}
							extvars = extvars->Child[2];
						} else {
							extvars = NULL;
						}
					}
				}
			}
			extdefs = extdefs->Child[1];
		} else {
			extdefs = NULL;
		}
	}
}

/* Check function parameters */
void Semantictree::CheckVarFuncRuleFunction(struct NodeT * nodeExtdef, map<string, list<VariableType> > &previousFunctions, map<string, set<VariableType> > &globalVariables)
{
	// The value is the key
	map<string, set<VariableType> > variables;
	variables.insert(globalVariables.begin(), globalVariables.end());
	if(nodeExtdef != NULL)
	{
		// Parameters
		struct NodeT *func = nodeExtdef->Child[1];
		struct NodeT *paras = func->Child[2];
		while(paras != NULL)
		{
			if(paras->Child[0] != NULL){
				struct NodeT *para = paras->Child[0];
				// PARA -> SPEC VAR
				struct NodeT *spec = para->Child[0];
				struct NodeT *var = para->Child[1];
				
				VariableType type;
				// Get the type
				switch(spec->Child[0]->type)
				{
					case _TYPE:
						type = _TYPE_INT;
						break;
					case _STSPEC:
						type = _TYPE_STRUCT;
						break;
					default:
						break;
				}

				string varName;
				switch(var->Child[0]->type)
				{
					case _ID:
						varName = var->Child[0]->value;
						break;
					case _VAR:
						varName = var->Child[0]->Child[0]->value; // 1 dimensionnal array
						type = _TYPE_ARRAYS;
						break;
					default:
						break;
				}
				
				// Check if parameters are singles
				if(variables.find(varName) == variables.end())
				{
					variables[varName].insert(type);
				} else {
					if(variables[varName].find(type) == variables[varName].end())
					{
						variables[varName].insert(type);
					} else {
						containedError = true;
					}
				}
				// Next
				paras = paras->Child[2];
			} else {
				paras = NULL;
			}
		}
		// Variables into function
		struct NodeT *stmtblock = nodeExtdef->Child[2];
		CheckVarFuncRuleStmtBlock(stmtblock, variables, previousFunctions);
	}
}

/* Check content of a function : definitions and statements */
void Semantictree::CheckVarFuncRuleStmtBlock(struct NodeT * stmtblock, map<string, set<VariableType> > &globalVariables, map<string, list<VariableType> > &previousFunctions)
{
	map<string, set<VariableType> > tmp;
	tmp.insert(globalVariables.begin(), globalVariables.end());
	
	struct NodeT *defs = stmtblock->Child[1];
	struct NodeT *stmts = stmtblock->Child[2];
	
	CheckVarFuncRuleDefs(defs, tmp, previousFunctions);
	CheckVarFuncRuleStmts(stmts, tmp, previousFunctions);
}

/* Check definitions */
void Semantictree::CheckVarFuncRuleDefs(struct NodeT * defs, map<string, set<VariableType> > &previousVariable, map<string, list<VariableType> > &previousFunctions)
{
	// Definition
	while(defs != NULL)
	{
		if(defs->Child[0] != NULL)
		{
			struct NodeT *def = defs->Child[0];
			//
			struct NodeT *spec = def->Child[0];
			struct NodeT *decs = def->Child[1];
			
			VariableType type;
			// Get the type
			switch(spec->Child[0]->type)
			{
				case _TYPE:
					type = _TYPE_INT;
					break;
				case _STSPEC:
					type = _TYPE_STRUCT;
					break;
				default:
					break;
			}
	
			while(decs != NULL)
			{
				if(decs->Child[0] != NULL)
				{
					struct NodeT *dec = decs->Child[0];
					struct NodeT *var = dec->Child[0];
					
					string varName;
					switch(var->Child[0]->type)
					{
						case _ID:
							varName = var->Child[0]->value;
							break;
						case _VAR:
							varName = var->Child[0]->Child[0]->value; // 1 dimensionnal array
							type = _TYPE_ARRAYS;
							break;
						default:
							break;
					}
					
					// Check if parameters are singles
					if(previousVariable.find(varName) == previousVariable.end())
					{
						previousVariable[varName].insert(type);
					} else {
						if(previousVariable[varName].find(type) == previousVariable[varName].end())
						{
							previousVariable[varName].insert(type);
						} else {
							containedError = true;
						}
					}
					
					// DEC -> VAR ASSIGNOP INIT
					if(dec->Child[2] != NULL && dec->Child[2]->type == _INIT)
					{
						struct NodeT *init = dec->Child[2];
						
						// INIT -> EXP
						if(init->Child[0]->type == _EXP)
						{
							struct NodeT *exp = init->Child[0];
							CheckVarFuncRuleFunctionExp(exp, previousVariable, previousFunctions);
						} else {
							// INIT -> LC ARGS RC
						}
					}
					decs = decs->Child[2];
				} else {
					decs = NULL;
				}
			}
			defs = defs->Child[1];
		} else {
			defs = NULL;
		}
	}
}

/* Check expression contained into definitions */
void Semantictree::CheckVarFuncRuleFunctionExp(struct NodeT * node, map<string, set<VariableType> > &previousVariable,  map<string, list<VariableType> > &previousFunctions)
{
	if(node->Child[0] != NULL && node->Child[1] != NULL)
	{
		// UNARYOP EXP
		if(node->Child[1]->type == _EXP)
		{
			CheckVarFuncRuleFunctionExp(node->Child[1], previousVariable, previousFunctions);
		}
		
		// ID ARRS
		if(node->Child[0]->type == _ID && node->Child[1]->type == _ARRS)
		{
			string var = node->Child[0]->value;
			struct NodeT *arrs = node->Child[1];
			
			if(arrs->Child[0] != NULL)
			{
				// arrays
				// Check if parameters are singles
				if(previousVariable[var].find(_TYPE_ARRAYS) == previousVariable[var].end())
				{
					containedError = true;
				}
			} else {
				// int
				if(previousVariable[var].find(_TYPE_INT) == previousVariable[var].end())
				{
					containedError = true;
				}
			}

			// Check inside ARRS
			if(arrs->Child[0] != NULL && arrs->Child[0]->type == _LB && arrs->Child[1] != NULL && arrs->Child[1]->type == _EXP && arrs->Child[2] != NULL && arrs->Child[2]->type == _RB)
			{
				CheckVarFuncRuleFunctionExp(arrs->Child[1], previousVariable, previousFunctions);
			}
		}
	}
	if(node->Child[0] != NULL && node->Child[1] != NULL && node->Child[2] != NULL)
	{
		if(node->Child[0]->type == _EXP && node->Child[2]->type == _EXP)
		{
			CheckVarFuncRuleFunctionExp(node->Child[0], previousVariable, previousFunctions);
			CheckVarFuncRuleFunctionExp(node->Child[2], previousVariable, previousFunctions);
		}
		if(node->Child[0]->type == _LP && node->Child[1]->type == _EXP && node->Child[2]->type == _RP)
		{
			CheckVarFuncRuleFunctionExp(node->Child[1], previousVariable, previousFunctions);
		}
		if(node->Child[0]->type == _EXP && node->Child[1]->type == _DOT && node->Child[2]->type == _ID)
		{
			// Check struct variable
			struct NodeT *exp = node->Child[0];
			if(exp->Child[0] != NULL && exp->Child[0]->type == _ID && exp->Child[1]->type == _ARRS)
			{
				string var = exp->Child[0]->value;
				if(previousVariable[var].find(_TYPE_STRUCT) == previousVariable[var].end())
				{
					containedError = true;
				}
			}
		}
	}
	if(node->Child[0] != NULL && node->Child[1] != NULL && node->Child[2] != NULL && node->Child[3] != NULL)
	{
		if(node->Child[0]->type == _ID && node->Child[1]->type == _LP && node->Child[2]->type == _ARGS && node->Child[3]->type == _RP)
		{
			CheckParamFunction(node, previousVariable, previousFunctions);
		}
	}
}

/* Check function parameters */
void Semantictree::CheckParamFunction(struct NodeT * expFunction, map<string, set<VariableType> > &previousVariable,  map<string, list<VariableType> > &previousFunctions)
{
	if(expFunction->Child[0] != NULL)
	{
		string functionName = expFunction->Child[0]->value;
		struct NodeT *args = expFunction->Child[2];
		list<VariableType> vars;
		
		if(previousFunctions.find(functionName) == previousFunctions.end())
		{
			containedError = true;
		} else {
			int paramCount = 0;
			// Get list of type parameter
			list<VariableType> list = previousFunctions[functionName];
			std::list<VariableType>::iterator it = list.begin();

			while(args != NULL)
			{
				struct NodeT *exp = args->Child[0];
				CheckVarFuncRuleFunctionExp(exp, previousVariable, previousFunctions);
				paramCount++;
				// Next parameter
				args = args->Child[2];
			}
			if(paramCount != list.size())
			{
				containedError = true;
			}
		}
	}

}

/* Check all statements */
void Semantictree::CheckVarFuncRuleStmts(struct NodeT * stmts, map<string, set<VariableType> > &previousVariable,  map<string, list<VariableType> > &previousFunctions)
{
	while(stmts->Child[0] != NULL)
	{
		struct NodeT *stmt = stmts->Child[0];
		CheckVarFuncRuleStmt(stmt, previousVariable, previousFunctions);
		stmts = stmts->Child[1];
	}
}

/* Check one statement */
void Semantictree::CheckVarFuncRuleStmt(struct NodeT * stmt, map<string, set<VariableType> > &previousVariable,  map<string, list<VariableType> > &previousFunctions)
{
	if(stmt->Child[0]->type == _STMTBLOCK)
	{
		CheckVarFuncRuleStmtBlock(stmt->Child[0], previousVariable, previousFunctions);
	}
	if(stmt->Child[0]->type == _EXP && stmt->Child[1]->type == _SEMI)
	{
		CheckVarFuncRuleFunctionExp(stmt->Child[0], previousVariable, previousFunctions);
	}
	if(stmt->Child[0]->type == _RETURN && stmt->Child[1]->type == _EXP && stmt->Child[2]->type == _SEMI)
	{
		CheckVarFuncRuleFunctionExp(stmt->Child[1],previousVariable, previousFunctions);
	}
	if(stmt->Child[0]->type == _IF && stmt->Child[1]->type == _LP && stmt->Child[2]->type == _EXP && stmt->Child[3]->type == _RP && stmt->Child[4]->type == _STMT && stmt->Child[5]->type == _ESTMT)
	{
		CheckVarFuncRuleFunctionExp(stmt->Child[2], previousVariable, previousFunctions);

		struct NodeT *stmtThen = stmt->Child[4];
		
		CheckVarFuncRuleStmt(stmtThen, previousVariable, previousFunctions);
		
		if(stmt->Child[5]->Child[0] != NULL && stmt->Child[5]->Child[1]->type == _STMT)
		{
			struct NodeT *stmtElse = stmt->Child[5]->Child[1];
			CheckVarFuncRuleStmt(stmtElse, previousVariable, previousFunctions);
		}
	}
	if(stmt->Child[0]->type == _FOR && stmt->Child[1]->type == _LP && stmt->Child[2]->type == _EXP && stmt->Child[3]->type == _SEMI && stmt->Child[4]->type == _EXP && stmt->Child[5]->type == _SEMI && stmt->Child[6]->type == _EXP && stmt->Child[7]->type == _RP && stmt->Child[8]->type == _STMT)
	{
		struct NodeT * exp1 = stmt->Child[2];
		struct NodeT * exp2 = stmt->Child[4];
		struct NodeT * exp3 = stmt->Child[6];
		struct NodeT * stmtB = stmt->Child[8];
		
		CheckVarFuncRuleFunctionExp(exp1,previousVariable, previousFunctions);
		CheckVarFuncRuleFunctionExp(exp2,previousVariable, previousFunctions);
		CheckVarFuncRuleFunctionExp(exp3,previousVariable, previousFunctions);

		CheckVarFuncRuleStmt(stmtB, previousVariable, previousFunctions);
	}
}

/* Check if the identifier is not a reserved word */
void Semantictree::CheckSemanticRules(struct NodeT *node)
{
	if(node != NULL)
	{
		TypeNode typeCurrentNode = node->type;
		struct NodeT *idNode;
		switch(typeCurrentNode)
		{
			case _STSPEC:
				idNode = node->Child[1];
				if(idNode->type == _ID)
				{
					string idValue = idNode->value;
					if(ReservedWords.find(idValue) != ReservedWords.end())
					{
						containedError = true;
					}
				}
				break;
			case _OPTTAG:
			case _VAR:
			case _FUNC:
				idNode = node->Child[0];
				if(idNode->type == _ID)
				{
					string idValue = idNode->value;
					if(ReservedWords.find(idValue) != ReservedWords.end())
					{
						containedError = true;
					}
				}
				break;
			case _EXP:
				idNode = node->Child[0];
				if(idNode != NULL){
					if(idNode->type == _ID)
					{
						string idValue = idNode->value;
						if(ReservedWords.find(idValue) != ReservedWords.end())
						{
							containedError = true;
						}
					} else {
						idNode = node->Child[2];
						if(idNode != NULL && idNode->type == _ID)
						{
							string idValue = idNode->value;
							if(ReservedWords.find(idValue) != ReservedWords.end())
							{
								containedError = true;
							}
						}
					}
				}
				break;
			case _CONTINUE:
			case _BREAK:
			{
				CheckForContSemi(node);
			}
				break;
			case _STMT:
			{
				switch(node->Child[0]->type)
				{
					case _IF:
						CheckExpCond(node->Child[2]);
						break;
					case _FOR:
					{
						if(node->Child[4]->Child[0] != NULL)
						{
							CheckExpCond(node->Child[4]);
						}
					}
						break;
					default:
						break;
				}
			}
			default:
				break;
		}
		int i;
		for(i = 0; i < NB_CHILD; ++i)
		{
			if(node->Child[i] != NULL)
			{
				CheckSemanticRules(node->Child[i]);
			} else {
				break;
			}
		}
	}
}

/* Check continue node into for loop statement */
void Semantictree::CheckForContSemi(struct NodeT *node)
{
	bool isfound, isFinished = false;
	// go back stmts node
	struct NodeT *parent = node->Parent;
	
	while(!isFinished)
	{
		if(parent->type == _STMT)
		{
			if(parent->Child[0]->type == _FOR)
			{
				// found
				isfound = true;
				isFinished = true;
			}
		}
		if(parent->type == _EXTDEF)
		{
			containedError = true;
			// Not found
			isfound = false;
			isFinished = true;
		}
		parent = parent->Parent;
	}
}

/* Check condition for for-loop statement and if-then-else statement */
void Semantictree::CheckExpCond(struct NodeT *node)
{
	if(node->Child[0] != NULL)
	{
		// UNARYOP EXP
		if(node->Child[1] != NULL)
		{
			if(node->Child[0]->type == _UNARYNOT && node->Child[1]->type == _EXP)
			{
				CheckExpCond(node->Child[1]);
			}
		}
		if(node->Child[1] != NULL && node->Child[2] != NULL)
		{
			if(node->Child[0]->type == _EXP && node->Child[2]->type == _EXP)
			{
				// Check if statement
				switch(node->Child[1]->type)
				{
					case _GT:
					case _GE:
					case _LT:
					case _LE:
					case _EQ:
					case _NE:
					case _SHIFTLEFT:
					case _SHIFTRIGHT:
					case _BITAND:
					case _BITXOR:
					case _BITOR:
					case _AND:
					case _OR:
					{
						CheckExpCond(node->Child[0]);
						CheckExpCond(node->Child[2]);
					}
						break;
					default:
						break;
				}
			}
			if(node->Child[0]->type == _LP && node->Child[1]->type == _EXP && node->Child[2]->type == _RP)
			{
				CheckExpCond(node->Child[1]);
			}
		}
	}
}

bool Semantictree::GetContainedError()
{
	return containedError;
}
