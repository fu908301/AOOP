#ifndef __TYPE_H__
#define __TYPE_H__
#include "Word.h"

class Type : public Word{
	public : 
		int width = 0;
		Type(string s, int tag, int w);
		~Type();
		static bool numeric(Type & p);
		static Type max(Type & p1, Type & p2);
		friend bool operator == (const Type & t1, const Type & t2);
	private :
	/*Nothing to do here*/		
};

static const Type
	Int("int", Tag::BASIC, 4),
	Float("float", Tag::BASIC, 8),
	Char("char", Tag::BASIC, 1),
	Bool("bool", Tag::BASIC, 1);
bool operator == (const Type & t1, const Type & t2);
#endif
