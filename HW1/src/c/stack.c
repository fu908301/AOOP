#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(struct stack* this,int input)
{
	NODEPTR new_space = (NODEPTR)malloc(sizeof(NODE));
	new_space -> data = input;
	new_space -> next = this -> topptr;
	this -> topptr = new_space;
}

int pop(struct stack* this)
{
	int pop_data;
	NODEPTR temp = malloc(sizeof(NODE));
	temp = this -> topptr;
	if(temp == NULL)
	{
		printf("Stack is empty!\n");
		return -1;
	}
	pop_data = temp -> data;
	this ->topptr = this -> topptr -> next;
	free(temp);	

	return pop_data;
}

struct stack* new_stack()
{
	struct stack* new_space;
	new_space = malloc(sizeof(struct stack));
	new_space -> topptr = NULL;
	return new_space;
}

void delete_stack(struct stack* stk)
{
	free(stk);
}
