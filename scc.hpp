/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRUCT = 258,
     RETURN = 259,
     IF = 260,
     ELSE = 261,
     BREAK = 262,
     CONTINUE = 263,
     FOR = 264,
     TYPE = 265,
     SEMI = 266,
     COMMA = 267,
     LP = 268,
     RP = 269,
     LB = 270,
     RB = 271,
     LC = 272,
     RC = 273,
     OCTAL = 274,
     HEXADECIMAL = 275,
     DECIMAL = 276,
     ID = 277,
     ASSIGNSHIFTR = 278,
     ASSIGNSHIFTL = 279,
     ASSIGNORBIT = 280,
     ASSIGNXORBIT = 281,
     ASSIGNANDBIT = 282,
     ASSIGNDIV = 283,
     ASSIGNMINUS = 284,
     ASSIGNMULT = 285,
     ASSIGNPLUS = 286,
     ASSIGN = 287,
     OR = 288,
     AND = 289,
     BITOR = 290,
     BITXOR = 291,
     BITAND = 292,
     EQ = 293,
     NE = 294,
     GT = 295,
     GE = 296,
     LT = 297,
     LE = 298,
     SHIFTLEFT = 299,
     SHIFTRIGHT = 300,
     PLUS = 301,
     MINUS = 302,
     MULT = 303,
     DIV = 304,
     MOD = 305,
     UNARYNOT = 306,
     UNARYINCR = 307,
     UNARYDECR = 308,
     UNARYBITNOT = 309,
     UMINUS = 310,
     DOT = 311
   };
#endif
/* Tokens.  */
#define STRUCT 258
#define RETURN 259
#define IF 260
#define ELSE 261
#define BREAK 262
#define CONTINUE 263
#define FOR 264
#define TYPE 265
#define SEMI 266
#define COMMA 267
#define LP 268
#define RP 269
#define LB 270
#define RB 271
#define LC 272
#define RC 273
#define OCTAL 274
#define HEXADECIMAL 275
#define DECIMAL 276
#define ID 277
#define ASSIGNSHIFTR 278
#define ASSIGNSHIFTL 279
#define ASSIGNORBIT 280
#define ASSIGNXORBIT 281
#define ASSIGNANDBIT 282
#define ASSIGNDIV 283
#define ASSIGNMINUS 284
#define ASSIGNMULT 285
#define ASSIGNPLUS 286
#define ASSIGN 287
#define OR 288
#define AND 289
#define BITOR 290
#define BITXOR 291
#define BITAND 292
#define EQ 293
#define NE 294
#define GT 295
#define GE 296
#define LT 297
#define LE 298
#define SHIFTLEFT 299
#define SHIFTRIGHT 300
#define PLUS 301
#define MINUS 302
#define MULT 303
#define DIV 304
#define MOD 305
#define UNARYNOT 306
#define UNARYINCR 307
#define UNARYDECR 308
#define UNARYBITNOT 309
#define UMINUS 310
#define DOT 311




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "scc.y"
{
	char * valeur;
	char * name;
	struct NodeT * node;
}
/* Line 1529 of yacc.c.  */
#line 167 "scc.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

