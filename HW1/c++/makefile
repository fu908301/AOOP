all: main main2

main: stack.o main.o
	g++ -ggdb -o main stack.o main.o

main2: stack.o main2.o
	g++ -ggdb -o main2 stack.o main2.o

stack.o: stack.cpp
	g++ -ggdb -c stack.cpp

main.o: main.cpp
	g++ -ggdb -c main.cpp

main2.o: main2.cpp
	g++ -ggdb -c main2.cpp

dep:
	echo "Do nothing"

clean:
	rm -f main main2 *.o

