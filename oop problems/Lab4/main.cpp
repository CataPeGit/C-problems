#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "complex_test.h"


int main(int argc, char** argv) {
	
#if ENABLE_TESTS > 0
	run_complex_tests(true);
#endif
	// TODO your code here

	Complex c{ 4, -3 };
	Complex c2{ 1, 1 };
	Complex c2_equal{ 1, 1 };
	//cout <<
	c.getReal();
	c.getImag();
	c.setImag(3);
	c.setReal(-4);

	c.conjugate();
	c.add(c2);
	c.subtract(c2);
	c.multiply(c2);

	float f = 3;
	c.multiply(f);

	c2.equals(c2_equal);

	c.magnitude();
	c.phase();
	float r, y;
	c.toPolar(&r, &y);

	c.toString();
	
	return 0;
}
