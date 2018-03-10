#include <stdio.h>

long int nextperfect(long int n);

int
isperfect(int n) {
	long int sum = 0, i;
	for (i = (n - 1); i > 0; --i) {
		if (n % i == 0) {
			sum += i;
		}
	}
	if (sum == n) {
		return 1;
	}
	else {
		return 0;
	}
}