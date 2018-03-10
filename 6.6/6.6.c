#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *number[10]) {
	int i, j, tmp, k;
	for (i = 0; i < 9; ++i) {
		for (j = i + 1; j < 10; ++j) {
			if (*number[i] > *number[j]) {
				tmp = *number[i];
				*number[i] = *number[j];
				*number[j] = tmp;
			}
			/*
			for (k = 0; k < 10; k++) {
				printf("%d ", *number[k]);
			}
			printf("\n");
			*/
		}
	}
}

void test() {
int num[10], i = 0, *address[10];
	
	while (i < 10) {
		num[i] = rand();
		address[i] = &num[i];
		printf("%d ", num[i]);
		i++;
	}
	printf("\n");
	bubble_sort(address);
	
	printf("sorted: \n");
	i = 0;
	while (i < 10) {
		printf("%d ", num[i]);
		i++;
	}
}

int main() {
	test();
}