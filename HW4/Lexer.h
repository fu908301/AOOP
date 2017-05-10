#ifndef __LEXER_H__
#define __LEXER_H__

#include "Tag.h"
#include "Token.h"
#include "Word.h"
#include "Type.h"
#include "Num.h"
#include "Real.h"
#include <map>

class Lexer{
	public :
	    int line;
		~Lexer();
		Lexer();
		Token scan();
		char peek = ' ';
		map <string, Word> words;
		void reserve(Word w);
		void readch();
		bool readch(char c);
		bool end_of_file = false;
	private :
};

#endif
