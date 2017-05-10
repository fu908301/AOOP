all:lex 
lex:main.o Lexer.o Num.o Real.o Tag.o Token.o Word.o Type.o
	g++ -std=c++11 -ggdb -o lex main.o Lexer.o Num.o Real.o Tag.o Token.o Word.o Type.o
Lexer.o:
	g++ -std=c++11 -ggdb -c Lexer.cpp
main.o:
	g++ -std=c++11 -ggdb -c main.cpp
Num.o:
	g++ -std=c++11 -ggdb -c Num.cpp
Real.o:
	g++ -std=c++11 -ggdb -c Real.cpp
Tag.o:
	g++ -std=c++11 -ggdb -c Tag.cpp
Token.o:
	g++ -std=c++11 -ggdb -c Token.cpp
Word.o:
	g++ -std=c++11 -ggdb -c Word.cpp
Type.o:
	g++ -std=c++11 -ggdb -c Type.cpp
run1:
	./lex < test1 > result
run2:
	./lex < test2 > result
dep:
	g++ -std=c++11 -ggdb -M main.cpp Lexer.cpp Num.cpp Real.cpp Tag.cpp Token.cpp Word.cpp Type.cpp > depend
clean:
	rm *.o result depend lex
