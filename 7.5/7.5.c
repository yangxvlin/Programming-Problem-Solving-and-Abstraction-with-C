/*
823678 66
765876 94
904904 100
864876 48
785671 68
854565 89
*/

#include <stdio.h>

#define MAX_VAL 1000

int read_number(int arr[][2]);
void two_dimension_array_sort(int arr[][2], int num);
void print_array(int arr[][2], int num);

int main() {
	int info[MAX_VAL][2], num;
	
	num = read_number(info);
	
	two_dimension_array_sort(info, num);
	print_array(info, num);
}

void print_array(int arr[][2], int num) {
	int i;
	printf("Studennt    Mark\n");
	for (i = 0; i < num; i++) {
		printf("%8d    %4d\n", arr[i][0], arr[i][1]);
	}
}

void two_dimension_array_sort(int arr[][2], int num) {
	int i, j, tmp_val, tmp_freq;
	
	for (i = 0; i < num; ++i) {
		for (j = i; j < num; ++j) {
			if (arr[i][0] > arr[j][0]) {
				tmp_val = arr[i][0];
				arr[i][0] = arr[j][0];
				arr[j][0] = tmp_val;
				
				tmp_freq = arr[i][1];
				arr[i][1] = arr[j][1];
				arr[j][1] = tmp_freq;
			}
		}
	}
}

int read_number(int arr[][2]) {
	int i = 0, student, mark, excess = 0;
	
	while (scanf("%d %d", &student, &mark) && (student != 4)) {
		if (i == MAX_VAL) {
			excess++;
		}
		else {
			arr[i][0] = student;
			arr[i][1] = mark;
			i++;
		}
	}
	
	printf("%d values read into array\n", i);
	if (excess) {
		printf("%d values not read into array\n", excess);
	}
	return i;
}