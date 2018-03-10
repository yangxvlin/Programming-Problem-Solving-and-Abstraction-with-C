/* Determine the input number's next prime.
*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	long int n, divisor, start;
	int isprime, prime;
	printf("Enter a number n: ");
	if (scanf("%d", &start) != 1) {
		printf("Incorrect input\n");
		exit(EXIT_FAILURE);
	}
	/* a value for n has been read */
	isprime = 0;
	n = start + 1;
	while (isprime == 0) {
		prime = 1;
		for (divisor=2; divisor*divisor<=n; divisor++) {
			if (n%divisor==0) {
				prime = 0;
				//printf("%d %d %d\n", divisor, n, prime);
				//continue;
			}
		}
		if (prime == 1) {
			isprime = 1;
		}
		n++;
	}
		

	if (isprime == 1) {
		printf("The next prime number is %d\n", (n - 1));
	}


	return 0;
}
