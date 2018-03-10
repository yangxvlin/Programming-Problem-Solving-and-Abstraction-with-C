#include <stdio.h>

double int_pow(int base, int power) {
	int i;
	double decimal = 0.0 ,numtiple = 1.0;
	decimal += base;
	
	if (power < 0) {
		decimal = 1.0 / base;
		power = -power;
	}
	
	for (i = 0;i < power; ++i) {
		numtiple *= decimal;
	}
	return numtiple;
}

int main() {
	int base, power;
	printf("base = ");
	scanf("%d", &base);
	printf("power = ");
	scanf("%d", &power);
	printf("%d^(%d) = %.0lf\n", base, power, int_pow(base, power));
	if (power < 0) {
		printf("%d^(%d) = 1/%.0lf\n", base, power, int_pow(base, -power));
	}
}