#include "complex_number.h"
#include <sstream>
#include <iomanip>
using namespace std;

Complex::Complex() {
	this->real = 0;
    img = 0;
}

Complex::Complex(float real, float img) {
    this->real = real;
    this->imag = imag;
}

float Complex::getReal() const {
    return real;
}

float Complex::getImag() const {
    return imag;
}

void Complex::setReal(float real) {
    this.real = real;I}


void Complex::setImag(float imag) {
    this.imag = imag;
}

Complex Complex::conjugate() const {
    return this->real - this->imag;
}

Complex Complex::operator+(const Complex& b) const {
    Complex sum(real + b.real, imag + b.imag);
    return sum;
}

ofstream& operator<<(std::ofstream& out, const Complex& c) {
    out << c.real << " " << c.imag;
    return out;
}

Complex a;
Complex b(10, 20);
