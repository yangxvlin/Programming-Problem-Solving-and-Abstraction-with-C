#include <stdio.h>

int max_2_ints(int num_1, int num_2) {
	int larger = num_1;
	if (num_2 > num_1) {
			larger = num_2;
	}
	return larger;
}

int main() {
	printf("input 2 numbers: ");
	int number_0, number_1;
	scanf("%d, %d", &number_0, &number_1);
	printf("%d is larger", max_2_ints(number_0, number_1));
}