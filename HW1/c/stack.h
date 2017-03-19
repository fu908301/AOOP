#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 100

typedef struct node {			
	int data;
	struct node *next;
}NODE,*NODEPTR;

struct stack
{
	NODEPTR topptr;
};
extern void push(struct stack* this,int input);  
extern int pop(struct stack* this);
extern struct stack* new_stack();
extern void delete_stack(struct stack* stk);

#endif



