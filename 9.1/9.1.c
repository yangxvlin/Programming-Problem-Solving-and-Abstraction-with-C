/* Recursive exhaustive evaluation of subset sum problem
   using a generate and test approach.
*/
#include <stdio.h>
#include <stdlib.h>

int subsetsum(int A[], int n, int k);

int
main(int argc, char *argv[]) {
	/* simple data for testing */
	int A[] = {
	34,  38,  39,  43,  55,  66,  67,  84,  85,  91,
	101, 117, 128, 138, 165, 168, 169, 182, 184, 186,
	234, 238, 241, 276, 279, 288, 386, 387, 388, 389,
	413, 444, 487, 513, 534, 535, 616, 722, 786, 787
	};
	int n=20, k=1000;
	if (argc==3) {
		n = atoi(argv[1]);
		k = atoi(argv[2]);
	}
	printf("\nn=%d, k=%d, subsetsum = %d\n",
			n, k, subsetsum(A, n, k));
	return 0;
}

int
subsetsum(int A[], int n, int k) {
	int m, q;
	if (k==0) {
		return 1;
	} else if (n==0) {
		return 0;
	} else {
		m = subsetsum(A, n-1, k-A[n-1]);
		if ((m == 1)/* && (q == 1)*/) {
			printf("%d ",A[n]);
		}
		
		subsetsum(A, n-1, k);

		//printf("%d %d\n",m, q);
		
		//return (m || q);
	}
}

