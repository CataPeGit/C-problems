#pragma once
#include <string>
#include <fstream>

class Complex{

public:
    Complex();
    Complex(float real, float imag);
    
    float getReal() const;
    float getImag() const;
    
    float setReal(float real);
    float setReal(float i);
    
    Complex conjugate();
    
    Complex operator+(const Complex& b) const;
    
    
private:
    float real;
    float imag;

}