#pragma once
#include<string>
#include<iostream>

using std::string;
using std::max;

class BigInteger {

public:
	BigInteger();
	BigInteger(string str);
	BigInteger(int* _digits, int _num_digits, int _sign);

	~BigInteger();

	BigInteger& operator=(const BigInteger N);

	int compare(const BigInteger N) const;

	int get_num_digits() const;
	int get_sign() const;
	int* get_digits_array() const;
	int get_digit(int pos) const;

	friend bool operator==(const BigInteger& A, const BigInteger& B);
	friend bool operator<(const BigInteger& A, const BigInteger& B);
	friend bool operator>(const BigInteger& A, const BigInteger& B);
	friend bool operator<=(const BigInteger& A, const BigInteger& B);
	friend bool operator>=(const BigInteger& A, const BigInteger& B);

	friend BigInteger operator+(const BigInteger& A, const BigInteger& B);
	friend BigInteger operator-(const BigInteger& A, const BigInteger& B);

	//BigInteger sub(const BigInteger& N) const;
	/*
	int* prepend_zeros(int* arr, int arr_sz, int new_sz);
	int* negate(int* arr, int arr_sz);
	int* add(int* arr1, int* arr2, int arr_sz);
	int* digitize(int* arr, int arr_sz);	
	*/

	BigInteger add(const BigInteger& N) const;
	//BigInteger sub(const BigInteger& N) const;

private:
	int* digits;
	int num_digits;
	int sign; // 1 -> >0 ; 0 == 0; -1 -> <0


	

	//BigInteger sub(const BigInteger& N) const;

};
