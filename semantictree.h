/*************************************************************************
 Header Semantictree.h
 -------------------
 date                : december 2013
 auteur           	 : TA Alexandre
 *************************************************************************/
#ifndef SEMANTICTREE_H
#define SEMANTICTREE_H
//---------------------------------------------------------------- INCLUDES
#include <stdio.h>
#include <list>
#include <map>
#include <set>
//----------------------------------------------------------------
#include "treenode.h"
//---------------------------------------------------------------- NAMESPACES
using namespace std;
//---------------------------------------------------------------- GLOBAL VARIABLES
/* enum variable type */
enum VariableType {_TYPE_INT, _TYPE_STRUCT, _TYPE_ARRAYS};

/* Reserved keywords for c++ */
static const std::string keywords[] = {
	"alignas",
	"alignof",
	"and",
	"and_eq",
	"asm",
	"auto",
	"bitand",
	"bitor",
	"bool",
	"break",
	"case",
	"catch",
	"char",
	"char16_t",
	"char32_t",
	"class",
	"compl",
	"const",
	"constexpr",
	"const_cast",
	"continue",
	"decltype",
	"default",
	"delete",
	"do",
	"double",
	"dynamic_cast",
	"else",
	"enum",
	"explicit",
	"export",
	"extern",
	"false",
	"float",
	"for",
	"friend",
	"goto",
	"if",
	"inline",
	"int",
	"long",
	"mutable",
	"namespace",
	"new",
	"noexcept",
	"not",
	"not_eq",
	"nullptr",
	"operator",
	"or",
	"or_eq",
	"private",
	"protected",
	"public",
	"register",
	"reinterpret_cast",
	"return",
	"short",
	"signed",
	"sizeof",
	"static",
	"static_assert",
	"static_cast",
	"struct",
	"switch",
	"template",
	"this",
	"thread_local",
	"throw",
	"true",
	"try",
	"typedef",
	"typeid",
	"typename",
	"union",
	"unsigned",
	"using",
	"virtual",
	"void",
	"volatile",
	"wchar_t",
	"while",
	"xor",
	"xor_eq"
};
static const std::set<std::string> ReservedWords(keywords, keywords + sizeof(keywords) / sizeof(keywords[0]));

//---------------------------------------------------------------- DECLARATION
/* Class for checking parse tree semantically */
class Semantictree {
	private:
	
	// Browse Function node
	static void CheckVarFuncRuleFunction(struct NodeT * nodeExtdef, map<string, list<VariableType> > &previousFunctions, map<string, set<VariableType> > &globalVariables);
	
	// Browse STMTBLOCK node
	static void CheckVarFuncRuleStmtBlock(struct NodeT * stmtblock, map<string, set<VariableType> > &globalVariables, map<string, list<VariableType> > &previousFunctions);
	
	// Browse DEFS node
	static void CheckVarFuncRuleDefs(struct NodeT * defs, map<string, set<VariableType> > &previousVariable, map<string, list<VariableType> > &previousFunctions);
	
	// Browse EXP node
	static void CheckVarFuncRuleFunctionExp(struct NodeT * node, map<string, set<VariableType> > &previousVariable, map<string, list<VariableType> > &previousFunctions);

	// Browse STMTS node
	static void CheckVarFuncRuleStmts(struct NodeT * stmts, map<string, set<VariableType> > &previousVariable,  map<string, list<VariableType> > &previousFunctions);
	
	// Browse STMT node
	static void CheckVarFuncRuleStmt(struct NodeT * stmt, map<string, set<VariableType> > &previousVariable,  map<string, list<VariableType> > &previousFunctions);
		
	// Browse ARGS node
	static void CheckParamFunction(struct NodeT * expFunction, map<string, set<VariableType> > &previousVariable,  map<string, list<VariableType> > &previousFunctions);
	
	// Check Continue node into for statement
	static void CheckForContSemi(struct NodeT *node);
	
	// Check condition for If-then-else statement and for loop statement
	static void CheckExpCond(struct NodeT *node);
	
	public:

	// Constructor
	Semantictree(){}
	
	// Variables and functions should be declared before usage and once
	static void CheckVarFuncRule(struct NodeT * node);

	// Reserved words cannot be used as identifiers
	// Continue break into for loop statement
	// Condition for if-then-else statement and for-loop
	static void CheckSemanticRules(struct NodeT *node);
	
	// Get contained errors boolean
	static bool GetContainedError();
};
#endif