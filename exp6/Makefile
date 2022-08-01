parser: sysy.tab.c ast.c lex.yy.c
	gcc sysy.tab.c ast.c lex.yy.c -o parser
sysy.tab.c: sysy.y
	bison -d -v sysy.y
lex.yy.c: sysy.l
	flex sysy.l