#ifndef __STACK_H__
#define __STACK_H__

class Stack
{
  	enum { STACK_SIZE = 200 };

  	int stk[STACK_SIZE];
  	int sp;
public:
 	 Stack()
  	{
    	sp = -1;
  	}
  	void push( int x )
  	{
    	stk[++sp] = x;
  	}
  	int pop()
  	{
    	return stk[sp--];
  	}
};

#endif
