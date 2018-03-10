/*test: 1 3 4 6 4 3 6 10 3 5 4 3 1 6 4 3 1*/

#include <stdio.h>

#define MAX_VALS 1000

int read_number(int num[]);
int frequent(int num[], int num_values, int freq[][2]);
void print_array(int arr[][2], int num);
void two_dimension_array_sort(int arr[][2], int num);

int main() {
	int numbers_entered, frequency_num, numbers[MAX_VALS], freqency[MAX_VALS][2];
	numbers_entered = read_number(numbers);
	
	frequency_num = frequent(numbers, numbers_entered, freqency);
	
	two_dimension_array_sort(freqency, frequency_num);
	print_array(freqency, frequency_num);
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

void print_array(int arr[][2], int num) {
	int i;
	printf("Value    Freq\n");
	for (i = 0; i < num; i++) {
		printf("%4d    %4d\n", arr[i][0], arr[i][1]);
	}
}

int frequent(int num[], int num_values, int freq[][2]) {
	int i = 0, j, k, m = 0, n = 0, new_num_flag = 1;
	freq[m][0] = num[i];
	freq[m][1] = 1;
	m++;
	
	for (i = 1; i < num_values; i++) {
		new_num_flag = 1;
		for (j = 0; j < m; j++) {
			if (num[i] == freq[j][0]) {
				freq[j][1] += 1;
				new_num_flag = 0;
			}
		}
		
		if (new_num_flag) {
			freq[m][0] = num[i];
			freq[m][1] = 1;
			m++;
		}
	}
	
	return m;
}

int read_number(int num[]) {
	int n = 0, excess = 0, next;
	
	printf("Enter as many as %d values, ^D to end\n", MAX_VALS);
	
	while ((scanf("%d", &next)) == 1) {
		if (n == MAX_VALS) {
			excess++;
		}
		else {
			num[n] = next;
			n++;
		}
	}
	
	printf("%d values read into array\n", n);
	if (excess) {
		printf("%d values not read into array\n", excess);
	}
	return n;
}