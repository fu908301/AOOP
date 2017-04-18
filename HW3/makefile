all:result 
result:main.o Complex.o
	g++ -ggdb -o result main.o Complex.o
Complex.o:
	g++ -ggdb -c Complex.cpp
main.o:
	g++ -ggdb -c main.cpp
dep:
	g++ -ggdb -M main.cpp Complex.cpp > depend
clean:
		rm *.o result depend
