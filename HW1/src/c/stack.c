#include <stdlib.h>
#include "stack.h"

void push(struct stack* this,int input)
{
	this->stk[++this->sp] = input;
}

int pop(struct stack* this)
{
	return this->stk[this->sp--];
}

struct stack* new_stack()
{
	struct stack* stk = malloc(sizeof(struct stack));
	stk->sp = -1;
	return stk;
}

void delete_stack(struct stack* stk)
{
	free(stk);
}
