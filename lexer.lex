%{

#include <stdio.h>

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
IDENT [a-zA-Z][a-zA-Z0-9]*
INVALIDIDENT1 [_0-9][a-zA-Z][a-zA-Z0-9]*
INVALIDIDENT2 [a-zA-Z][a-zA-Z0-9]*[_]
%%


"tni" {printf("INTEGER\n"); num_chars += yyleng;}
"noitcnuf" {printf("FUNCTION\n");  num_chars += yyleng;}
"}" {printf("BEGIN_BODY\n"); num_chars += yyleng;}
"{" {printf("END_BODY\n"); num_chars += yyleng;}
"yarra" {printf("ARRAY\n"); num_chars += yyleng;}
"fo" {printf("OF\n"); num_chars += yyleng;}
"fi" {printf("IF\n"); num_chars += yyleng;}
"neht" {printf("THEN\n"); num_chars += yyleng;}
"fidne" {printf("ENDIF\n"); num_chars += yyleng;}
"esle" {printf("ELSE\n"); num_chars += yyleng;}
"elihw" {printf("WHILE\n"); num_chars += yyleng;}
"od" {printf("DO\n"); num_chars += yyleng;}
"etunitnoc" {printf("CONTINUE\n"); num_chars += yyleng;}
"kaerb" {printf("BREAK\n"); num_chars += yyleng;}
"daer" {printf("READ\n"); num_chars += yyleng;}
"etirw" {printf("WRITE\n"); num_chars += yyleng;}
"ton" {printf("NOT\n"); num_chars += yyleng;}
"EURT" {printf("TRUE\n"); num_chars += yyleng;}
"ESLAF" {printf("FALSE\n"); num_chars += yyleng;}
"nruter" {printf("RETURN\n"); num_chars += yyleng;}
"%" {printf("MOD\n"); num_chars += yyleng;}
"!!" {printf("EQ\n"); num_chars += yyleng;}
"><" {printf("NEQ\n"); num_chars += yyleng;}
">" {printf("LT\n"); num_chars += yyleng;}
"<" {printf("GT\n"); num_chars += yyleng;}
">=" {printf("LTE\n"); num_chars += yyleng;}
"<=" {printf("GTE\n"); num_chars += yyleng;}
":" {printf("SEMICOLON\n"); num_chars += yyleng;}
";" {printf("COLON\n"); num_chars += yyleng;}
"." {printf("COMMA\n"); num_chars += yyleng;}
"[" {printf("L_SQUARE_BRACKET\n"); num_chars += yyleng;}
"]" {printf("R_SQUARE_BRACKET\n"); num_chars += yyleng;}
"!=" {printf("EQUAL\n"); num_chars += yyleng;}
{DIGIT}+ {printf("NUMBER: %s\n", yytext); num_chars += yyleng;}
{PLUS}   {printf("PLUS\n", yytext); num_chars += yyleng;}
{MINUS}  {printf("MINUS\n", yytext); num_chars += yyleng;}
{MULT}   {printf("MULT\n", yytext); num_chars += yyleng;}
{DIV}   {printf("DIV\n", yytext); num_chars += yyleng;}
{L_PAREN}   {printf("L_PAREN\n", yytext); num_chars += yyleng;}
{R_PAREN}   {printf("R_PAREN\n", yytext); num_chars += yyleng;}
{EQUAL}   {printf("ASSIGN\n", yytext); num_chars += yyleng;}
{INVALIDIDENT1}    {printf("Error at line %d, identifier '%s' must begin with a letter or end without an underscore\n", num_lines, yytext); num_chars += yyleng;}
{INVALIDIDENT2}    {printf("Error at line %d, identifier '%s' must begin with a letter or end without an underscore\n", num_lines, yytext); num_chars += yyleng;}
{IDENT}    {printf("IDENT %s\n", yytext); num_chars += yyleng;}


"\\"	/* comments */ 
" "    
"\t" 
"\n"    ++num_lines; num_chars = 1; // reset num_chars when moving to a new line

. 	++num_chars; printf("Error at line %d, at position: %d. Unrecognized symbol: %s \n", num_lines, num_chars+1, yytext);	

%%

main(void) {
    printf("Cntrl-D to exit\n");
       yylex();
}



