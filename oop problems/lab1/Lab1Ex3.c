#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isApril(int D, int E) {
	if (22 + E + D > 31)
		return true;
	else
		return false;
}

bool test_year(int year) {
	if(year >= 1876){
		return true;
	}
	else {
		printf("Invalid input, the year should be greater or equal to 1876");
		return false;
	}
}

char check_day(int day) {
	if (day < 10) {
		return true;
	}
	return false;
}

struct Date {
	int year;
	char month[21];
	int day;

}date;

int main() {
	scanf_s("%d", &date.year);
	
	if (test_year(date.year) == false) {
		return 0;
	}

	int A = date.year % 19;
	int B = date.year % 4;
	int C = date.year % 7;
	int D = (19 * A + 24) % 30;
	int E = (2 * B + 4 * C + 6 * D + 5) % 7;
	strcpy_s(date.month, "March");
	if (isApril(D, E)) {
		strcpy_s(date.month, "April");
		date.day = 22 + E + D - 31;
	}
	else {
		strcpy_s(date.month, "March");
		date.day = 22 + E + D;
	}
	
	if (check_day(date.day)) {
		printf("In %d the Easter date is %s 0%d", date.year, &date.month, date.day);
	}
	else {
		printf("In %d the Easter date is %s %d", date.year, &date.month, date.day);
	}
	return 0;
}