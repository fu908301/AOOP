#include "Lexer.h"
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <sstream>
using namespace std;

Lexer::Lexer(){
	line = 1;
	reserve(Word("if", Tag::IF));
	reserve(Word("else", Tag::ELSE));
	reserve(Word("while", Tag::WHILE));
	reserve(Word("do", Tag::DO));
	reserve(Word("break", Tag::BREAK));
	reserve(True);
	reserve(False);
	reserve(Int);
	reserve(Char);
	reserve(Bool);
	reserve(Float);
}

Lexer::~Lexer(){}

void Lexer::reserve(Word w){
	words.insert({w.lexme, w});
}

void Lexer::readch(){
	char c;
	if(cin.get(c))
		peek = c;
	else{
		cout << "End of file reached!" << endl;
		this -> end_of_file = true;
	}
}

bool Lexer::readch(char c){
	readch();
	if(peek != c)
		return false;
	peek = ' ';
	return true; 
}

Token Lexer::scan(){
	for( ; ; readch()){
		if(this -> end_of_file)
			return Token(' ');
		if(peek == ' ' || peek == '\t')
			continue;
		else if(peek == '\n')
			line++;
		else 
			break;
	}	
	switch(peek){
		case '&' :
			if(readch('&')){
				cout << "Token: " << left << setw( 10 ) << "&&";
				return AND;
			}
			else{
				cout << "Token: " << left << setw( 10 ) << "&";
				return Token('&');
			}
			break;
		case '|' :
			if(readch('|')){
				cout << "Token: " << left << setw( 10 ) << "||";
				return OR;
			}
			else{
				cout << "Token: " << left << setw( 10 ) << "|"; 
				return Token('|');
			}
			break;
		case '=' :
			if(readch('=')){
				cout << "Token: " << left << setw( 10 ) << "==";
				return EQ;
			}
			else {
				cout << "Token: " << left << setw( 10 ) << "=";
				return Token('=');
			}
			break;
		case '!' :
			if(readch('=')){
				cout << "Token: " << left << setw( 10 ) << "!=";
				return NE;
			}
			else {
				cout << "Token: " << left << setw( 10 ) << "!";
				return Token('!');
			}
			break;
		case '<' :
			if(readch('=')){
				cout << "Token: " << left << setw( 10 ) << "<=";
				return LE;
			}
			else{
				cout << "Token: " << left << setw( 10 ) << "<"; 
				return Token('<');
			}
			break;
		case '>' :
			if(readch('=')){
				cout << "Token: " << left << setw( 10 ) << ">=";
				return GE;
			}
			else{
				cout << "Token: " << left << setw( 10 ) << ">"; 
				return Token('>');
			}
			break;
	}
	
	if(isdigit(peek)){
		int v = 0;
		do{
			v = 10 * v + (peek - '0');
			readch();
		}while(isdigit(peek));
		cout << "Token: " << left << setw(10) << v;
		if(peek != '.')
			return Num(v);
		float x = v;
		float d = 10;
		for(;;){
			readch();
			if(!isdigit(peek))
				break;
			x = x + (peek - '0') / d;
			d = d * 10; 
		}
		cout << "Token: " << left << setw( 10 ) << x;
		return Real(x);
	}
	if(isalpha(peek)){
		stringstream ss;
		do{
			ss << peek;
			readch();
		}

		while(isdigit(peek) || isalpha(peek));
		string s = ss.str();
		map<string, Word>::iterator it = words.find(s);
		if(it != words.end()){
			cout << "Token: " << left << setw( 10 ) << s;
			return it -> second;
		}
		Word w(s, Tag::ID);
		words.insert({s, w});
		cout << "Token: " << left << setw( 10 ) << s;
		return w;
	}
	
	Token tok(peek);
	
  cout << "Token: " << left << setw( 10 ) << peek;
	peek = ' ';
	return tok; 
}
