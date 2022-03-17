#include <math.h>
#include <stdio.h>
#include <math.h>       

#include "complex_number.h"

#define PI 3.14159265


Complex complex_create(float real, float imag) {
	Complex c;
	c.real = real;
	c.imag = imag;
	return c;
}


float get_real(Complex c) {
	return c.real;
}

float get_imag(Complex c) {
	return c.imag;
}

void set_imag(Complex* c, float img) {
	c->imag = img;
}

void set_real(Complex* c, float r) {
	c->real = r;
}

Complex complex_conjugate(Complex c) {
	Complex result;
	result.real = c.real;
	result.imag = -1 * c.imag;
	return result;
}


Complex complex_add(Complex c1, Complex c2) {
	Complex result = complex_create(c1.real + c2.real, c1.imag + c2.imag);
	return result;
}


Complex complex_subtract(Complex c1, Complex c2) {
	Complex result = complex_create(c1.real - c2.real, c1.imag - c2.imag);
	return result;
}

Complex complex_multiply(Complex c1, Complex c2) {
	
	float result_real = c1.real * c2.real - c1.imag * c2.imag;
	float result_imag = c1.real * c2.imag + c1.imag * c2.real;

	return complex_create(result_real, result_imag);
}

void complex_scalar_mult(Complex* c, float s) {
	c->real = s * c->real;
	c->imag = s * c->imag;
}

bool complex_equals(Complex c1, Complex c2) {
	if (c1.real == c2.real && c1.imag == c2.imag)
		return 1;
	return 0;
}

float complex_mag(Complex c) {
	return sqrt(c.real * c.real + c.imag * c.imag);
}

float complex_phase(Complex c) {
	float result = atan2(c.imag, c.real);
	return result;
}
 
void complex_to_polar(Complex c, float* r, float* theta) {
	*r = complex_mag(c);
	*theta = complex_phase(c);
	float x = *r * cos(*theta);
	float y = *r * sin(*theta);
	c.real = x;
	c.imag = y;
}

void complex_display(Complex c) {
	printf("%f+(%f)*i", c.real, c.imag);
}


// folosim qsort(v, n, sizeof(Complex), compare_real);


int compare_real(const void* n1, const void* n2) {
	Complex* c1 = (Complex*)n1;
	Complex* c2 = (Complex*)n2;
	if (c1->real < c2->real) return -1;
	if (c1->real > c2->real) return 1;
	return 0;
}


