#pragma once
#include<string>
#include<iostream>


class BigInteger {

public:

	BigInteger BigInteger(int* digits,int num_digits,int sign);

	int compare(BigInteger N);

private:
	int* digits;
	int num_digits;
	int sign; // 1 -> >0 ; 0 == 0; -1 -> <0
};