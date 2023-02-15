all:

	bison -v -d --file-prefix=y ppC.y
	flex lexer.lex
	gcc -o parser y.tab.c lex.yy.c -lfl
	
clean:

	rm -f lexer lex.yy.c
