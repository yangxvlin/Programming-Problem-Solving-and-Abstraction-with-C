#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
	double x;
	double y;
} vector_t;

typedef struct {
	vector_t points[MAX_POINTS];
	int points_num;
} poly_t;

double distance(vector_t p1, vector_t p2);
double perimeter(poly_t P);
double area(poly_t P);

int main() {
	poly_t poly;
	poly.points[0].x = 0.0;
	poly.points[0].y = 0.0;
	poly.points[1].x = 1.0;
	poly.points[1].y = 0.0;
	poly.points[2].x = 1.0;
	poly.points[2].y = 3.0;
	poly.points[3].x = 0.5;
	poly.points[3].y = 5.0;
	poly.points[4].x = 0.0;
	poly.points[4].y = 3.0;
	poly.points_num = 5;
	
	printf("poly's C = %lf\n", perimeter(poly));
	printf("poly's A = %lf\n", area(poly));
}

double perimeter(poly_t P) {
	int i;
	double polygan_len = 0.0;
	
	for (i = 0; i < P.points_num - 1; i++) {
		polygan_len += distance(P.points[i], P.points[i + 1]);
	}
	
	return polygan_len += distance(P.points[i], P.points[0]);
}

double distance(vector_t p1, vector_t p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double area(poly_t P) {
	int i;
	double area = 0.0, len1, len2, len3, p;
	
	for (i = 2; i < P.points_num; i++) {
		/*hailun formula*/
		len1 = distance(P.points[0], P.points[i-1]);
		len2 = distance(P.points[i-1], P.points[i]);
		len3 = distance(P.points[i], P.points[0]);
		p = (len1 + len2 + len3) / 2.0;
		area += sqrt(p * (p - len1) * (p - len2) * (p - len3));
	}
	
	printf("%lf\n", area);
	return area;
}

