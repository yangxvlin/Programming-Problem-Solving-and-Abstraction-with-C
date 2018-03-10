#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TOLARANCE_VALUE 0.1
#define ITER_LIMIT 50
#define NO_ROOT 0

double f(double x, double z);
void newton_root(double z);

int main() {
	newton_root(3.0);
}

double f(double x, double z) {
	return (x + z / x) / 2.0;
}

void newton_root(double z) {
	double x1 = 0.0, x0 = z;
	int iter = 0;
	x1 = f(x0, z);
	
	while (x0 - x1 >= 0.05) {
		iter++;
		if (iter == ITER_LIMIT) {
			exit(NO_ROOT);
		}
		
		if (iter != 1) {
			x0 = x1;
		}

		x1 = f(x0, z);
	}
	
	printf("%.0lf has root = (x1 + x2)/2 =  %.6lf with iteration %d\n", z, x1, iter);
}