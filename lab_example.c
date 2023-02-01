//This is just an example from the lab section
//Please change it accordingly to fit our own language 

%{
#include <stdio.h>
%}

%start prog_start
%token INT SMICOLON IDENT LB RBR COMMA LPR RPR

%%

prog start: /* epsilon */ {printf("prog_ start-›epsilon \n");}
      | functions {printf("prog_start -> functions \n");}
        
        
functions: function {printf("functions -› function \n");}
      | function functions {printf("functions -> function functions \n");}

                           
function: INT IDENT LP arguments RPR LBR statements RBR {printf("function -> INT IDENT LP arguments PR LBR statements");}


arguments: argument {printf("arguments -> Asgumnet \n");)
      | COMMA arguments {printf("arguments -> COMMA arguments \n");}


argument: /* epsilon */ {printf("argument -> epsilon \n");}
      | INT IDENT {printf("argument -> INT IDENT \n");)

        
statements: /* epsilon */ {printf("statements -> epsilon \n");}
      | statement SMICOLON statements {printf("statements -> statement SMICOLON statements \n");} //CW
      | statement {printf("Smicolon is missing! \n");} //CW


statement: /* epsilon */ {printf("statement -> epsilon \n");} //CW
       | statement {printf("Smicolon is missing! \n");} //CW


void main(int arge, char ** argv) {
  /*
      If(arge >= 2) {

          yyin = fopen(argv[1], "r);

            if (yyin B = NULL)

              yyin = stdin;

            felse {
              yin - stdin;
            ] */
  yyparse();
}
int yyerror() {}
