#include "Word.h"

Word::Word(string s, int tag) : Token(tag){
	lexme = s;
}

Word::~Word(){}

string Word::toString(){
	return lexme;
}
