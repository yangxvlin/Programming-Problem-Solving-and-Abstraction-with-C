#include <stdio.h>
#include <math.h>
int main()
{
	double a, b, c, d, x1, x2, r, i1, i2;
	printf("a * x^2 + b * x + c = 0\na = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);
	d = pow(b, 2) - 4 * a * c;

	if(d > 0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		printf("x1 = %lf\n", x1);
		x2 = -(-b + sqrt(d)) / (2 * a);
		printf("x2 = %lf\n", x2);
	}
	else if(d == 0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		printf("x1 = x2 = %lf", x1);
	}
	else
	{
		printf("no real solution\n");
		r = -b / (2 * a);
		i1 = sqrt(-d)/ (2 * a);
		i2 = -sqrt(-d)/ (2 * a);
		printf("But has complex solution\n");
		printf("x1 = %lf + %lfi\n", r, i1);
		printf("x2 = %lf + %lfi\n", r, i2);
	}
}