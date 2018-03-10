#include <stdio.h>
#include <math.h>

int log_star(double base, double num) {
	double result = num;
	int times = 0;
	
	while (result >= 1) {
		result = log(result) / log(base);
		times++;
	}
	return times;
}

int main() {
	double base, x;
	printf("base = ");
	scanf("%lf", &base);
	printf("x = ");
	scanf("%lf", &x);
	printf("log* = %d for log with base = %.0lf of %.0lf\n",
		    log_star(base, x), base, x);
}