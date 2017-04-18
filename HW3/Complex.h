#ifndef __complex_h_included__
#define __complex_h_included__

#include <iostream>

using std::ostream;

class Complex {
public:
    Complex(const double re = 0, const double im = 0);
    Complex(const Complex& c);
    Complex& operator=(const Complex& c);

    Complex Polar(const double leng, const double arg);

    double Real();
    double Imag();
    double Norm();
    double Abs();
    double Arg();

    Complex operator++();
    Complex operator++(int);
    Complex operator--();
    Complex operator--(int);

    ~Complex();

    friend Complex Polar(const double leng, const double arg);
    friend double Norm(const Complex& x);
    friend double Abs(const Complex& x);
    friend double Arg(const Complex& x);
    friend Complex operator+(const Complex& x, const Complex& y);
    friend Complex operator-(const Complex& x, const Complex& y);
    friend Complex operator*(const Complex& x, const Complex& y);
    friend Complex operator/(const Complex& x, const Complex& y);
    friend Complex operator+=(Complex& x, const Complex& y);
    friend Complex operator-=(Complex& x, const Complex& y);
    friend Complex operator*=(Complex& x, const Complex& y);
    friend Complex operator/=(Complex& x, const Complex& y);
    friend bool operator==(const Complex& x, const Complex& y);
    friend bool operator!=(const Complex& x, const Complex& y);
    friend ostream& operator<<(ostream& o, const Complex& x);

private:
    double real;
    double imag;
};

Complex Polar(const double leng, const double arg);
double Norm(const Complex& x);
double Abs(const Complex& x);
double Arg(const Complex& x);
Complex operator+(const Complex& x, const Complex& y);
Complex operator-(const Complex& x, const Complex& y);
Complex operator*(const Complex& x, const Complex& y);
Complex operator/(const Complex& x, const Complex& y);
Complex operator+=(Complex& x, const Complex& y);
Complex operator-=(Complex& x, const Complex& y);
Complex operator*=(Complex& x, const Complex& y);
Complex operator/=(Complex& x, const Complex& y);
bool operator==(const Complex& x, const Complex& y);
bool operator!=(const Complex& x, const Complex& y);
ostream& operator<<(ostream& o, const Complex& x);
#endif
