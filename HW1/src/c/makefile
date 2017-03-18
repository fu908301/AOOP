all:main
cc=gcc 
CFLAGS=-g -Wall -ansi
stack_obj=stack.o main.o
main:$(stack_obj)
		$(cc)-o$@ $(stack_obj)
%.c:%.o
		$(cc)$(CFLAGS)-c-o$@ $<
clean:
		rm *.o
