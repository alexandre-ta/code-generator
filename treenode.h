/*************************************************************************
 Header TreeNode.h
 -------------------
 date                : december 2013
 auteur           	 : TA Alexandre 7110309022
 *************************************************************************/
#ifndef TREENODE_H
#define TREENODE_H
//---------------------------------------------------------------- INCLUDES
#include <stdio.h>
#include <iostream>
#include <list>
#include <map>
#include <set>
//----------------------------------------------------------------
#include "node.h"
//---------------------------------------------------------------- NAMESPACES
using namespace std;
//---------------------------------------------------------------- GLOBAL VARIABLES
/* Define Maximum children */
#define NB_CHILD 9

/* Type of node */
enum TypeNode {_PROGRAM, _EXTDEFS, _EXTDEF, _SPEC, _EXTVARS, _FUNC, _STMTBLOCK, _DEC, _STSPEC, _OPTTAG, _DEFS, _VAR, _PARAS, _PARA, _STMTS, _STMT, _EXP, _ESTMT, _DEF, _INIT, _ARGS, _DECS, _ARRS,
	_STRUCT, _RETURN, _IF, _ELSE, _BREAK, _CONTINUE, _FOR, _TYPE, _SEMI, _COMMA, _LP, _RP, _LB, _RB, _LC, _RC, _ASSIGN, _ASSIGNPLUS, _ASSIGNMULT, _ASSIGNMINUS, _ASSIGNDIV, _ASSIGNANDBIT, _ASSIGNXORBIT,
	_ASSIGNORBIT, _ASSIGNSHIFTL, _ASSIGNSHIFTR, _OR, _AND, _BITOR, _BITXOR, _BITAND, _NE, _EQ, _LE, _LT, _GE, _GT, _SHIFTRIGHT, _SHIFTLEFT, _MINUS, _PLUS, _MOD, _DIV, _MULT,
	_UNARYBITNOT, _UNARYDECR, _UNARYINCR, _UNARYNOT, _DOT, _OCTAL, _HEXADECIMAL, _DECIMAL, _ID};

static const char* typeNodeTable[] = {"PROGRAM", "EXTDEFS", "EXTDEF", "SPEC", "EXTVARS", "FUNC", "STMTBLOCK", "DEC", "STSPEC", "OPTTAG", "DEFS", "VAR", "PARAS", "PARA", "STMTS", "STMT", "EXP", "ESTMT", "DEF", "INIT", "ARGS", "DECS", "ARRS",
		"STRUCT", "RETURN", "IF", "ELSE", "BREAK", "CONTINUE", "FOR", "TYPE", "SEMI", "COMMA", "LP", "RP", "LB", "RB", "LC", "RC", "ASSIGN", "ASSIGNPLUS", "ASSIGNMULT", "ASSIGNMINUS", "ASSIGNDIV", "ASSIGNANDBIT", "ASSIGNXORBIT",
		"ASSIGNORBIT", "ASSIGNSHIFTL", "ASSIGNSHIFTR", "OR", "AND", "BITOR", "BITXOR", "BITAND", "NE", "EQ", "LE", "LT", "GE", "GT", "SHIFTRIGHT", "SHIFTLEFT", "MINUS", "PLUS", "MOD", "DIV", "MULT",
		"UNARYBITNOT", "UNARYDECR", "UNARYINCR", "UNARYNOT", "DOT", "OCTAL", "HEXADECIMAL", "DECIMAL", "ID"};

/* Semantic of a node */
struct NodeT
{
	enum TypeNode type;
	char * value;
	
	struct NodeT * Parent;
	struct NodeT * Child[NB_CHILD];
};
//---------------------------------------------------------------- DECLARATION
/* This class contains all methods used for building syntax tree */
class Treenode {
	
	public:
	
	// Constructor
	Treenode(){}

	// Create a node with value according to the type
	static struct NodeT * CreateNode(enum TypeNode type, char * value);

	// Add a node to a parent node
	static void AddNode(struct NodeT * parent, struct NodeT * child);

	// Print node
	static void PrintNode(struct NodeT * node, int depth, FILE *myfile);

	// Print nb times underscore character
	static void Printchar(char *c, int n, FILE *myfile);

	// Get boolean mainIsFinded
	static bool GetMainFunctionFinded();

	// Process different methods depends on node type
	static bool DispatchNodeFunction(struct NodeT * parent);

	// Check one dimension array
	static bool CheckOneDimensionArray(struct NodeT * parent);

	// Check integer type into struct node
	static bool CheckStructInt(struct NodeT * parent);

	// Check return type is integer
	static bool CheckFunctionReturnInt(struct NodeT * parent);

	// Check function main
	static bool CheckMainFunctionFinded(struct NodeT * parent);

	// Set variable isWellFormed
	static void SetWellFormed(bool b);

	// Free tree
	static void EraseTree(struct NodeT * node);
	
};
#endif