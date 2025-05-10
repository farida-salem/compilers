all:
	bison -d -v parser.y
	flex lexer.l
	gcc parser.tab.c lex.yy.c symbol_table.c quadruple.c -o compiler.exe -I. -lfl

clean:
	rm -f parser.tab.* lex.yy.* compiler.exe
