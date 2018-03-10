#include <stdio.h>

int frequent(int freq[][2], int arr[], int bound);
int find_most_freq(int freq[][2], int bound, int*max_freq);
int most_frequent_min_val(int arr[], int n, int *max_freqency);
void print_array(int arr[][2], int n);

int main() {
	int a[17] = {10, 3, 4, 6, 4, 3, 6, 10, 3, 5, 4, 3, 1, 6, 4, 3, 1};
	int result, freq;
	
	result = most_frequent_min_val(a, 17, &freq);
	printf("%d whith frequency %d\n", result, freq);
}

int frequent(int freq[][2], int arr[], int bound) {
	int i, j = 0, k, new_character = 1;
	
	for (i = 0; i < bound; i++) {
		new_character = 1;
		if (i == 0) {
			freq[j][0] = arr[i];
			freq[j][1] = 1;
			j++;
			new_character = 0;
		}
		else {
			for (k = 0; k < i; k++) {
				if (freq[k][0] == arr[i]) {
					freq[k][1]++;
					new_character = 0;
				}
			}
		}
		
		if (new_character) {
			freq[j][0] = arr[i];
			freq[j][1] = 1;
			j++;
		}
	}
	
	return j;
}

int find_most_freq(int freq[][2], int bound, int*max_freq) {
	int i, max_char[1][2];
	
	for (i = 0; i < bound; i++) {
		if (i == 0) {
			max_char[i][1] = freq[i][1];
			max_char[i][0] = freq[i][0];
		}
		else {
			if (max_char[0][1] < freq[i][1]){
				max_char[0][1] = freq[i][1];
				max_char[0][0] = freq[i][0];
			}
			else if ((max_char[0][1] == freq[i][1]) && (max_char[0][0] < freq[i][0])) {
				max_char[0][0] = freq[i][0];
			}
		}
	}
	
	*max_freq = max_char[0][1];
	return max_char[0][0];
}

int most_frequent_min_val(int arr[], int n, int *max_freqency) {
	int val, val_freq[n][2], character_num, max_freq_int;
	
	character_num = frequent(val_freq, arr, n);
	max_freq_int = find_most_freq(val_freq, character_num, max_freqency);
	
	//print_array(val_freq, character_num);
	
	return max_freq_int;
}

void print_array(int arr[][2], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d %d\n", arr[i][0], arr[i][1]);
	}
}