#include "Token.h"

Token::Token(int t){
	this -> tag = t;
}

Token::~Token(){}

string Token::toString(){
	if(tag < 256 || tag > 275){
		return "(" + string(1, (char)tag) + ")";
	}
	string tokens[20] = 
	{
		"AND",
		"BASIC",
		"BREAK",
		"DO",
		"ELSE",
		"EQ",
		"FALSE",
		"GE",
		"ID",
		"IF",
		"INDEX",
		"LE",
		"MINUS",
		"NE",
		"NUM",
		"OR",
		"REAL",
		"TEMP",
		"TRUE",
		"WHILE",
	};
	return "(" + tokens[tag - 256] + ")";
}
