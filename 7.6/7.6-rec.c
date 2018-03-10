#include <stdio.h>

void print_arry(int arr[], int num);
void selection_sort(int A[], int n);
int rec_max(int arr[], int n);
void rec_swap(int arr[], int num, int max, int index);

int main() {
	int a[17] = {10, 3, 4, 6, 4, 3, 6, 10, 3, 5, 4, 3, 1, 6, 4, 3, 1};
	printf("original: \n");
	print_arry(a, 17);
	selection_sort(a, 17);
	printf("sorted: \n");
	print_arry(a, 17);
}

int rec_max(int arr[], int n) {
	int max;
	if (n == 0) {
		return arr[0];
	}
	else {
		max = rec_max(arr, n - 1);
		if (max < arr[n - 1]) {
			max = arr[n - 1];
		}
	}
	
	return max;
}

void print_arry(int arr[], int num) {
	int i;
	
	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void rec_swap(int arr[], int num, int max, int index) {
	int tmp;
	
	if (num == 0) {
		return;
	}
	else if ((arr[num - 1] == max) && (num != index - 1) &&
		(arr[index - 1] < max)) {
		tmp = arr[num - 1];
		arr[num - 1] = arr[index - 1];
		arr[index - 1] = tmp;
		return;
	}
	num--;
	rec_swap(arr, num, max, index);
}

void selection_sort(int A[], int n) {
	int i, j, number = n, max, index, tmp;
	
	if (n == 0) {
		return;
	}
	
	max = rec_max(A, number - 1);
	
	rec_swap(A, number, max, number);
	
	number--;
	selection_sort(A, number);
}

