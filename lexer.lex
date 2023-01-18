%{

#include <stdio.h>

%}

DIGIT [0-9]
PLUS [-]
MINUS [+]
MULT [/]
DIV  [*]
L_PAREN [(]
R_PAREN [)]
EQUAL [=]

%%

{DIGIT}+ {printf("NUMBER: %s\n", yytext);}
{PLUS}   {printf("PLUS\n", yytext);}
{MINUS}  {printf("MINUS\n", yytext);}
{MULT}   {printf("MULT\n", yytext);}
{DIV}   {printf("DIV\n", yytext);}
{L_PAREN}   {printf("L_PAREN\n", yytext);}
{R_PAREN}   {printf("R_PAREN\n", yytext);}
{EQUAL}   {printf("EQUAL\n", yytext);}
"tni" {printf("INTEGER\n");}
.	 {}

%%

main(void) {
    printf("Cntrl-D to exit\n");
        yylex();
}


