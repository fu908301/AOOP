all: main main2

main: stack.o main.o
	g++ -ggdb -o test1 stack.o main.o

main2: stack.o main2.o
	g++ -ggdb -o test2 stack.o main2.o

stack.o: stack.c
	g++ -ggdb -c stack.c

main.o: main.c
	g++ -ggdb -c main.c

main2.o: main2.c
	g++ -ggdb -c main2.c

dep:
	echo "Do nothing"

clean:
	rm -f main main2 *.o

