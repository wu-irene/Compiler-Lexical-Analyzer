//This is just an example from the lab section
//Please change it accordingly to fit our own language 

%{
#include <stdio.h>
extern FILE* yyin;
%}

%start progstart
%token INTEGER FUNCTION BEGIN_BODY END_BODY ARRAY OF IF THEN ENDIF ELSE WHILE DO CONTINUE BREAK READ WRITE NOT TRUE FALSE RETURN MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_SQUARE_BRACKET R_SQUARE_BRACKET EQUAL NUMBER PLUS MINUS MULT DIV L_PAREN R_PAREN ASSIGN IDENT 

%%

prog start: /* epsilon */ {printf("prog start-›epsilon \n");}
      | functions {printf("prog_start -> functions \n");}


functions: function {printf("functions -› function \n");}
      | function functions {printf("functions -> function functions \n");}


function: INTEGER IDENT L_PAREN arguments R_PAREN BEGIN_BODY statements END_BODY {printf("function -> INTEGER IDENT L_PAREN arguments R_PAREN BEGIN_BODY statements END_BODY\n");}


arguments: argument {printf("arguments -> Argument \n");}
      | argument COMMA arguments {printf("arguments -> COMMA arguments \n");}


argument: /* epsilon */ {printf("argument -> epsilon \n");}
      | INT IDENT {printf("argument -> INT IDENT \n");}


statements: /* epsilon */ {printf("statements -> epsilon \n");}
      | statement SEMICOLON {printf("statements -> statement SEMICOLON \n");} //CW
      | statement SEMICOLON statements {printf("statements -> statement SMICOLON statements \n");} //CW

statement: /* epsilon */ {printf("statement -> epsilon \n");} //CW
      | ifElseState {printf("statement -> ifElseState \n");}
      | whileLoop {printf("statement -> whileLoop\n");}

ifElseState: /* epsilon */ {printf("ifElseState -> epsilon\n");}
      | IF L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY ifElseState {printf("ifElseState -> IF L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY ifElseState\n");}
      | ELSE BEGIN_BODY statements END_BODY {printf("ifElseState -> ELSE BEGIN_BODY statements END_BODY\n");}

whileLoop: /* epsilon */ {printf("whileLoop -> epsilon\n");}
      | WHILE L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY {printf("whileLoop -> WHILE L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY\n");}

condition: /* epsilon */ {printf("condition -> epsilon\n");}
      | IDENT EQ IDENT {printf("condition -> IDENT EQ IDENT\n");}
      | IDENT NEQ IDENT {printf("condition -> IDENT NEQ IDENT\n");}
      | IDENT LT IDENT {printf("condition -> IDENT LT IDENT\n");}
      | IDENT GT IDENT {printf("condition -> IDENT GT IDENT\n");}
      | IDENT LTE IDENT {printf("condition -> IDENT LTE IDENT\n");}
      | IDENT GTE IDENT {printf("condition -> IDENT GTE IDENT\n");}


void main(int arge, char ** argv) {
  if (arge >= 2) {
    yyin = fopen(argv[1], r);
    if (yyin B = NULL) {
      yyin = stdin;
    } else {
      yin - stdin;
    }
    yyparse();
  }
}
int yyerror() {}
