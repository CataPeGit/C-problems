#include "complex_number.h"
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

Complex::Complex() {
	this->real = 0;
	this->imag = 0;
}

Complex::Complex(float real, float img) {
	this->real = real;
	this->imag = img;
}

float Complex::getReal() const {
	return real;
}

float Complex::getImag() const {
	return imag;
}

void Complex::setReal(float real) {
	this->real = real; 
}


void Complex::setImag(float imag) {
	this->imag = imag;
}

Complex Complex::conjugate() const {
	return Complex(this->real ,-1 * this->imag);
}

Complex Complex::add(Complex a) const {
	a.real = a.real + this->real;
	a.imag = a.imag + this->imag;
	return a;
}

Complex Complex::subtract(Complex c) const {
	return Complex(this->real - c.real, this->imag - c.imag);
}

Complex Complex::multiply(Complex c) const {
	return Complex(this->real * c.real - this->imag * c.imag, this->real * c.imag + this->imag * c.real);
}


void Complex::multiply(float a) {
	this->real = a * this->real;
	this->imag = a * this->imag;
}

bool Complex::equals(Complex other) const {
	if (this->real == other.real && this->imag == other.imag)
		return 1;
	return 0;
}



float Complex::magnitude() {
	return sqrtf(this->real * this->real + this->imag * this->imag);
}


float Complex::phase() {
	float result = atan2(this->imag, this->real);
	
	return result;
}

void Complex::toPolar(float* r, float* theta) {
	*r = magnitude();
	*theta = phase();
	this->real = *r * cos(*theta);
	this->imag = *r * sin(*theta);
}




string Complex::toString() const {

	ostringstream sstr;
	sstr << std::setprecision(2) << std::fixed;
	

	if (this->real == 0 && this->imag == 0)
		return "0";
	else if (this->imag == 0) {
		sstr << this->real;
	}
	else if (this->real == 0) {
		sstr << this->imag;
		sstr << "i";
	}
	else {
		sstr << this->real;
		if (imag >= 0)
			sstr << "+";
		sstr << this->imag;
		sstr << "i";
	}


	string result = sstr.str();
	return result;
}




Complex Complex::operator*(const Complex& b) const {
	Complex mult(this->real * b.real - this->imag * b.imag, this->real * b.imag + this->imag * b.real);
	return mult;
}

Complex Complex::operator-(const Complex& b) const {
	Complex sum(real - b.real, imag - b.imag);
	return sum;
}


Complex operator+(const Complex& c1, const Complex& c2) {
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}


ostream& operator<<(std::ostream& out, const Complex& c) {
	out << c.real << " " << c.imag;
	return out;
}

istream& operator>>(std::istream& in, Complex& c) {
	in >> c.real >> c.imag;
	return in;
}
