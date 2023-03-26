//=================================================
// K M Asif
// March 2023
// Complex.h
// This file contains the class declaration for the
// Complex number class.
// *** Students should not change this file ever ***
//=================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef COMPLEX
#define COMPLEX

class Complex
{
public:
	Complex(void);
	Complex(float a, float b);
	Complex(const Complex &c);
	string to_string(void) const;
	Complex add(const Complex c) const;
	Complex add(float a) const;
	// Complex add(int a) const;
	float abs(void) const;
	void setReal(float a);
	float getReal(void) const;
	void setImag(float b);
	float getImag(void) const;
	void makeCopy(const Complex c);

private:
	float real; // real part
	float imag; // imaginary part
};

#endif

// Imaginary Number --> i = sqrt(-1) OR i^2 = -1
// i^3 = -i and i^4 = 1
//

// Desired Outputs

// c1 = 0.000+0.000i
// c2 = 3.000+0.000i
// c3 = 3.000+0.000i
// c4 = -4.500-3.124i
// c4 = c2+c3 = 6.000+0.000i
// c4 = c2+4.5 = 7.500+0.000i
// c4 = c2+4 = 7.000+0.000i
// abs(c7) = 5.000
// c5 = 3.000+2.000i
// c6 = 7.000+0.000i