#include <stdio.h>

int
isperfect(int n) {
	long int sum = 0, i;
	for (i = (n - 1); i > 0; --i) {
		if (n % i == 0) {
			sum += i;
		}
	}
	if (sum == n) {
		return 1;
	}
	else {
		return 0;
	}
}

long int
nextperfect(long int n) {
	long int i;
	i = n + 1;
	while(isperfect(i) == 0) {
		if (i > 33550337) {
			return 4;
			break;
		}
		i++;
	}
	return i;
}

int main() {
	long int num, result;
	printf("input a number: ");
	scanf("%d", &num);
	result = nextperfect(num);
	
	if (result == 4) {
		printf("Cpu is not so powerful and number has already reached 33550337\n");
	}
	else {
		printf("nest perfect is %d\n", result);
	}
}