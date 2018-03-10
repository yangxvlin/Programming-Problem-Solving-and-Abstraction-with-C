#include <stdio.h>

double rec_int_pow(int base, int power) {
	if (power == 0) {
		return 1;
	}
	return base * rec_int_pow(base, power - 1);
}

int main() {
		int base, power;
	printf("base = ");
	scanf("%d", &base);
	printf("power = ");
	scanf("%d", &power);
	if (power < 0) {
		printf("%d^(%d) = 1/%.0lf\n", base, power, rec_int_pow(base, -power));
	}
	else {
		printf("%d^(%d) = %.0lf\n", base, power, rec_int_pow(base, power));
	}
}