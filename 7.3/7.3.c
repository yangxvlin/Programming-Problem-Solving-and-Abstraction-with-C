/* Read an array, sort it, write it out in decreasing order again.
test: 1 8 15 3 17 12 4 8 4
*/
#include <stdio.h>

#define MAXVALS 10

int read_int_array(int A[], int n);
void sort_int_array(int A[], int n);
void print_int_array(int A[], int n);
void int_swap(int *p1, int *p2);
int unique_value(int *num[], int origin_num[], int number);

int
main(int argc, char *argv[]) {
	int numbers[MAXVALS], nnumbs;
	nnumbs = read_int_array(numbers, MAXVALS);
	
	printf("Before: ");
	print_int_array(numbers, nnumbs);
	sort_int_array(numbers, nnumbs);
	
	printf("After : ");
	
	int unique[MAXVALS], unique_num, *address[MAXVALS], i;
	for (i = 0; i < MAXVALS; ++i) {
		address[i] = &unique[i];
	}
	unique_num = unique_value(address, numbers, MAXVALS);
	print_int_array(unique, unique_num);
	return 0;
}

int unique_value(int *num[], int origin_num[], int number) {
	int i = 0, j = 0;
	*num[j] = origin_num[i];
	for (i = 1; i < number; i++) {
		if (origin_num[i] > *num[j]) {
			j++;
			*num[j] = origin_num[i];
		}
	}
	return j;
}

int
read_int_array(int A[], int maxvals) {
	int n, excess, next;
	
	printf("Enter as many as %d values, ^D to end\n",
			maxvals);
	n = 0; excess = 0;
	
	while (scanf("%d", &next)==1) {
		if (n==maxvals) {
			excess = excess+1;
		} else {
			A[n] = next;
			n += 1;
		}
	}
	
	printf("%d values read into array", n);
	
	if (excess) {
		printf(", %d excess values discarded", excess);
	}
	printf("\n");
	return n;
}

void
sort_int_array(int A[], int n) {
	int i, j;
	/* assume that A[0] to A[n-1] have valid values */
	for (i=1; i<n; i++) {
		/* swap A[i] left into correct position */
		for (j=i-1; j>=0 && A[j+1] < A[j]; j--) {
			/* not there yet */
			int_swap(&A[j], &A[j+1]);
		}
	}
	/* and that's all there is to it! */
}

void
print_int_array(int A[], int n) {
	int i;
	for (i=0; i<n; i++) {
		printf("%4d", A[i]);
	}
	printf("\n");
}

/* exchange the values of the two variables indicated 
	by the arguments */
void
int_swap(int *p1, int *p2) {
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}