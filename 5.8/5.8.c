#include <stdio.h>
#include <math.h>
#define CUBE_BOUND 1e-5

int near_equal(double x1, double x2) {
	
	if (((fabs(x2 - x1) <= (CUBE_BOUND)) && (fabs(x2 - x1) >= 0)) && ((x1 != 0) || (x2 != 0))) {
		return 1;
	}
	else if ((x1 == 0) && (x2 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

double
cube_root(double v) {
	double next = 1.0;
	while (near_equal(v, next * next * next) == 0) {
		printf("%lf ", next);
		next = (2 * next + v / (next * next)) / 3;
	}
	return next;
}

int near_equal_test() {
	printf("%d\n", near_equal(0, 0));
	printf("%d\n", near_equal(0, 0.00001));
	printf("%d\n", near_equal(1.01567, 1.01568));
	return 0;
}

int cube_root_test() {
	printf("%lf and %lf\n", cube_root(27), cbrt(27));
	printf("%lf and %lf\n", cube_root(1000), cbrt(1000));
	printf("%lf and %lf\n", cube_root(10), cbrt(10));
	printf("%lf and %lf\n", cube_root(1), cbrt(1));
}

int main() {
	printf("near_equal_test:\n");
	near_equal_test();
	
	printf("cube root test:\n");
	cube_root_test();
	
}