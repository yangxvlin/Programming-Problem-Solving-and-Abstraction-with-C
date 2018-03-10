#include <stdio.h>

int max_2_ints(int num_1, int num_2) {
	int larger = num_1;
	if (num_2 > num_1) {
		larger = num_2;
	}
	return larger;
}

int max_4_ints(int num_1, int num_2, int num_3, int num_4) {
	int larger_0, larger_1, largest;
	larger_0 = max_2_ints(num_1, num_2);
	larger_1 = max_2_ints(num_3, num_4);
	largest = max_2_ints(larger_0, larger_1);
	return largest;
}

int main() {
	printf("input 4 numbers: ");
	int number_0, number_1, number_2, number_3;
	scanf("%d, %d, %d, %d", &number_0, &number_1, &number_2, &number_3);
	printf("the largest number among 4 numbers is %d\n",
		    max_4_ints(number_0, number_1, number_2, number_3));
}