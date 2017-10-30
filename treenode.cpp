/*************************************************************************
 Class TreeNode.cpp
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
#include "treenode.h"
//---------------------------------------------------------------- NAMESPACES
using namespace std;
//---------------------------------------------------------------- GLOBAL VARIABLES
bool mainIsFinded = false;
bool isWellFormed = true;
//---------------------------------------------------------------- METHODS

/* Function which create a new NodeT with value */
struct NodeT * Treenode::CreateNode(enum TypeNode type, char * value)
{
	struct NodeT * t = (NodeT *)malloc(sizeof(struct NodeT));
	t->type = type;
	t->value = value;
	t->Parent = NULL;
	int i;
	for(i = 0; i < NB_CHILD; i++)
	{
		t->Child[i] = NULL; 
	}
	return t;
}

/* Add a NodeT to a parent NodeT */
void Treenode::AddNode(struct NodeT * parent, struct NodeT * child)
{
	if(child != NULL)
	{
		child->Parent = parent;

		int i;
		for(i = 0; i < NB_CHILD; i++)
		{
			if(parent->Child[i] == NULL)
			{
				parent->Child[i] = child;
				break;
			}
		}
		if(!DispatchNodeFunction(parent) && isWellFormed)
		{
			isWellFormed = false;
		}
	}
}

/* Check 1-dimensional array */
bool Treenode::CheckOneDimensionArray(struct NodeT * parent)
{
	int countVar = 0;
	struct NodeT * tmpVar = parent->Child[0];
			
	while(tmpVar!= NULL && tmpVar->type == _VAR && countVar < 2)
	{
		countVar ++;
		tmpVar = tmpVar->Child[0];
	}
	if(countVar > 1)
	{
		fprintf(stderr, "%s\n", "Only one dimensional array is permitted");
		return false;
	}
	return true;
}

/* Only integer type into Struct NodeT */
bool Treenode::CheckStructInt(struct NodeT * parent)
{
	if(parent->Child[3] != NULL && parent->Child[3]->type == _DEFS)
	{
		struct NodeT * tmpDefs = parent->Child[3];
		while(tmpDefs->Child[1] != NULL)
		{
			struct NodeT * tmpDef = tmpDefs->Child[0];
			if(tmpDef->Child[0] != NULL && tmpDef->Child[0]->type == _SPEC)
			{
				struct NodeT * tmpSpec = tmpDef->Child[0];
				if(tmpSpec->Child[0]->type != _TYPE)
				{
					fprintf(stderr, "%s\n", "Only integer type is permitted into struct NodeT");
					return false;
				}
			}
			tmpDefs = tmpDefs->Child[1];
		}
	}
	return true;
}

/* Check return int type function*/
bool Treenode::CheckFunctionReturnInt(struct NodeT * parent)
{
	struct NodeT * funcNodeT = parent->Child[1];
	if(funcNodeT != NULL && funcNodeT->type == _FUNC)
	{
		if(parent->Child[0]->Child[0]->type != _TYPE)
		{
			fprintf(stderr, "%s\n", "Integer type has to be returned by function");
			return false;
		}
	}
	return true;
}

/* Check Main function into sample */
bool Treenode::CheckMainFunctionFinded(struct NodeT * parent)
{
	struct NodeT * funcNodeT = parent->Child[0];
	if(funcNodeT != NULL && funcNodeT->type == _ID)
	{
		if(strcmp(funcNodeT->value, "main") == 0)
		{
			mainIsFinded = true;
		}
	}
	return true;
}

/* Check NodeT type with restrictions */
bool Treenode::DispatchNodeFunction(struct NodeT * parent)
{
	bool res = true;
	switch(parent->type)
	{
		case _VAR :
			res = CheckOneDimensionArray(parent);
			break;
		case _STSPEC :
			res = CheckStructInt(parent);
			break;
		case _EXTDEF :
			res = CheckFunctionReturnInt(parent);
			break;
		case _FUNC :
			res = CheckMainFunctionFinded(parent);
			break;
		default : break;
	}
	return res;
}

/* Return the global variable isMainFinded */
bool Treenode::GetMainFunctionFinded()
{
	return mainIsFinded;
}

/* Set the boolean isWellFormed */
void Treenode::SetWellFormed(bool b)
{
	isWellFormed = b;
}

/* Get a char * with nb times underscore character */
void Treenode::Printchar(char *c, int n, FILE *myfile)
{
	int i;
	for(i=0;i<n;i++)
	{
		fprintf(myfile," %s",c);
	}
}

/* Print NodeT according to the depth */
void Treenode::PrintNode(struct NodeT * node, int depth, FILE *myfile)
{
	if(node != NULL && isWellFormed && mainIsFinded)
	{
		Printchar((char*)"|", depth, myfile);
		if(node->type == _ID || node->type == _OCTAL || node->type == _HEXADECIMAL || node->type == _DECIMAL)
		{
			fprintf(myfile," %s (%s)\n", typeNodeTable[(int)node->type], node->value);
		} else
		{
			fprintf(myfile," %s\n", typeNodeTable[(int)node->type]);
		}

		int i;
		for(i = 0; i < NB_CHILD; i++)
		{
			if(node->Child[i] != NULL)
			{
				PrintNode(node->Child[i], depth + 1, myfile);
			} else {
				break;
			}
		}
	} else
	{
		if(!isWellFormed)
		{
			printf("Error : file is not well formed\n");
		} else if(!mainIsFinded) {
			printf("Error : \"main\" function doesn't exist !\n");
		}
		fprintf(myfile, "Error");
	}
}

/* Free tree */
void Treenode::EraseTree(struct NodeT * NodeT)
{
	int i;

	for(i = 0; i < NB_CHILD; ++i)
	{
		if(NodeT->Child[i] != NULL)
		{
			EraseTree(NodeT->Child[i]);
		}
		free(NodeT->Child[i]);
	}
	free(NodeT->value);
}
