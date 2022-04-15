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

	int start = 0;
	if (sign == -1)
		start = 1;

	num_digits = str.length();
	digits = new int[num_digits - start]();

	for (int i = start; i < num_digits; i++) {
		digits[i-start] = str[i] - '0';
	}
	if (sign == -1)
		num_digits -= 1;
}

BigInteger::BigInteger(int* _digits, int _num_digits, int _sign)
{
	sign = _sign;
	num_digits = _num_digits;
	digits = new int[num_digits]();
	for (int i = 0; i < num_digits; i++) {
		digits[i] = _digits[i];
	}
	//delete[] _digits;
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

int* BigInteger::get_digits_array() const
{
	return digits;
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

int* prepend_zeros(int* arr, int arr_sz, int new_sz) {
	// adds zeros to the start of the array to fill the gap between new_sz and arr_sz

	if (arr_sz == new_sz)
		return arr;

	int gap_to_prepend = new_sz - arr_sz;
	int* digits_new = new int[new_sz]();
	for (int i = 0; i < new_sz; i++) {
		if (i >= gap_to_prepend) {
			digits_new[i] = arr[i - gap_to_prepend];
		}
		else {
			digits_new[i] = 0;
		}
	}
	return digits_new;
}


int* negate(int* arr, int arr_sz) {
	// multiply with -1 each element in arr
	for (int i = 0; i < arr_sz; i++) {
		arr[i] *= -1;
	}
	return arr;
}

int* add_arrays(int* arr1, int* arr2, int arr_sz) {
	// adds two arrays of digits
	for (int i = 0; i < arr_sz; i++) {
		arr1[i] += arr2[i];
		cout << arr1[i] << "we got this";
	}
	return arr1;
}

int* sub_arrays(int* arr1, int* arr2, int arr_sz) {
	// subtracts two arrays of digits

	for (int i = 0; i < arr_sz; i++) {
		arr1[i] -= arr2[i];
	}
	return arr1;
}

int* digitize(int* arr, int arr_sz)
{
	// normalizes arr such that every element is a digit
	int carry = 0;
	int borrow = 0;
	for (int i = arr_sz - 1; i >= 0; i--) {
		arr[i] += carry;
		arr[i] -= borrow;
		if (arr[i] > 9) {
			arr[i] = arr[i] - 10;
			carry = 1;
			borrow = 0;
		}
		else if (arr[i] < 0) {
			arr[i] += 10;
			borrow = 1;
			carry = 0;
		}
		else {
			carry = 0;
			borrow = 0;
		}
	}
	return arr;
}

BigInteger BigInteger::add(const BigInteger& N) const {
	// adds two BigInteger objects

	// getting the biggest array size
	int max_size = 0;
	if (num_digits >= N.get_num_digits())
	{
		max_size = num_digits;
	}
	else if (num_digits < N.get_num_digits()) {
		max_size = N.get_num_digits();
	}

	// creating arrays we will add
	int* array1 = prepend_zeros(digits, num_digits, max_size);
	int* array2 = prepend_zeros(N.get_digits_array(), N.get_num_digits(), max_size);

	// negating arrays if needed
	if (sign == -1 && N.get_sign() == 1) {
		array1 = negate(array1, max_size);
	}
	if (N.get_sign() == -1 && sign == 1) {
		array2 = negate(array2, max_size);
	}

	// calculate resulted array
	int* result_array = add_arrays(array1, array2, max_size);

	result_array = digitize(result_array, max_size);

	// getting the new sign
	int result_sign = 0;
	if (sign == -1 && N.get_sign() == -1) {
		result_sign = -1;
	}
	else if (sign == 1 || N.get_sign() == 1) {
		result_sign = 1;
	}
	
	//delete[] array1;
	//delete[] array2;
	//delete[] result_array;
	return BigInteger(result_array, max_size, result_sign);
}


BigInteger operator+(const BigInteger& A, const BigInteger& B)
{
	return A.add(B);
}


bool operator==(const BigInteger& A, const BigInteger& B)
{
	if (A.get_sign() != B.get_sign())
		return false;
	if (A.get_num_digits() != B.get_num_digits())
		return false;
	for (int i = 0; i < A.get_num_digits(); i++)
		if (A.get_digit(i) != B.get_digit(i))
			return false;
	return true;
}

bool operator<(const BigInteger& A, const BigInteger& B)
{
	if (A.get_sign() > B.get_sign()) {
		return false;
	}
	else if (A.get_num_digits() > B.get_num_digits()) {
		return false;
	}
	else {
		for (int i = 0; i < A.get_num_digits(); i++) {
			if (A.get_digit(i) == B.get_digit(i))
				continue;
			else if (A.get_digit(i) > B.get_digit(i))
				return false;
			else if (A.get_digit(i) < B.get_digit(i))
				return true;
		}
	}
	return true;
}

bool operator>(const BigInteger& A, const BigInteger& B)
{
	if (A.get_sign() < B.get_sign()) {
		return false;
	}
	else if (A.get_num_digits() < B.get_num_digits()) {
		return false;
	}
	else {
		for (int i = 0; i < A.get_num_digits(); i++) {
			if (A.get_digit(i) == B.get_digit(i))
				continue;
			else if (A.get_digit(i) < B.get_digit(i))
				return false;
			else if (A.get_digit(i) > B.get_digit(i))
				return true;
		}
	}
	return true;
}

bool operator<=(const BigInteger& A, const BigInteger& B)
{
	if (A == B || A < B)
		return true;
	return false;
}

bool operator>=(const BigInteger& A, const BigInteger& B)
{
	if (A == B || A > B)
		return true;
	return false;
}


/*
BigInteger add(const BigInteger& N) const {
	int new_sign = 0;
	if ((sign == -1 || N.get_sign() == -1) && (sign != N.get_sign())) {
		new_sign = -1;
	}
	else if (sign != 0 || N.get_sign() != 0) {
		new_sign = 1;
	}

}

*/

//BigInteger sub(const BigInteger& N) const;

