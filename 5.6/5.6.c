#include <stdio.h>
#define TEST_BOUND 1000000

long int factor_sum(long int number) {
	long int sum = 0, i;
	for (i = 1; i <= number/2; i++) {
		if (number % i == 0) {
			sum += i;
		}
	}
	return sum;
}

int is_amicable_pair(long int sum, long int num) {	
	if ((num != sum) && (num > sum) && (factor_sum(sum) == num)) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	long int num = 2, j, flag = 1, num_sum;
	printf("Now starts to find amicable pair:\n");
	while (num < TEST_BOUND) {
		flag = 1;
		num_sum = factor_sum(num);
		//printf("%ld %ld \n", num_sum, num);
		if (is_amicable_pair(num_sum, num)) {
			flag = 0;
			printf("%7d has amicable pair %7d\n", num, num_sum);
		}
		/*if (flag) {
			printf("%5d can't find amicable pair and test number has already reached %d\n", num, TEST_BOUND);
		}*/
		
		num++;
	}
	printf("end");
}