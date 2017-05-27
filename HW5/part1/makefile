all:result 
result:main.o Form.o 
	g++ -std=c++11 -ggdb -o result main.o
main.o:
	g++ -std=c++11 -ggdb -c main.cpp
Form.o:
	g++ -std=c++11 -ggdb -c Form.cpp
dep:
	g++ -std=c++11 -ggdb -M main.cpp Form.cpp  > depend
clean:
	rm *.o result depend 
