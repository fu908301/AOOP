#include "stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;


Stack::Stack()
{
	topptr = NULL;
}

void Stack::push(int x)
{
	Node* newspace = (Node*)malloc(sizeof(Node));
	newspace -> data = x;
	newspace -> next = topptr;
	topptr = newspace;
}


int Stack::pop()
{
	Node *temp = topptr;
	if(temp == NULL)
	{
		cout<<"Stack is empty"<<endl;
		return -1;
	}
	int return_data = temp -> data;
	topptr = topptr -> next;
	free(temp);
	return return_data;
}
