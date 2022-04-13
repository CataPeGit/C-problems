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


BigInteger::BigInteger(string str) {
	if (str[0] == '-') {
		sign = -1;
	}
	else if (str[0] == '0') {
		sign = 0;
	}
	else
	{
		sign = 1;
	}
	num_digits = str.length();
	digits = new int[num_digits]();

	for (int i = 0; i < num_digits; i++) {
		digits[i] = (int)str[i];
	}
}



BigInteger::~BigInteger() {
	delete[] digits;
}



BigInteger& BigInteger::operator=(const BigInteger N)
{
	// release then deep copy
	delete[] digits;

	num_digits = N.get_num_digits();
	sign = N.get_sign();
	digits = new int[num_digits]();
	for (int i = 0; i < num_digits; i++)
		digits[i] = N.get_digit(i);
	return *this;
}

int BigInteger::get_sign() const {
	return sign;
}

int BigInteger::get_num_digits() const {
	return num_digits;
}
int BigInteger::get_digit(int pos) const {
	return digits[pos];
}

int BigInteger::compare(const BigInteger N) const {
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
			if (digits[i] < N.digits[i]) {
				return 1;
			}
			else if (digits[i] > N.digits[i]) {
				return -1;
			}
		}
	}

	for (int i = 0; i < num_digits; i++) {
		if (digits[i] > N.digits[i]) {
			return 1;
		}
		else if (digits[i] < N.digits[i]) {
			return -1;
		}
	}

	return 0;
}

bool BigInteger::operator==(const BigInteger& A, const BigInteger& B) const {
	if (A.get_sign() != B.get_sign())
		return false;
	if (A.get_num_digits() != B.get_num_digits())
		return false;
	for (int i = 0; i < A.get_num_digits(); i++)
		if (A.get_digit(i) != A.get_digit(i))
			return false;
	return true;
}

/*
bool operator<(const BigInteger N) const {
	return true;
}

bool operator>(const BigInteger N) const {
	return true;
}

bool operator<=(const BigInteger N) const {
	return true;
}

bool operator>=(const BigInteger N) const {
	return true;
}
*/



char* BigInteger::prepend_zeros(char* arr, int arr_sz, int new_sz) {
	int gap_to_prepend = new_sz - arr_sz;
	char* digits_new = new char[new_sz]();
	int digit = 0;
	for (int i = 0; i < new_sz; i++) {
		if (i >= gap_to_prepend) {
			arr[i] = digits[digit];
		}
		arr[i] = 0;
	}
	return arr;
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

*/

