#include "Token.h"

Token::Token(int t){
	this -> tag = t;
}

Token::~Token(){}

string Token::toString(){
	char c = tag;
	return "" + c;
}
