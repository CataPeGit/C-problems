#pragma once
#include <string>
#include <fstream>

class Complex {

public:
    Complex();
    Complex(float real, float imag);

    float getReal() const;
    float getImag() const;

    void setReal(float real);
    void setImag(float i);

    Complex conjugate() const;
    Complex add(Complex a) const;
    Complex subtract(Complex c) const;
    Complex multiply(Complex c) const;

    void multiply(float a);

    bool equals(Complex other) const;

    float magnitude();
    float phase();
    void toPolar(float* r, float* theta);

    std::string toString() const;

    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;

    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend std::istream& operator>>(std::istream& in, Complex& c);
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);


private:
    float real;
    float imag;

};
