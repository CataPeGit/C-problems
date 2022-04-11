#pragma once
#include<string>
#include<iostream>


class BigInteger {

public:
	BigInteger();
	//BigInteger(string* str);

	~BigInteger();

	int compare(const BigInteger N) const;

	int operator==(const BigInteger N) const;
	int operator<(const BigInteger N) const;
	int operator>(const BigInteger N) const;
	int operator<=(const BigInteger N) const;
	int operator>=(const BigInteger N) const;

	char* prepend_zeros(char* arr, int arr_sz, int new_sz);

	//BigInteger add(const BigInteger& N) const;
	//BigInteger sub(const BigInteger& N) const;

private:
	int* digits;
	int num_digits;
	int sign; // 1 -> >0 ; 0 == 0; -1 -> <0
};
