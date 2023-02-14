all:
	flex lexer.lex
	bison -v -d --file-prefix=y ppC.y
	gcc -o lexer lex.yy.c -lfl
	
clean:
	rm -f lexer lex.yy.c
