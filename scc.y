/*
 * Yacc/Bison file compiler.y
 * Syntax analyzer to build a parse tree
 */
%{
    #include <stdio.h>
	#include <stdlib.h>
	#include "treenode.h"
	#include "semantictree.h"
	#include "llvmbuild.h"
	
	// Lexer prototype required by bison
	extern int yylex();
	void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }
	// Root node
	struct NodeT * node = NULL;
	
	%}

// Declare another data type
%union {
	char * valeur;
	char * name;
	struct NodeT * node;
}

// Tokens
%token STRUCT RETURN IF ELSE BREAK CONTINUE FOR TYPE SEMI COMMA LP RP LB RB LC RC

%token<valeur> OCTAL
%token<valeur> HEXADECIMAL
%token<valeur> DECIMAL
%token<name> ID

// Operators precedence
// UMINUS is used to differentiate unary and binary minus
%right ASSIGN ASSIGNPLUS ASSIGNMULT ASSIGNMINUS ASSIGNDIV ASSIGNANDBIT ASSIGNXORBIT ASSIGNORBIT ASSIGNSHIFTL ASSIGNSHIFTR
%left OR
%left AND
%left BITOR
%left BITXOR
%left BITAND
%left NE EQ
%left LE LT GE GT
%left SHIFTRIGHT SHIFTLEFT
%left MINUS PLUS
%left MOD DIV MULT
%left UMINUS UNARYBITNOT UNARYDECR UNARYINCR UNARYNOT
%left DOT

// Non terminal as a node
%type <node> program extdefs extdef spec extvars func stmtblock dec stspec opttag defs var paras para stmts stmt exp estmt def init args decs arrs

%start program
%%
program
: extdefs					{node = Treenode::CreateNode(_PROGRAM, NULL); Treenode::AddNode(node, $1);}
;

extdefs
: extdef extdefs			{$$ = Treenode::CreateNode(_EXTDEFS, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, $2);}
| /* empty */				{$$ = Treenode::CreateNode(_EXTDEFS, NULL);}
;

extdef
: spec extvars SEMI			{$$ = Treenode::CreateNode(_EXTDEF, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, $2); Treenode::AddNode($$, Treenode::CreateNode(_SEMI, NULL));}
| spec func stmtblock		{$$ = Treenode::CreateNode(_EXTDEF, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, $2); Treenode::AddNode($$, $3);}
;

extvars
: dec						{$$ = Treenode::CreateNode(_EXTVARS, NULL); Treenode::AddNode($$, $1);}
| dec COMMA extvars			{$$ = Treenode::CreateNode(_EXTVARS, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_COMMA, NULL)); Treenode::AddNode($$, $3);}
| /* empty */				{$$ = Treenode::CreateNode(_EXTVARS, NULL);}
;

spec
: TYPE						{$$ = Treenode::CreateNode(_SPEC, NULL); Treenode::AddNode($$, Treenode::CreateNode(_TYPE, NULL));}
| stspec					{$$ = Treenode::CreateNode(_SPEC, NULL); Treenode::AddNode($$, $1);}
;

stspec
: STRUCT opttag LC defs RC	{$$ = Treenode::CreateNode(_STSPEC, NULL); Treenode::AddNode($$, Treenode::CreateNode(_STRUCT, NULL)); Treenode::AddNode($$, $2); Treenode::AddNode($$, Treenode::CreateNode(_LC, NULL)); Treenode::AddNode($$, $4); Treenode::AddNode($$, Treenode::CreateNode(_RC, NULL));}
| STRUCT ID					{$$ = Treenode::CreateNode(_STSPEC, NULL); Treenode::AddNode($$, Treenode::CreateNode(_STRUCT, NULL)); Treenode::AddNode($$, Treenode::CreateNode(_ID, $2));}
;

opttag
: ID						{$$ = Treenode::CreateNode(_OPTTAG, NULL); Treenode::AddNode($$, Treenode::CreateNode(_ID, $1)); }
| /* empty */				{$$ = Treenode::CreateNode(_OPTTAG, NULL);}
;

var
: ID						{$$ = Treenode::CreateNode(_VAR, NULL); Treenode::AddNode($$, Treenode::CreateNode(_ID, $1));}
| var LB OCTAL RB			{$$ = Treenode::CreateNode(_VAR, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_LB, NULL)); Treenode::AddNode($$, Treenode::CreateNode(_OCTAL, $3)); Treenode::AddNode($$, Treenode::CreateNode(_RB, NULL));}
| var LB HEXADECIMAL RB		{$$ = Treenode::CreateNode(_VAR, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_LB, NULL)); Treenode::AddNode($$, Treenode::CreateNode(_HEXADECIMAL, $3)); Treenode::AddNode($$, Treenode::CreateNode(_RB, NULL));}
| var LB DECIMAL RB			{$$ = Treenode::CreateNode(_VAR, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_LB, NULL)); Treenode::AddNode($$, Treenode::CreateNode(_DECIMAL, $3)); Treenode::AddNode($$, Treenode::CreateNode(_RB, NULL));}
;

func
: ID LP paras RP			{$$ = Treenode::CreateNode(_FUNC, NULL); Treenode::AddNode($$, Treenode::CreateNode(_ID, $1)); Treenode::AddNode($$, Treenode::CreateNode(_LP, NULL)); Treenode::AddNode($$, $3); Treenode::AddNode($$, Treenode::CreateNode(_RP, NULL));}
;

paras
: para COMMA paras			{$$ = Treenode::CreateNode(_PARAS, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_COMMA, NULL)); Treenode::AddNode($$, $3);}
| para						{$$ = Treenode::CreateNode(_PARAS, NULL); Treenode::AddNode($$, $1);}
| /* empty */				{$$ = Treenode::CreateNode(_PARAS, NULL);}
;

para
: spec var					{$$ = Treenode::CreateNode(_PARA, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, $2);}
;

stmtblock
: LC defs stmts RC			{$$ = Treenode::CreateNode(_STMTBLOCK, NULL); Treenode::AddNode($$, Treenode::CreateNode(_LC, NULL)); Treenode::AddNode($$, $2); Treenode::AddNode($$, $3); Treenode::AddNode($$, Treenode::CreateNode(_RC, NULL));}
;

stmts
: stmt stmts				{$$ = Treenode::CreateNode(_STMTS, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, $2);}
| /* empty */				{$$ = Treenode::CreateNode(_STMTS, NULL);}
;

stmt
: exp SEMI					{$$ = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_SEMI, NULL));}
| stmtblock					{$$ = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode($$, $1);}
| RETURN exp SEMI			{$$ = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode($$, Treenode::CreateNode(_RETURN, NULL)); Treenode::AddNode($$, $2); Treenode::AddNode($$, Treenode::CreateNode(_SEMI, NULL));}
| IF LP exp RP stmt estmt	{$$ = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode($$, Treenode::CreateNode(_IF, NULL)); Treenode::AddNode($$, Treenode::CreateNode(_LP, NULL)); Treenode::AddNode($$, $3); Treenode::AddNode($$, Treenode::CreateNode(_RP, NULL)); Treenode::AddNode($$, $5); Treenode::AddNode($$, $6);}
| FOR LP exp SEMI exp SEMI exp RP stmt
{$$ = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode($$, Treenode::CreateNode(_FOR, NULL)); Treenode::AddNode($$, Treenode::CreateNode(_LP, NULL)); Treenode::AddNode($$, $3); Treenode::AddNode($$, Treenode::CreateNode(_SEMI, NULL)); Treenode::AddNode($$, $5); Treenode::AddNode($$, Treenode::CreateNode(_SEMI, NULL)); Treenode::AddNode($$, $7); Treenode::AddNode($$, Treenode::CreateNode(_RP, NULL)); Treenode::AddNode($$, $9);}
| CONTINUE SEMI				{$$ = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode($$, Treenode::CreateNode(_CONTINUE, NULL)); Treenode::AddNode($$, Treenode::CreateNode(_SEMI, NULL));}
| BREAK SEMI				{$$ = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode($$, Treenode::CreateNode(_BREAK, NULL)); Treenode::AddNode($$, Treenode::CreateNode(_SEMI, NULL));}
;

estmt
: ELSE stmt					{$$ = Treenode::CreateNode(_ESTMT, NULL); Treenode::AddNode($$, Treenode::CreateNode(_ELSE, NULL)); Treenode::AddNode($$, $2);}
| /* empty */				{$$ = Treenode::CreateNode(_ESTMT, NULL);}
;

defs
: def defs					{$$ = Treenode::CreateNode(_DEFS, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, $2);}
| /* empty */				{$$ = Treenode::CreateNode(_DEFS, NULL);}
;

def
: spec decs SEMI			{$$ = Treenode::CreateNode(_DEF, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, $2); Treenode::AddNode($$, Treenode::CreateNode(_SEMI, NULL));}
;

decs
: dec COMMA decs			{$$ = Treenode::CreateNode(_DECS, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_COMMA, NULL)); Treenode::AddNode($$, $3);}
| dec						{$$ = Treenode::CreateNode(_DECS, NULL); Treenode::AddNode($$, $1);}
;

dec
: var						{$$ = Treenode::CreateNode(_DEC, NULL); Treenode::AddNode($$, $1);}
| var ASSIGN init			{$$ = Treenode::CreateNode(_DEC, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGN, NULL)); Treenode::AddNode($$, $3);}
;

init
: exp						{$$ = Treenode::CreateNode(_INIT, NULL); Treenode::AddNode($$, $1);}
| LC args RC				{$$ = Treenode::CreateNode(_INIT, NULL); Treenode::AddNode($$, Treenode::CreateNode(_LC, NULL)); Treenode::AddNode($$, $2); Treenode::AddNode($$, Treenode::CreateNode(_RC, NULL));}
;

exp
: exp MULT exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_MULT, NULL)); Treenode::AddNode($$, $3);}
| exp DIV exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_DIV, NULL)); Treenode::AddNode($$, $3);}
| exp MOD exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_MOD, NULL)); Treenode::AddNode($$, $3);}
| exp PLUS exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_PLUS, NULL)); Treenode::AddNode($$, $3);}
| exp MINUS exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_MINUS, NULL)); Treenode::AddNode($$, $3);}
| exp GT exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_GT, NULL)); Treenode::AddNode($$, $3);}
| exp GE exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_GE, NULL)); Treenode::AddNode($$, $3);}
| exp LT exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_LT, NULL)); Treenode::AddNode($$, $3);}
| exp LE exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_LE, NULL)); Treenode::AddNode($$, $3);}
| exp EQ exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_EQ, NULL)); Treenode::AddNode($$, $3);}
| exp NE exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_NE, NULL)); Treenode::AddNode($$, $3);}
| exp SHIFTLEFT exp			{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_SHIFTLEFT, NULL)); Treenode::AddNode($$, $3);}
| exp SHIFTRIGHT exp		{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_SHIFTRIGHT, NULL)); Treenode::AddNode($$, $3);}
| exp BITAND exp			{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_BITAND, NULL)); Treenode::AddNode($$, $3);}
| exp BITXOR exp			{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_BITXOR, NULL)); Treenode::AddNode($$, $3);}
| exp BITOR exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_BITOR, NULL)); Treenode::AddNode($$, $3);}
| exp AND exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_AND, NULL)); Treenode::AddNode($$, $3);}
| exp OR exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_OR, NULL)); Treenode::AddNode($$, $3);}
| exp ASSIGN exp			{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGN, NULL)); Treenode::AddNode($$, $3);}

| exp ASSIGNSHIFTR exp		{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGNSHIFTR, NULL)); Treenode::AddNode($$, $3);}
| exp ASSIGNSHIFTL exp		{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGNSHIFTL, NULL)); Treenode::AddNode($$, $3);}
| exp ASSIGNORBIT exp		{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGNORBIT, NULL)); Treenode::AddNode($$, $3);}
| exp ASSIGNXORBIT exp		{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGNXORBIT, NULL)); Treenode::AddNode($$, $3);}
| exp ASSIGNANDBIT exp		{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGNANDBIT, NULL)); Treenode::AddNode($$, $3);}
| exp ASSIGNDIV exp			{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGNDIV, NULL)); Treenode::AddNode($$, $3);}
| exp ASSIGNMINUS exp		{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGNMINUS, NULL)); Treenode::AddNode($$, $3);}
| exp ASSIGNMULT exp		{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGNMULT, NULL)); Treenode::AddNode($$, $3);}
| exp ASSIGNPLUS exp		{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_ASSIGNPLUS, NULL)); Treenode::AddNode($$, $3);}

| MINUS exp %prec UMINUS	{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_MINUS, NULL)); Treenode::AddNode($$, $2);}
| UNARYNOT exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_UNARYNOT, NULL)); Treenode::AddNode($$, $2);}
| UNARYINCR exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_UNARYINCR, NULL)); Treenode::AddNode($$, $2);}
| UNARYDECR exp				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_UNARYDECR, NULL)); Treenode::AddNode($$, $2);}
| UNARYBITNOT exp			{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_UNARYBITNOT, NULL)); Treenode::AddNode($$, $2);}
| LP exp RP					{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_LP, NULL)); Treenode::AddNode($$, $2); Treenode::AddNode($$, Treenode::CreateNode(_RP, NULL));}
| ID LP args RP				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_ID, $1)); Treenode::AddNode($$, Treenode::CreateNode(_LP, NULL)); Treenode::AddNode($$, $3); Treenode::AddNode($$, Treenode::CreateNode(_RP, NULL));}
| ID arrs					{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_ID, $1)); Treenode::AddNode($$, $2);}
| exp DOT ID				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_DOT, NULL)); Treenode::AddNode($$, Treenode::CreateNode(_ID, $3));}
| OCTAL						{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_OCTAL, $1));}
| HEXADECIMAL				{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_HEXADECIMAL, $1));}
| DECIMAL					{$$ = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode($$, Treenode::CreateNode(_DECIMAL, $1));}
| /* empty */				{$$ = Treenode::CreateNode(_EXP, NULL);}
;

arrs
: LB exp RB arrs			{$$ = Treenode::CreateNode(_ARRS, NULL); Treenode::AddNode($$, Treenode::CreateNode(_LB, NULL)); Treenode::AddNode($$, $2); Treenode::AddNode($$, Treenode::CreateNode(_RB, NULL)); Treenode::AddNode($$, $4);}
| /* empty */				{$$ = Treenode::CreateNode(_ARRS, NULL);}
;

args
: exp COMMA args			{$$ = Treenode::CreateNode(_ARGS, NULL); Treenode::AddNode($$, $1); Treenode::AddNode($$, Treenode::CreateNode(_COMMA, NULL)); Treenode::AddNode($$, $3); }
| exp						{$$ = Treenode::CreateNode(_ARGS, NULL); Treenode::AddNode($$, $1);}
;

%%
// When the scanner receives an end-of-file, just return 1 means ok
int yywrap(void)
{
	return 1;
}

// Run
void Run(char *file)
{
	LLVMBuild::BuildLLVM(node, file);
	//Treenode::PrintNode(node, 0, file);
}

// Free memories
void EraseTreeNode()
{
	Treenode::EraseTree(node);
}

// Print the message error
void yyerror(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	Treenode::SetWellFormed(false);
}

