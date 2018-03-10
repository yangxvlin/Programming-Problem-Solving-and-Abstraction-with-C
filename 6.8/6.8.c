#include <stdio.h>

void int_divide(int numerator, int denominator,
	            int *quotient, int *remainder) {
	*quotient = numerator / denominator;
	*remainder = numerator - (*quotient * denominator);
}

void test() {
	int numerator, denominator, quotient, remainder;
	int_divide(10, 3, &quotient, &remainder);
	printf("%d / %d = %d ，，，，，，， %d\n",
		   10, 3, quotient, remainder);
	
	int_divide(-10, 3, &quotient, &remainder);
	printf("%d / %d = %d ，，，，，，， %d\n",
		   -10, 3, quotient, remainder);
	cd 
	int_divide(10, -3, &quotient, &remainder);
	printf("%d / %d = %d ，，，，，，， %d\n",
		   10, -3, quotient, remainder);
	
	int_divide(-10, -3, &quotient, &remainder);
	printf("%d / %d = %d ，，，，，，， %d\n",
		   -10, -3, quotient, remainder);
	
	int_divide(10, 100, &quotient, &remainder);
	printf("%d / %d = %d ，，，，，，， %d\n",
		   10, 100, quotient, remainder);
	
	int_divide(-10, -100, &quotient, &remainder);
	printf("%d / %d = %d ，，，，，，， %d\n",
		   -10, -100, quotient, remainder);
}

int main() {
	test();
	/*
	printf("input: numerator, denominator\n");
	scanf("%d, %d", &numerator, &denominator);
	*/
	
}
// ||((numerator == 'y') && (denominator == 'y'))