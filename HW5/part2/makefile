all:result 
result:main.o Trace.o
	g++ -ggdb -o result main.o Trace.o
Complex.o:
	g++ -ggdb -c Trace.cpp
main.o:
	g++ -ggdb -c main.cpp
dep:
	g++ -ggdb -M main.cpp Trace.cpp > depend
clean:
	rm *.o result depend
