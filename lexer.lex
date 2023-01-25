%{

#include <stdio.h>

int num_lines = 1;

%}

DIGIT [0-9]
PLUS [-]
MINUS [+]
MULT [/]
DIV  [*]
L_PAREN [(]
R_PAREN [)]
EQUAL [=]
IDENT [a-zA-Z_][a-zA-Z0-9_]*

%%

"tni" {printf("INTEGER\n");}
"noitcnuf" {printf("FUNCTION\n");}
"}" {printf("BEGIN_BODY\n");}
"{" {printf("END_BODY\n");}
"yarra" {printf("ARRAY\n");}
"fo" {printf("OF\n");}
"fi" {printf("IF\n");}
"neht" {printf("THEN\n");}
"fidne" {printf("ENDIF\n");}
"esle" {printf("ELSE\n");}
"elihw" {printf("WHILE\n");}
"od" {printf("DO\n");}
"etunitnoc" {printf("CONTINUE\n");}
"kaerb" {printf("BREAK\n");}
"daer" {printf("READ\n");}
"etirw" {printf("WRITE\n");}
"ton" {printf("NOT\n");}
"EURT" {printf("TRUE\n");}
"ESLAF" {printf("FALSE\n");}
"nruter" {printf("RETURN\n");}
"%" {printf("MOD\n");}
"!!" {printf("EQ\n");}
"><" {printf("NEQ\n");}
">" {printf("LT\n");}
"<" {printf("GT\n");}
">=" {printf("LTE\n");}
"<=" {printf("GTE\n");}
":" {printf("SEMICOLON\n");}
";" {printf("COLON\n");}
"." {printf("COMMA\n");}
"[" {printf("L_SQUARE_BRACKET\n");}
"]" {printf("R_SQUARE_BRACKET\n");}
"!=" {printf("ASSIGN\n");}
{DIGIT}+ {printf("NUMBER: %s\n", yytext);}
{PLUS}   {printf("PLUS\n", yytext);}
{MINUS}  {printf("MINUS\n", yytext);}
{MULT}   {printf("MULT\n", yytext);}
{DIV}   {printf("DIV\n", yytext);}
{L_PAREN}   {printf("L_PAREN\n", yytext);}
{R_PAREN}   {printf("R_PAREN\n", yytext);}
{EQUAL}   {printf("EQUAL\n", yytext);}
{IDENT}    {printf("IDENT %s\n", yytext);}

"\\"	/* comments */
" "
"\t" 
"\n"    ++num_lines;
. 	printf("Error at line %d, unrecognized symbol: %s\n", num_lines, yytext);	

%%

main(void) {
    printf("Cntrl-D to exit\n");
       yylex();
}


