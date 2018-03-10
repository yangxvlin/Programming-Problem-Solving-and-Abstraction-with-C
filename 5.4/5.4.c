#include <stdio.h>

double factorial(int num) {
	double fac = 1.0, i;
	for (i = num; i > 1.0; --i) {
		fac *= i;
	}	
	return fac;
}

double n_choose_k(int o, int p) {
	double result;
	result = factorial(o) / (factorial(o - p) * factorial(p));
	return result;
}

int main() {
	int n, k;
	printf("");
	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	printf("%d_choose_%d = %f", n, k, n_choose_k(n, k));
}