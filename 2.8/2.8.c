#include <stdio.h>

int main()
{
	int degree;
	double celsius_degree, decimal_degree;
	
	printf("degrees Fahrenheit = ");
	scanf("%d", &degree);
	
	decimal_degree = degree;
	celsius_degree = (decimal_degree - 32) * 5 / 9;
	printf("celsius_degree = %lf\n", celsius_degree);
}