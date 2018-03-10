#include <stdio.h>

void print_arr(int arr[][3], int n, int set[]);
int sumset(int arr[], int result[][3], int n);
void subset(int a[], int len);

int main() {
	int set[] = {5, -6, 5, 3, -2, 3, -1, 4, -100, 101};
	int len = sizeof(set) / sizeof(set[0]);
	subset(set, len);
}

void subset(int a[], int len) {
	int sum[len][3], setnum;
	
	setnum = sumset(a, sum, len);
	print_arr(sum, setnum, a);
}

int sumset(int arr[], int result[][3], int n) {
	int i, j, sum = 0, start, end, counter = 0, unwanted_neg = 1;
	
	for (i = 0; i < n; i++) {
		start = i;
		sum += arr[i];
		
		if (sum <= 0) {
			sum = 0;
			continue;
		}
		
		unwanted_neg = 1;
		for (j = i + 1; j < n; j++) {
			sum += arr[j];
			//printf("---%d \n", sum);
			if (sum < 0) {
				end = j - 1;
				unwanted_neg = 0;
				sum -= arr[j];
				result[counter][0] = sum;
				result[counter][1] = start;
				result[counter][2] = end;
				sum = 0;
				break;
			}
		}
		
		if (unwanted_neg) {
			end = j - 1;
			result[counter][0] = sum;
			result[counter][1] = start;
			result[counter][2] = end;
		}
		i = j;
		//printf("%d \n", sum);
		
		
		counter++;
	}
	
	return counter;
}

void print_arr(int arr[][3], int n, int set[]) {
	int i, j, k;
	
	for (i = 0; i < n; i++) {
		printf("sum = %d start at %d, end at %d: {", arr[i][0], arr[i][1], arr[i][2]);
		for (j = arr[i][1]; j <= arr[i][2]; j++) {
			printf("%d", set[j]);
			if (j < arr[i][2]) {
				printf(", ");
			}
		}
		printf("}\n");
	}
}

/*
void sort() {
	
}

*/