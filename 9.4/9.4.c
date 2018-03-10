#include <stdio.h>
#include <math.h>

#define START 0.0
#define STOP 86.45
#define MAJOR_AXIS 86.45
#define MINOR_AXIS 73.65

double f(double);

double linelength(double, double, int);

double area(double start, double stop, int steps);

int
main(int argc, char *argv[]) {
	int steps;
	for (steps=1; steps<=10000000; steps=steps*10) {
		printf("steps = %8d, line length = %.6f (m)\n", steps,
				4.0 * linelength(START, STOP, steps));
	}
	printf("\n");
	for (steps=1; steps<=10000000; steps=steps*10) {
		printf("steps = %8d, area = %.6f (m^2)\n", steps,
				4.0 * area(START, STOP, steps));
	}
	return 0;
}

double
f(double x) {
	return MINOR_AXIS * sqrt(1.0 - pow(x, 2) / pow(MAJOR_AXIS, 2));
}

double
linelength(double start, double stop, int steps) {
	double totlen=0.0, x1, x2, fx1, fx2, dx, dy;
	int i;
	x1 = start;
	fx1 = f(x1);
	for (i=1; i<=steps; i++) {
		x2 = start + (double)i*(stop-start)/steps;
		fx2 = f(x2);
		dx = x2-x1;
		dy = fx2-fx1;
		totlen = totlen + sqrt(dx*dx + dy*dy);
		x1 = x2;
		fx1 = fx2;
	}
	return totlen;
}

double area(double start, double stop, int steps) {
	double totarea=0.0, x1, x2, fx1, fx2;
	int i;
	x1 = start;
	fx1 = f(x1);
	for (i=1; i<=steps; i++) {
		x2 = start + (double)i*(stop-start)/steps;
		fx2 = f(x2);
		totarea = totarea + (x2 - x1) * (fx1 + fx2) / 2.0;
		x1 = x2;
		fx1 = fx2;
	}
	return totarea;
}

