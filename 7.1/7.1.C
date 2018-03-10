#include <stdio.h>

int all_zero(int A[], int n) {
	int i;
	for (i = 0; i < n; ++i) {
		if (i != 0) {
			if (A[i] != A[0]) {
				return 0;
			}
		}
	}
	return 1;
}

void test() {
	int num[100] = {0, 0, 0, 0, 0, 0, 1, 2 , 3, 6, 8, 0, 0, 0, 9};
	printf("0 to 3 in num is %d\n", all_zero(num, 3));
	printf("0 to 6 in num is %d\n", all_zero(num, 6));
	printf("0 to 8 in num is %d\n", all_zero(num, 8));
	printf("0 to 10 in num is %d\n", all_zero(num, 10));
}

int main() {
	test();
}