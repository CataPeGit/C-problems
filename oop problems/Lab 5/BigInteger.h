#pragma once
#include<string>
#include<iostream>

using std::string;

class BigInteger {

public:
	BigInteger();
	BigInteger(string str);

	~BigInteger();

	BigInteger& operator=(const BigInteger N);

	int compare(const BigInteger N) const;

	int get_num_digits() const;
	int get_sign() const;
	int get_digit(int pos) const;

	friend bool operator==(const BigInteger& A, const BigInteger& B) const;
	/*
	friend bool operator<(const BigInteger N) const;
	friend bool operator>(const BigInteger N) const;
	friend bool operator<=(const BigInteger N) const;
	friend bool operator>=(const BigInteger N) const;	
	*/


	char* prepend_zeros(char* arr, int arr_sz, int new_sz);

	//BigInteger add(const BigInteger& N) const;
	//BigInteger sub(const BigInteger& N) const;

private:
	int* digits;
	int num_digits;
	int sign; // 1 -> >0 ; 0 == 0; -1 -> <0
};
