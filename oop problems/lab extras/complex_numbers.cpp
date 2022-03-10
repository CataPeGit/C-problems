
#include <math.h>
#include <stdio.h>

#include "complex_number.h"


void get_real(Complex c) {
	return c.real;
}

void get_imag(Complex c) {
	return c.imag;
}

void set_imag(Complex* c, float img) {
	c->img.imag;
}

void set_real(Complex* c, float r) {
	c->r.real;
}

Complex complex_conjugate(Complex c) {
	return c.real - c.imag;
}

Complex complex_conjugate(Complex c) {
	return c.real - c.imag;
}

Complex complex_add(Complex c1, Complex c2) {
	Complex result;
	result.real = c1.real + c2.real;
	result.imag = c1.imag + c2.imag;
	return result;
}

Complex complex_substract(Complex c1, Complex c2) {
	Complex result;
	result.real = c1.real - c2.real;
	result.imag = c1.imag - c2.imag;
	return result;
}

Complex complex_multiply(Complex c1, Complex c2) {
	Complex result;
	result.real = c1.real * c2.real;
	result.imag = c1.imag * c2.imag;
	return result;
}

void complex_scalar_mult(complex* c, float s) {
	c.real = s * c.real;
	c.real = s * c.real;
}

void ccomplex_equals(Complex c1, Complex c2) {
	if (c1.real == c2.real && c1.imag == c2.imag)
		return true;
	return false;
}

float complex_mag(Complex c) {
	return sqrt(c.real * c.real + c.imag * c.imag);
}

float complex_phase(Complex c) {

}
 
void complex_to_polar(Complex c, float* r, float* theta);


// folosim qsort(v, n, sizeof(Complex), compare_real);

int compare_real(const void* n1, const void* n2) {
	Complex* c1 = (Complex*)n1;
	Complex* c2 = (Complex*)n2;
	if (c1->real < c2->real) return -1;
	if (c1->real > c2->real) return 1;
	return 0;
}