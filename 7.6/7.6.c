#include <stdio.h>

void print_arry(int arr[], int num);
void selection_sort(int A[], int n);

int main() {
	int a[17] = {10, 3, 4, 6, 4, 3, 6, 10, 3, 5, 4, 3, 1, 6, 4, 3, 1};
	printf("original: \n");
	print_arry(a, 17);
	selection_sort(a, 17);
	printf("sorted: \n");
	print_arry(a, 17);
}

void print_arry(int arr[], int num) {
	int i;
	
	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void selection_sort(int A[], int n) {
	int i, j, number = n, max, index, tmp;
	
	for(j = 0; j < n; j++) {
		for (i = 0; i < number; i++) {
			if (i == 0) {
				max = A[0];
				index = i;
			}
			else {
				if (A[i] > max) {
					max = A[i];
					index = i;
				}
			}
		}
		number--;
		
		if (index != number) {
			tmp = A[index];
			A[index] = A[number];
			A[number] = tmp;
		}
		
		printf("%d\n", j);
		print_arry(A, 17);
	}
}

