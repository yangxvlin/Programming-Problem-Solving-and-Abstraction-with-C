/*calculate inversion in an unsorted arry*/

#include <stdio.h>

int cal_inversion(int arr[], int n);

int main() {
	int a[] = {12, 10, 13, 16, 18, 15, 22, 21, 23, 14};
	
	printf("%d ascending runs in array\n", cal_inversion(a, 10));
}

int cal_inversion(int arr[], int n) {
	int ascending_runs = 1, i, j, start;
	
	for (i = 0; i < n; i++) {
		if (i == 0) {
			start = arr[i];
		}
		else {
			if (arr[i] < start) {
				ascending_runs++;
				
			}
		}
		start = arr[i];
	}
	
	return ascending_runs;
}