#include <stdio.h>
#include <math.h>

typedef struct {
	double x;
	double y;
} vector_t;

void test(double x1, double y1, double x2, double y2);
double distance(vector_t p1, vector_t p2);

int main() {
	test(1.0, 1.0, 2.0, 2.0);
	test(10, 0, 5.5, 2.5);
}

void test(double x1, double y1, double x2, double y2) {
	vector_t point1;
	vector_t point2;
	point1.x = x1;
	point1.y = y1;
	point2.x = x2;
	point2.y = y2;
	
	printf("point(%lf, %lf) and point(%lf, %lf) has \n",
		point1.x, point1.y, point2.x, point2.y);
	printf("distance = %lf\n\n", distance(point1, point2));
}

double distance(vector_t p1, vector_t p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

