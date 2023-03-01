%{

#include <stdio.h>
#include "y.tab.h"
int num_lines = 1;
int num_chars = 1;
%}

DIGIT [0-9]
PLUS [-]
MINUS [+]
MULT [/]
DIV  [*]
L_PAREN [(]
R_PAREN [)]
EQUAL [=]
IDENT [a-zA-Z][a-zA-Z]*[_]*[a-zA-Z0-9]*
INVALIDIDENT1 [_0-9][a-zA-Z][a-zA-Z0-9]*
INVALIDIDENT2 [a-zA-Z][a-zA-Z0-9]*[_]
%%

"tni" {return INTEGER; num_chars += yyleng;}
"diov" {return FUNCTION; num_chars += yyleng;}
"noitcnuf" {return FUNCTION; num_chars += yyleng;}
"}" {return BEGIN_BODY; num_chars += yyleng;}
"{" {return END_BODY; num_chars += yyleng;}
"yarra" {return ARRAY; num_chars += yyleng;}
"fo" {return OF; num_chars += yyleng;}
"fi" {return IF; num_chars += yyleng;}
"neht" {return THEN; num_chars += yyleng;}
"fidne" {return ENDIF; num_chars += yyleng;}
"esle" {return ELSE; num_chars += yyleng;}
"elihw" {return WHILE; num_chars += yyleng;}
"od" {return DO; num_chars += yyleng;}
"etunitnoc" {return CONTINUE; num_chars += yyleng;}
"kaerb" {return BREAK; num_chars += yyleng;}
"daer" {return READ; num_chars += yyleng;}
"etirw" {return WRITE; num_chars += yyleng;}
"ton" {return NOT; num_chars += yyleng;}
"EURT" {return TRUE; num_chars += yyleng;}
"ESLAF" {return FALSE; num_chars += yyleng;}
"nruter" {return RETURN; num_chars += yyleng;}
"%" {return MOD; num_chars += yyleng;}
"!!" {return EQ; num_chars += yyleng;}
"><" {return NEQ; num_chars += yyleng;}
">" {return LT; num_chars += yyleng;}
"<" {return GT; num_chars += yyleng;}
">=" {return LTE; num_chars += yyleng;}
"<=" {return GTE; num_chars += yyleng;}
":" {return SEMICOLON; num_chars += yyleng;}
";" {return COLON; num_chars += yyleng;}
"." {return COMMA; num_chars += yyleng;}
"[" {return L_SQUARE_BRACKET; num_chars += yyleng;}
"]" {return R_SQUARE_BRACKET; num_chars += yyleng;}
"!=" {return EQUAL; num_chars += yyleng;}
"tuoc" {return WRITE; num_chars += yyleng;}
">>" {return INPUT; num_chars += yyleng;}
"<<" {return OUTPUT; num_chars += yyleng;}
{DIGIT}+ {
    char * token = new char[yyleng];
    strcpy(token, yytext);
    yylval.op_val = token;
    numberToken = atoi(yytext);
    num_chars += yyleng;
    return NUMBER;}
{PLUS}   {return PLUS; num_chars += yyleng;}
{MINUS}  {return MINUS; num_chars += yyleng;}
{MULT}   {return MULT; num_chars += yyleng;}
{DIV}   {return DIV; num_chars += yyleng;}
{L_PAREN}   {return L_PAREN; num_chars += yyleng;}
{R_PAREN}   {return R_PAREN; num_chars += yyleng;}
{EQUAL}   {return ASSIGN; num_chars += yyleng;}
{INVALIDIDENT1}    {printf("Error at line %d, identifier '%s' must begin with a letter or end without an underscore\n", num_lines, yytext);exit; num_chars += yyleng;}
{INVALIDIDENT2}    {printf("Error at line %d, identifier '%s' must begin with a letter or end without an underscore\n", num_lines, yytext);exit; num_chars += yyleng;}
{IDENT}    {
    char * token = new char[yyleng];
    strcpy(token, yytext);
    yylval.op_val = token;
    identToken = yytext;
    return IDENT; num_chars += yyleng;}

"\\"	/* comments */ 
" "    
"\t" 
"\n"    ++num_lines; num_chars = 1; //reset num_chars when moving to a n:wq 
.	++num_chars; printf("Error at line %d at position %d. Unrecognized symbol: %s \n", num_lines, num_chars+1, yytext); // the next symbol is unrecognize, so we manually +1	

%%


/*
main(void) {
    printf("Cntrl-D to exit\n");
       yylex();
}

*/


