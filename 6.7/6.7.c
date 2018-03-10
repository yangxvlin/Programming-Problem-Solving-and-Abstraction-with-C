/* Read numbers until one in the specified range is found.
*/
#include <stdio.h>
#include <stdlib.h>

#define READ_OK 0
#define READ_ERROR 1

int read_num(int lo, int hi, int *num);

void int_swap(int *p1, int *p2) {
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int
main(int argc, char *argv[]) {
	int valu, low, high, tmp;
	printf("low = ");
	scanf("%d", &low);
	printf("high = ");
	scanf("%d", &high);
	if (high < low) {
		int_swap(&low, &high);
	}
	if (read_num(low, high, &valu) != READ_OK) {
		printf("Read error, program abort\n");
		exit(EXIT_FAILURE);
	}
	/* ok, can now go ahead and use the number in valu */
	printf("valu = %d\n", valu);
	
	return 0;
}

/* Read numbers until one in the desired range from lo
   to hi is entered. Return that one as num. */
int
read_num(int lo, int hi, int *num) {
	int next;
	printf("enter a number between %d and %d inclusive: ",
			lo, hi);
	while (scanf("%d", &next) == 1) {
		/* got a number, so take a look at it */
		if (lo <= next && next <= hi) {
			/* this number is within range */
			*num = next;
			return READ_OK;
		}
		printf("%d is not between %d and %d\ntry again: ",
				next, lo, hi);
	}
	/* no valid numbers found, and scanf has failed */
	return READ_ERROR;
}