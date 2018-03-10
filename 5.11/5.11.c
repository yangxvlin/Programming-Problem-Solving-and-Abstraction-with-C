#include <stdio.h>

double factorial(int num) {
	double fac = 1.0;
	int i;
	for (i = num; i > 1; --i) {
		fac *= i;
	}	
	return fac;
}

double sum(int num) {
	double sum = 0.0;
	int i;
	for (i = num; i >= 1; --i) {
		sum += i;
	}	
	return sum;
}

double sum_sequence(int n) {
	int i;
	double result = 0.0;
	for (i = n; i > 0; --i) {
		result += sum(i) / factorial(i);
	}
	return result;
}

int main() {
	int num;
	printf("input a positive integer:");
	scanf("%d", &num);
	printf("result = %lf\n", sum_sequence(num));
}