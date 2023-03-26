//=================================================
// Ethan Tecson
// 2023 March 26
// Complex.cpp
// This file contains the class implementation for the
// Complex number class.
//=================================================

#include "Complex.h"
#include <iomanip>
#include <math.h>

/********************Constructors*****************/

//=================================================
// default constructor
// PARAMETERS:
// none
// Creates a complex variable with value 0+0i
//=================================================

Complex::Complex(void)
{
	real = 0;
	imag = 0;
}

//=================================================
// constructor defined with two floating points
// PARAMETERS:
// two float values
// Creates a Complex instance with value 0.00+0.00i
//=================================================

Complex::Complex(float a, float b)
{
	real = a;
	imag = b;
}

//=================================================
// constructor defined with another instance
// PARAMETERS:
// A complex instance
// Creates a complex instance with another Complex instances' values
//=================================================

Complex::Complex(const Complex &c)
{
	real = c.real;
	imag = c.imag;
}

/********************Functions*****************/

//=================================================
// to_string
// PARAMETERS:
// none
// RETURN VALUE:
// a string containing "a+bi" where a and b are
// the real and complex parts of the number.  Both
// a and b will be with fixed decimal length up to
// two places.
//=================================================

string Complex::to_string(void) const
{
	stringstream stream;
	stream << fixed << setprecision(3) << real;
	if (imag >= 0)
		stream << "+" << fixed << setprecision(3) << imag << "i";
	else
		stream << "-" << fixed << setprecision(3) << fabs(imag) << "i";

	return stream.str();
}

//=================================================
// add (instnace)
// PARAMETERS:
// Complex class instance
// RETURN VALUE:
// Sum of two instances
//=================================================

Complex Complex::add(const Complex c) const
{
	float real_part = real + c.real;
	float imag_part = imag + c.imag;

	Complex sum(real_part, imag_part);

	return sum;
}

//=================================================
// add (float)
// PARAMETERS:
// Float number
// RETURN VALUE:
// Sum of instance and given float value
//=================================================

Complex Complex::add(float a) const
{
	float real_float = a + real;
	float imag_float = imag;

	Complex float_sum(real_float, imag_float);

	return float_sum;
}

//=================================================
// abs
// PARAMETERS:
// none
// RETURN VALUE:
// Absolute value of instance
//=================================================

float Complex::abs(void) const
{
	float abs_real = pow(real, 2);
	float abs_imag = pow(imag, 2);
	float sum = abs_real + abs_imag;
	float answer = sqrt(sum);

	return answer;
}

//=================================================
// setReal
// PARAMETERS:
// float value
// RETURN VALUE:
// real number value
//=================================================

void Complex::setReal(float a)
{
	real += a;
}

//=================================================
// getReal
// PARAMETERS:
// none
// RETURN VALUE:
// prints real number
//=================================================

float Complex::getReal(void) const
{
	return real;
}

//=================================================
// setImag
// PARAMETERS:
// float value
// RETURN VALUE:
// real imaginary value
//=================================================

void Complex::setImag(float b)
{
	imag += b;
}

//=================================================
// getImag
// PARAMETERS:
// none
// RETURN VALUE:
// prints imaginary number
//=================================================

float Complex::getImag(void) const
{
	return imag;
}

//=================================================
// makeCopy
// PARAMETERS:
// instance of complex numbers
// RETURN VALUE:
// Copies value of one instance to another
//=================================================

void Complex::makeCopy(const Complex c)
{
	real = c.real;
	imag = c.imag;
}