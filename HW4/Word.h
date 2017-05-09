#ifndef __WORD_H__
#define __WORD_H__
#include "Token.h"
#include "Tag.h"

class Word : public Token{
	public :
		string lexme = "";
		Word(string s, int tag);
		~Word(); 
		string toString();
	private:
	/*Nothing to do here*/
};
static const Word
	AND("&&", Tag::AND),
	OR("||", Tag::OR),
	EQ("==", Tag::EQ),
	NE("!=", Tag::EQ),
	LE("<=", Tag::LE),
	GE(">=", Tag::GE),
	Minus("minus", Tag::MINUS),
	True("true", Tag::TRUE),
	False("false", Tag::FALSE),
	Temp("t", Tag::TEMP);

#endif
