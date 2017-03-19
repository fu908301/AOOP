all:main main2
cc=gcc 
CFLAGS=-g -Wall -ansi
main_obj=stack.o main.o
main2_obj=stack.o main2.o
main:$(main_obj)
		$(cc)-o$@ $(main_obj)
main2:$(main2_obj)
		$(cc)-o$@ $(main2_obj)
%.c:%.o
		$(cc)$(CFLAGS)-c-o$@ $<
clean:
		rm *.o main main2
