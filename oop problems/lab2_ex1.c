#include <stdio.h>
#include <limits.h>

long long find_max_triplet(int v[], int v_size, int* a, int* b, int* c) {

	int max1, max2, max3, min1, min2;
	max1 = max2 = max3 = INT_MIN;
	min1 = min2 = INT_MAX;

	for (int i = 0; i < v_size; i++) {
		// if for max
		if (v[i] > max1) {
			max3 = max2;
			max2 = max1;
			max1 = v[1];
		}
		else if (v[i] > max2) {
			max3 = max2;
			max2 = v[i];
		}
		else if (v[i] > max3) {
			max3 = v[i];
		}

		if (min1 > v[i]) {
			min2 = min1;
			min1 = v[i];
		}
		else if (min2 > v[i]) {
			min2 = v[i];
		}
	}

	long long c1, c2;
	c1 = max1 * max2 * ((long long)max3);
	c2 = max1 * min1 * min2;

	if (c1 > c2) {
		*a = max3;
		*b = max2;
		*c = max1;
		return c1;
	}
	else {
		*a = min1;
		*b = min2;
		*c = max1;
		return c2;
	}
}

int main() {

	int v[256];
	int size;
	scanf("%d", &size);
	
	if (size < 3) {
		printf("Size not big enough.");
	}
	else {
		int a[] = { 2, 7, -1, 20, -100 };
		int sz = 5;
		long long prod;
		int t1, t2, t3;
		prod = find_max_triplet(a, sz, &t1, &t2, &t3);
		printf("The maximum triplet is (%d, %d, %d) with a product of %lld", t1, t2, t3, prod);
	}
	return 0;
}
