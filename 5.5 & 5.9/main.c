#include <stdio.h>

int isperfect(int n);
long int nextperfect(long int n);

int main() {
	long int num, result;
	printf("input a number: ");
	scanf("%ld", &num);
	result = nextperfect(num);
	
	if (result == 4) {
		printf("Cpu is not so powerful and number has already reached 33550337\n");
	}
	else {
		printf("nest perfect is %d\n", result);
	}
	
	return 0;
}

/*
gcc -Wall -ansi -o main main.c isperfect.c nextperfect.c
*/