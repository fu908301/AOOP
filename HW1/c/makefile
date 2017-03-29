all:main main2
main:main.o stack.o
	gcc -ggdb -o main main.o stack.o
main2:main2.o stack.o
	gcc -ggdb -o main2 main2.o stack.o
stack.o:
	gcc -ggdb -c stack.c
main.o:
	gcc -ggdb -c main.c
main2.o:
	gcc -ggdb -c main2.c
dep:
	gcc -ggdb -M main.c main2.c stack.c > depend
clean:
		rm *.o main main2 depend
