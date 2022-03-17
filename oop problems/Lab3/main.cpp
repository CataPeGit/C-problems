#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include "complex_test.h"


int compareTo(Complex* first, Complex* second) {
	int* a = (int*)first;
	int* b = (int*)second;
	if (*a > *b) {
		return +1;
	}
	else if (*b > *a) {
		return -1;
	}
	else {
		return 0;
	}
}


int main(int argc, char** argv) {

	run_complex_tests(true);

	// TODO your code here
	
	float real;
	float imag;

	printf("Please add the real and imaginary part of the complex number: ");
	printf("\nReal: ");
	scanf("%f", &real);
	printf("Imaginary: ");
	scanf("%f", &imag);

	//real = 1; imag = 1;

	// Variable of Complex type such that it is stored on the stack
	Complex test_stack = complex_create(real, imag);
	
	float r = complex_mag(test_stack);
	printf("\nMagnitude: %f", r);

	float theta = complex_phase(test_stack);
	printf("\nPhase: %f", theta);

	Complex polar = test_stack;
	complex_to_polar(polar, &r, &theta);
	printf("\nPolar coordinates: (%f,%f)", polar.real, polar.imag);


	Complex conjugate =  complex_conjugate(test_stack);
	printf("\nConjugate: %f%f", conjugate.real, conjugate.imag);

	float scalar = 2; 
	complex_scalar_mult(&test_stack, scalar);
	printf("\nAfter multiplying with a scalar (=2) we get: real = %f, imaginary = %f\n", test_stack.real, test_stack.imag);
	


	// Variable of Complex type such that it is stored on the heap

	Complex* test_heap = new Complex(complex_create(real, imag));

	float r_heap = complex_mag(*test_heap);
	printf("\nMagnitude: %f", r);
	

	float theta_heap = complex_phase(*test_heap);
	printf("\nPhase: %f", theta);

	complex_to_polar(*test_heap, &r_heap, &theta_heap);
	printf("\nPolar coordinates: (%f,%f)", test_heap->real, test_heap->imag);


	Complex* conjugate_heap = new Complex(complex_conjugate(*test_heap));
	printf("\nConjugate: %f%f", conjugate_heap->real, conjugate_heap->imag);

	complex_scalar_mult(test_heap, scalar);
	printf("\nAfter multiplying with a scalar (=2) we get: real = %f, imaginary = %f\n", test_heap->real, test_heap-> imag);
	printf("\n");


	complex_add(test_stack, *test_heap);
	complex_subtract(test_stack, *test_heap);
	complex_multiply(test_stack, *test_heap);

	// Create a dynamic array of complex numbers and populate it with the data stored in a text file
	
	

	ifstream read_file;
	read_file.open("D:/facultateoop/Laboratory3/in2.txt"); // make sure the proper path is given
	if (!read_file.is_open()) {
		printf("File could not be opened.");
		return 0;
	}
	

	int count_of_complex_numbers;
	read_file >> count_of_complex_numbers;

	Complex* text_file_data_array;
	text_file_data_array = new Complex[count_of_complex_numbers/2];

	for (int i = 0; i < count_of_complex_numbers / 2; i++) {
		float real_part, imag_part;
		read_file >> real_part >>imag_part;
		text_file_data_array[i] = complex_create(real_part, imag_part);
	}
	printf("\n");
	printf("Dynamic array of complex numbers and populate it with the data stores in a text file:");
	printf("\n");
	for (int i = 0; i < count_of_complex_numbers / 2; i++) {
		printf("%d : ", i+1);
		complex_display(text_file_data_array[i]);
		printf("\n");
	}
	// display the array of numbers in ascending order

	//void qsort(void* text_file_data_array, size_t nitems, size_t size, int (*compar)(const void*, const void*));

	//qsort(text_file_data_array, )

	qsort(text_file_data_array, count_of_complex_numbers , sizeof(float), compare_real);

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("After using Qsort on array: ");
	printf("\n");
	for (int i = 0; i < count_of_complex_numbers / 2; i++) {
		printf("%d : ", i+1);
		complex_display(text_file_data_array[i]);
		printf("\n");
	}

	delete test_heap;
	delete conjugate_heap;
	read_file.close();
	return 0;
}

