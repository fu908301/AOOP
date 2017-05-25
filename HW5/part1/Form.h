#ifndef __FORM_H__
#define __FORM_H__
#include <iostream>
#include <sstream>
using namespace std;
class Bound_form;

class Form{
	public :
		friend ostream& operator<< (ostream &, const Bound_form &);
		int prc;
		int wdt;
		int fmt;
		explicit Form(int p = 6) : prc(p){
			fmt = 0;
			wdt = 0;
		}
		Bound_form operator() (double d);
		Form & scientific(){fmt = ios_base::scientific; return *this;}
		Form & fixed(){fmt = ios_base::fixed; return *this;}
		Form & general(){fmt = 0; return *this;}
		Form & precision(int p){prc = p; return *this;}
		Form & width(int w){wdt = w; return * this;}
};
struct Bound_form{
	const Form& f;
	double val;
	Bound_form(const Form& ff, double v) : f(ff), val(v){}
};

Bound_form Form::operator() (double d) {return Bound_form{*this,d};}
ostream & operator << (ostream& os, const Bound_form& bf){
	ostringstream s;
	s.precision(bf.f.prc);
	s.setf((ios_base::fmtflags)bf.f.fmt, ios_base::floatfield);
	s << bf.val;
	return os << s.str();
}
#endif
