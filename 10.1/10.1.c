#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	double A[10]; char *p="mary mary quite contrary";
	printf("sizeof(char)   = %2lu\n", sizeof(char));
	printf("sizeof(int)    = %2lu\n", sizeof(int));
	printf("sizeof(float)  = %2lu\n", sizeof(float));
	printf("sizeof(double) = %2lu\n", sizeof(double));
	printf("sizeof(A)      = %2lu\n", sizeof(A));
	printf("sizeof(*A)     = %2lu\n", sizeof(*A));
	printf("sizeof(p)      = %2lu\n", sizeof(p));
	printf("sizeof(*p)     = %2lu\n", sizeof(*p));
	return 0;
}