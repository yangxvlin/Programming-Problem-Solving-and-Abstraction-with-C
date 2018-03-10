#include <stdio.h>

int main()
{
	int n;
	float x;
	char m[] = "hello";
	n = -123;
	x = 123.567;
	printf("%3d\n", n);
	printf("x = %8.4f\n",x);
	printf("m = \"%-15s\"\n", m);
}