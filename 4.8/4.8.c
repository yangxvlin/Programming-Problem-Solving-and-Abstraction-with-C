/* Explore the 3n+1 problem.
*/
#include <stdio.h>
#include <stdlib.h>

#define PERLINE 8

int
main(int argc, char *argv[]) {

	int n, cycles, max_cycles, nmax, max_cycles_number, i;
	int first_100_cycles = 0, first_100_cycles_number, last_number;
	int cycle_max_n = 0, max, cycle_max;
	//int cycle_before_converge_number = 0, cycle_before_converge_number_value = 0;
	
	printf("Enter starting value for nmax: ");
	if (scanf("%d", &nmax) != 1) {
		printf("Incorrect input\n");
		exit(EXIT_FAILURE);
	}
	// /* a value for n has been read */
	
	for (i = 2;i <= nmax; ++i) {
		n = i;
		//cycle_before_converge_number = n;
		cycles = 0;
		while(n > 1) {
			/*if(i == 27)
				printf("%5d ", n);*/
			/*if ((n < last_number) && (cycle_before_converge_number == i)) {
				cycle_before_converge_number = i;
				cycle_before_converge_number_value = last_number;
			}*/
			if (cycle_max < n) {
				cycle_max_n = i;
				cycle_max = n;
			}
			
			if (n % 2 == 0) {
				n = n / 2;
			}
			else {
				n = 3 * n + 1;
			}
			/*if (n > max) {
				max = n;
			}*/
			cycles += 1;
			/*if (cycles % PERLINE == 0) {
				printf("\n");
			}*/
			//last_number = n;
		}
		
		if (cycles > max_cycles) {
			max_cycles = cycles;
			max_cycles_number = i;
		}
		printf("number: %d has cycles: %d\n", i, cycles);
		
		if ((cycles > 99) && (first_100_cycles < 100)) {
			first_100_cycles = cycles;
			first_100_cycles_number = i;
		}
		if (cycle_max_n == first_100_cycles_number) {
			max = cycle_max;
		}
	}
	printf("max_cycles = %d, max_cycles_number = %d\n", max_cycles,
														max_cycles_number);
	printf("first_100+_cycles who has %d cycles occurs when number is %d\n",
		    first_100_cycles, first_100_cycles_number);
	printf("and it passed through the max value %d before converging\n",
		   max);
	/*printf("\n%d cycles consumed, maximum was %d\n",
			cycles, max);*/
	return 0;
}