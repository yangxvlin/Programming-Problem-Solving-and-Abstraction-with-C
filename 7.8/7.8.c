#include <stdio.h>

void copy_arry(int origin[], int copy[], int bound);
int find_particular_smallest_number(int arr[], int n, int k);
int find_max(int arr[], int bound, int max);
void sort_array(int arr[], int bound);
void print_arry(int arr[], int n);

int main() {
	int a[17] = {10, 3, 4, 6, 4, 3, 6, 10, 3, 5, 4, 3, 1, 6, 4, 3, 1};
	int value;
	
	printf("a: \n");
	print_arry(a, 17);
	printf("sorted_a:\n");
	value = find_particular_smallest_number(a, 17, 1);
	
	
	printf("1st smallest value = %d\n", value);
	
	printf("a: \n");
	print_arry(a, 17);
	
	
}

int find_particular_smallest_number(int arr[], int n, int k) {
	int A[n];
	copy_arry(arr, A, n);
	
	sort_array(A, n);
	
	print_arry(A, n);
	printf("A: \n");
	print_arry(A, n);
	printf("arr: \n");
	print_arry(arr, n);
	
	return A[k - 1];
}

int find_max(int arr[], int bound, int max) {
	int i, index;
	
	for (i = 0; i < bound; i++) {
		
		if (i == 0) {
			max = arr[i];
			index = i;
		}
		else if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}
	return index;
}

void sort_array(int arr[], int bound) {
	int i, index, max, tmp;
	
	for (i = (bound - 1); i > 0; i--) {
		index = find_max(arr, i, max);
		
		if ((index != i) && (arr[index] > arr[i])) {
			tmp = arr[i];
			arr[i] = arr[index];
			arr[index] = tmp;
		}
		
		// sorting process: print_arry(arr, bound);
	}
}

void copy_arry(int origin[], int copy[], int bound) {
	int i;
	
	for (i = 0; i < bound; i++) {
		copy[i] = origin[i];
	}
}

void print_arry(int arr[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
