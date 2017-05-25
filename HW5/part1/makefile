all:result 
result:main.o 
	g++ -std=c++11 -ggdb -o result main.o
main.o:
	g++ -std=c++11 -ggdb -c main.cpp
dep:
	g++ -std=c++11 -ggdb -M main.cpp  > depend
clean:
	rm *.o result depend 
