#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TOLARANCE_VALUE 0.1
#define ITER_LIMIT 50
#define NO_ROOT 0

void my_sqrt(double z);
double f(double x, double z);

int main() {
	my_sqrt(3.0);
	my_sqrt(4.0);
	my_sqrt(5.0);
}

double f(double x, double z) {
	return pow(x, 2) - z;
}

void my_sqrt(double z) {
	double x1 = 0.0, x2 = z, f1, f2, iter = 0, mid, fmid;
	f1 = f(x1, z);
	f2 = f(x2, z);
	
	while (x2 - x1 >= 0.1) {
		iter += 1.0;
		
		mid = (x1 + x2) / 2.0;
		fmid = f(mid, z);
		//printf("%lf %lf %lf\n", x1, x2, x2 - x1);
		if (iter == ITER_LIMIT) {
			exit(NO_ROOT);
		}
		
		/*root at left of mid*/
		if (mid * fmid < 0) {
			x1 = mid;
			f1 = fmid;
		} else {
			/*at right*/
			x2 = mid;
			f2 = fmid;
		}
		//printf("--%lf %lf %lf\n", x1, x2, x2 - x1);
	}
	
	printf("%.0lf has root = (x1 + x2)/2 =  %.6lf with iteration %.0lf\n", z, (x2 + x1) / 2.0, iter);
}