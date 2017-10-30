/*************************************************************************
 Main.cpp
 -------------------
 date                : december 2013
 auteur           	 : TA Alexandre
 *************************************************************************/

//---------------------------------------------------------------- INCLUDES
#include <iostream>
//----------------------------------------------------------------
#include "treenode.h"
//---------------------------------------------------------------- NAMESPACES
using namespace std;
//---------------------------------------------------------------- EXTERNS
extern int yyparse();
extern int yyparse(void);
extern void Run(char* file);
extern void EraseTreeNode(void);
extern FILE* yyin;
//---------------------------------------------------------------- METHODS

/* Main function */
int main(int argc, char **argv)
{
	// Input file
	FILE *myfileIn = fopen(argv[1],"r");
	// Output file contains the result (tree or error)
	char * out = argv[2];
	// Failed
	if (myfileIn != NULL)
	{
		yyin = myfileIn;
		yyparse();
		Run(out);
		EraseTreeNode();
		fclose(yyin);
	} else {
		fprintf(stderr, "Cannot open the input file ! \n");
	}
	return 0;
}

