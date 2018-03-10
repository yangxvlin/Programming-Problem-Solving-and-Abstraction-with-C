/* Explore the 3n+1 problem.
*/
#include <stdio.h>
#include <stdlib.h>

#define PERLINE 8

int
main(int argc, char *argv[]) {

	int n, cycles = 0, max_cycles, nmax, max_cycles_number, i;
	int first_100_cycles = 0, first_100_cycles_number, last_number;
	int cycle_max_n = 0, max, cycle_max;
	//int cycle_before_converge_number = 0, cycle_before_converge_number_value = 0;
	printf("The first 200+cycles exists ");
	
	for (i = 2;cycles < 200; ++i) {
		n = i;
		cycles = 0;
		cycle_max = 0;
		while(n > 1) {
			if (cycle_max < n) {
				cycle_max = n;
			}
			
			if (n % 2 == 0) {
				n = n / 2;
			}
			else {
				n = 3 * n + 1;
			}
			cycles++;
		}
		// printf("at %d with %d lengths; it grows as large as %d\n",i ,cycles , cycle_max);
	}
	printf("at %d with %d lengths; it grows as large as %d\n",(i - 1) ,cycles , cycle_max);

	/*printf("\n%d cycles consumed, maximum was %d\n",
			cycles, max);*/
	return 0;
}