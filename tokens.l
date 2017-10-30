%{
#include <string>
#include "node.h"
#include "scc.hpp"
%}
%option noyywrap

newline				\n
digit				[0-9]
letter				[a-zA-Z]
hexdigit			[a-fA-F0-9]
octaldigit			[0-7]
letterunderscore	{letter}|_

hexadecimal			0[xX]{hexdigit}+
decimal				{digit}+
octal				0{octaldigit}+
id					{letterunderscore}({letterunderscore}|{digit})*

mult					"*"
div						"/"
mod						"%"
plus					"+"
minus					"-"
gt						">"
ge						">="
lt						"<"
le						"<="
eq						"=="
ne						"!="
shift_left				"<<"
shift_right				">>"
bit_and					"&"
bit_xor					"^"
bit_or					"|"
and						"&&"
or						"||"
assign					"="
assign_plus				"+="
assign_minus			"-="
assign_mult				"*="
assign_div				"/="
assign_andbit			"&="
assign_xorbit			"^="
assign_orbit			"|="
assign_shiftl			"<<="
assign_shiftr			">>="
unary_not				"!"
unary_incr				"++"
unary_decr				"--"
unary_bitnot			"~"

semi					";"
comma					","
dot						"."

int						"int"
lp						"("
rp						")"
lb						"["
rb						"]"
lc						"{"
rc						"}"
struct					"struct"
return					"return"
if						"if"
else					"else"
break					"break"
continue				"continue"
for						"for"

%%
"/*".*"*/"				{} /*Ignore comments*/
{newline}        		{yylineno++;}


{struct}				{return STRUCT;}
{return}				{return RETURN;}
{if}					{return IF;}
{else}					{return ELSE;}
{break}					{return BREAK;}
{continue}				{return CONTINUE;}
{for}					{return FOR;}

{octal}					{yylval.valeur = strdup(yytext); return OCTAL;}
{hexadecimal}			{yylval.valeur = strdup(yytext); return HEXADECIMAL;}
{decimal}				{yylval.valeur = strdup(yytext); return DECIMAL;}

{int}					{return TYPE;}
{id}					{yylval.name = strdup(yytext); return ID;}

{semi}					{return SEMI;}
{comma}					{return COMMA;}
{dot}					{return DOT;}

{mult}					{return MULT;}
{div}					{return DIV;}
{mod}					{return MOD;}
{plus}					{return PLUS;}
{minus}					{return MINUS;}

{gt}					{return GT;}
{ge}					{return GE;}
{lt}					{return LT;}
{le}					{return LE;}
{eq}					{return EQ;}
{ne}					{return NE;}

{shift_left}			{return SHIFTLEFT;}
{shift_right}			{return SHIFTRIGHT;}
{bit_and}				{return BITAND;}
{bit_xor}				{return BITXOR;}
{bit_or}				{return BITOR;}

{and}					{return AND;}
{or}					{return OR;}

{assign}				{return ASSIGN;}
{assign_plus}			{return ASSIGNPLUS;}
{assign_minus}			{return ASSIGNMINUS;}
{assign_mult}			{return ASSIGNMULT;}
{assign_div}			{return ASSIGNDIV;}
{assign_andbit}			{return ASSIGNANDBIT;}
{assign_xorbit}			{return ASSIGNXORBIT;}
{assign_orbit}			{return ASSIGNORBIT;}
{assign_shiftl}			{return ASSIGNSHIFTL;}
{assign_shiftr}			{return ASSIGNSHIFTR;}


{unary_not}				{return UNARYNOT;}
{unary_incr}			{return UNARYINCR;}
{unary_decr}			{return UNARYDECR;}
{unary_bitnot}			{return UNARYBITNOT;}

{lp}					{return LP;}
{rp}					{return RP;}
{lb}					{return LB;}
{rb}					{return RB;}
{lc}					{return LC;}
{rc}					{return RC;}
[ \t]    				{}
.           			{}
%%
