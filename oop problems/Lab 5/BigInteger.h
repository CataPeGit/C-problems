#include "BigInteger.h"

#include <cctype> // for isdigit
#include <iostream>
#include <iomanip>
using namespace std;


// addition -prepend cu 0 si adunam una cate una
// apoi facem rez - 10 si facem carry
// 16 - 10 = 6, carry 1

/*
void digitize() {
	int carry = 0;
	for (i = num_digits - 1; i >= 0; i--) {
		digits[i] += carry;
		if (digits[i] > 9) {
			carry = 1;
			digits[i] -= 10;
		}
		else {
			carry = 0;
		}
	}
	if(carry) digits[0] = 1;
}
*/

BigInteger::BigInteger() {
	sign = 0;
	num_digits = 0;
	digits = new int[100]();

}

BigInteger::BigInteger(string* str) {
	if (str[0] == "-") {
		sign = -1;
	}
	else if (str[0] == 0){
		sign = 0;
	}
	else
	{
		sign = 1;
	}
	num_digits = length(str);
	digits = new int[num_digits]();
}

BigInteger::~BigInteger(BigInteger* Digits) {
	delete[] Digits;
}

BigInteger::copy_constructor(const BigInteger& c) {
	digits = c.digits;
	*num_digits = *(c.num_digits);
	sign = c.sign;
}

BigInteger::assignment_operator(const BigInteger& c) {
	// release si apoi deep copy
	digits = c.digits;
	*num_digits = *(c.num_digits);
	sign = c.sign;
	
}


int compare(BigInteger N) {
	// -1 if number in object is smaller than N, 0 if equal and 1 otherwise

	if (this->sign > N.sign) {
		return 1;
	}
	else if (this->sign < N.sign)
		return -1;
	
	if (this->num_digits > N.num_digits) {

	}
	
}