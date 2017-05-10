#include "Num.h"
#include "Tag.h"

using namespace std;

Num::Num(int v) : Token(Tag::NUM){
	value = v;
}

Num::~Num(){}

string Num::toString(){
	ostringstream ss;
	ss << this -> value;
	return "" + ss.str();
}
