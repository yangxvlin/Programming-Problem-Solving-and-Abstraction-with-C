/*test: 1 3 4 6 4 3 6 10 3 5 4 3 1 6 4 3 1*/

#include <stdio.h>

#define MAX_VALS 1000

int read_number(int freq[][2]);
void print_array(int arr[][2], int num);
void two_dimension_array_sort(int arr[][2], int num);

int main() {
	int frequency_num, freqency[MAX_VALS][2];
	frequency_num = read_number(freqency);
	
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

int read_number(int freq[][2]) {
	int n = 0, excess = 0, next, i, j = 0, new_val_flag;
	
	printf("Enter as many as %d values, ^D to end\n", MAX_VALS);
	
	while ((scanf("%d", &next)) == 1) {
		if (n == MAX_VALS) {
			excess++;
		}
		else {
			if (j == 0) {
				freq[j][0] = next;
				freq[j][1] = 1;
				j++;
			}
			else {
				new_val_flag = 1;
				for (i = 0; i < j; ++i) {
					if (next == freq[i][0]) {
						freq[i][1] += 1;
						new_val_flag = 0;
					}
				}
				
				if (new_val_flag) {
					freq[j][0] = next;
					freq[j][1] = 1;
					j++;
				}
			}
			n++;
		}
	}
	
	printf("%d values read into array\n", n);
	if (excess) {
		printf("%d values not read into array\n", excess);
	}
	return j;
}