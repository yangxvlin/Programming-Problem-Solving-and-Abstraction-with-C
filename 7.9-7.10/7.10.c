#include <stdio.h>

int inversion(int arr[], int n);

int main() {
	int a[] = {12, 10, 13, 16, 18, 15, 22, 21, 23, 14};
	printf("%d inversions in the array\n", inversion(a, 10));
}

int inversion(int arr[], int n) {
	int inver = 0, i, j;
	
	for (i = n - 1; i > 0; i--) {
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
				inver++;
			}
		}		
	}
	
	return inver;
}