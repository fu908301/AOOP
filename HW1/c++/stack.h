#ifndef __STACK_H__
#define __STACK_H__

class Node{
private:
	int data;
	Node* next;

	friend class Stack;
};


class Stack{
public:
 	 Stack();
  	void push(int x);
  	int pop();
private: 
	Node* topptr;
};

#endif
