#include <stdio.h>

int main()
{
	int x, y;
	/*x = 1; y = 2;
	if (x > y)
		printf("x=%d, y=%d\n", x, y);
		x = x + 1;
	if (x < y)
		printf("x=%d, y=%d\n", x, y);
		y = y + 2;
	printf("x=%d, y=%d\n", x, y);*/
	
	/*x = 1; y = 2;
	if (x > y); {
		printf("x=%d, y=%d\n", x, y);
		x = x + 1;
	}
	if (x < y); {
		printf("x=%d, y=%d\n", x, y);
		y = y + 2;
	}
	printf("x=%d, y=%d\n", x, y);*/
	int a;
	x = 0; y = 0;
	if (y<x) {
		printf("y is smaller\n");
	} else if (y=x){
		printf("x and y are equal\n");
	} else {
		printf("y is greater\n");
	}
	a = (y = x);
	printf("%d\n", a);
}