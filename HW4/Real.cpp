#include "Real.h"
#include "Tag.h"
#include <sstream>

Real::Real(float v) : Token(Tag::REAL){
	this -> value = v;
}

Real::~Real(){}

string Real::toString(){
	ostringstream ss;
	ss << this -> value;
	return "" + ss.str();
}
