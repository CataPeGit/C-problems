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
	
	for (int i = 0; i < num_digits; i++) {
		digits[i] = (int)str[i];
	}
}

BigInteger::~BigInteger() {
	delete[] digits;
}

int BigInteger::compare(const BigInteger N) const{
	// -1 if number in object is smaller than N, 0 if equal and 1 otherwise

	if (this->sign > N.sign) {
		return 1;
	}
	else if (this->sign < N.sign)
		return -1;
	
	if (this->num_digits > N.num_digits) {
		return 1;
	}

	if (this->num_digits < N.num_digits) {
		return 0;
	}
	
	if (sign == -1) {
		for (int i = 1; i < num_digits; i++) {
			if (this->num_digits[i] < N.num_digits[i]) {
				return 1;
			}
			else if (this->num_digits[i] > N.num_digits[i]) {
				return -1;
			}
		}
	}
	
	for (int i = 0; i < num_digits; i++) {
		if (this->num_digits[i] > N.num_digits[i]) {
			return 1;
		}
		else if (this->num_digits[i] < N.num_digits[i]) {
			return -1;
		}
	}
	
	return 0;
}

int BigInteger::operator==(const BigInteger N) const {
	return compare(N);
}

int BigInteger::operator<(const BigInteger N) const {
	return compare(N);
}

int BigInteger::operator>(const BigInteger N) const {
	return compare(N);
}

int BigInteger::operator<=(const BigInteger N) const {
	return compare(N);
}

int BigInteger::operator>=(const BigInteger N) const {
	return compare(N);
}

char* BigInteger::prepend_zeros(char* arr, int arr_sz, int new_sz) {
	int gap_to_prepend = new_sz - arr_sz;
	arr.~BigInteger();
	char digits_new = new char[new_sz]();
	int digit = 0;
	for (int i = 0; i < new_sz; i++) {
		if (i >= gap_to_prepend) {
			arr[i] = digits[digit];
		}
		arr[i] = 0;
	}
}




/*
BigInteger BigInteger::add(const BigInteger& N) const {
	if (this->sign == N.sign) {
		if (this->sign == "-") {
			for (int i = num; i++) {
				this->num_digits[i] += num_digits[i];
			}
		}
		else {
			for (int i = 0; i < num_digits; i++) {
				this->num_digits[i] += num_digits[i];
			}
		}
	}

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

*/
