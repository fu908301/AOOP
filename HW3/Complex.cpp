#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

Complex::Complex(const double re, const double im)
{
	this -> real = re;
	this -> imag = im;
}

Complex::Complex(const Complex& c)
{
	this -> real = c.real;
	this -> imag = c.imag;
}

Complex &Complex::operator=(const Complex& c)
{
	this -> real = c.real;
	this -> imag = c.imag;
	return *this;
}

Complex Complex::Polar(const double leng, const double arg)
{
	this -> real = leng * cos(arg);
	this -> imag = leng * sin(arg);
	return *this;
}

double Complex::Real()
{
	return this -> real;
}

double Complex::Imag()
{
	return this -> imag;
}

double Complex::Norm()
{
	return pow(this -> real,2) + pow(this -> imag,2);
}

double Complex::Abs()
{
	return sqrt(pow(this -> real,2) + pow(this -> imag,2));
}

double Complex::Arg()
{
	return acos(this -> real / (sqrt(this->Norm())));
}

Complex Complex::operator++()
{
	this -> real++;
	this -> imag++;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex tmp(*this);
	operator++();
	return tmp;
}

Complex Complex::operator--()
{
	this -> real--;
	this -> imag--;
	return *this;
}

Complex Complex::operator--(int)
{
	Complex tmp(*this);
	operator--();
	return tmp;
}

Complex::~Complex(){}

Complex Polar(const double leng, const double arg)
{
	double real = leng * cos(arg);
	double imag = leng * sin(arg);
	return Complex(real,imag);
}

double Norm(const Complex& x)
{
	double norm = pow(x.real,2) + pow(x.imag,2);
	return norm;
}

double Abs(const Complex &x)
{
	double abs = sqrt(pow(x.real,2) + pow(x.imag,2));
	return abs;
}

double Arg(const Complex &x)
{
	double arg = acos(x.real / (sqrt(Norm(x))));
	return arg;
}

Complex operator+(const Complex& x, const Complex& y)
{
	double real = x.real + y.real;
	double imag = x.imag + y.imag;
	return Complex(real,imag);
}

Complex operator-(const Complex& x, const Complex& y)
{
	double real = x.real - y.real;
	double imag = x.imag - y.imag;
	return Complex(real,imag);
}

Complex operator*(const Complex& x, const Complex& y)
{
	double real = x.real * y.real - x.imag * y.imag;
	double imag = x.real * y.imag + y.real * x.imag;
	return Complex(real,imag);
}

Complex operator/(const Complex& x, const Complex& y)
{
	double real = (x.real * y.real + x.imag * y.imag) / Norm(y);
	double imag = (x.imag * y.real - x.real * y.imag) / Norm(y);
	return Complex(real,imag);
}

Complex operator+=(Complex& x, const Complex& y)
{
	x = x + y;
	return x;
}

Complex operator-=(Complex& x, const Complex& y)
{
	x = x - y;
	return x;
}

Complex operator *=(Complex& x, const Complex& y)
{
	x = x * y;
	return x;
}

Complex operator /=(Complex& x, const Complex& y)
{
	x = x / y;
	return x;
}

bool operator==(const Complex& x, const Complex& y)
{
	if(x.real == y.real && x.imag == y.imag)
		return true;
	else 
		return false;
}

bool operator!=(const Complex& x, const Complex& y)
{
	if(x.real != y.real || x.imag != y.imag)
		return true;
	else 
		return false;
}

ostream& operator<<(ostream& o, const Complex& x)
{
	o<< "(" << x.real << "," << x.imag << ")";
	return o;
}
