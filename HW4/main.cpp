#include <iostream>
#include "Lexer.h"
using namespace std;
int main(){
	Lexer lex;
	while(true){
		Token t =  lex.scan();
		if(lex.end_of_file)
			break;
		cout << t.toString() << endl;
	}
	return 0;
}
