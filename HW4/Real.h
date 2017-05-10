#ifndef __REAL_H__
#define __REAL_H__
#include "Token.h"
class Real : public Token{
	public :
		float value;
		Real(float v);
		~Real();
		string toString();
	private :
	/*Nothing to do here*/
};

#endif
