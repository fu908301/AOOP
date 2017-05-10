#ifndef __NUM_H__
#define __NUM_H__
#include "Token.h"
#include <sstream>
class Num : public Token{
	public : 
		int value;
		Num(int v);
		~Num();
		string toString();
	private:
		/*Nothing to do here*/
};

#endif
