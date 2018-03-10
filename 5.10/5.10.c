/* Calculate the result of a regular savings plan.
*/
#include <stdio.h>

double savings_plan(double balance, double amount,
		double ann_rate, int years, double interest_rate);

double
savings_plan(double initial, double amount, 
		double ann_rate, int years, double interest_rate) {
	int month;
	double monthly_mult, balance = initial, rate;
	
	if (initial > 0) {
		rate = ann_rate;
	}
	else {
		rate = interest_rate;
	}
	
	monthly_mult = 1.00 + (rate/100.00)/12;
	for (month=1; month<=12*years; month++) {
		balance *= monthly_mult;
		balance += amount;
	}
	return balance;
}

int test() {
	double result;
	printf("Saving $%.0f plus $%.0f per month for %d years\n",
		175000.0, -1250.0, 25);
	result = savings_plan(175000.0, -1250.0, 7.0, 25, 8.0);
	printf("\tat %.1f%% per year: $%.0f\n", 8.0, result);
	
	printf("Saving $%.0f plus $%.0f per month for %d years\n",
		-175000.0, 1250.0, 25);
	result = savings_plan(-175000.0, 1250.0, 7.0, 25, 8.0);
	printf("\tat %.1f%% per year: $%.0f\n", 7.0, result);
}

int
main(int argc, char *argv[]) {
	int years;
	double rate, per_month, init_bal, answer, interest_rate, final_rate;

	/* read in values to be processed */
	/*
	printf("Enter number of years   : ");
	scanf("%d", &years);
	printf("Enter annual rate %%     : ");
	scanf("%lf", &rate);
	printf("Enter interest_rate     : ");
	scanf("%lf", &interest_rate);
	printf("Enter monthly amount    : $");
	scanf("%lf", &per_month);
	printf("Enter initial balance   : $");
	scanf("%lf", &init_bal);
	*/

	/* and print out the desired answers */
		/*
	printf("Saving $%.0f plus $%.0f per month for %d years\n",
		init_bal, per_month, years);
	answer = savings_plan(init_bal, per_month, rate, years, interest_rate);
	if (init_bal > 0) {
		final_rate = rate;
	}
	else {
		final_rate = interest_rate;
	}
	printf("\tat %.1f%% per year: $%.0f\n", final_rate, answer);
	*/
	/*
	printf("\tat %.1f%% per year: $%.0f\n", rate-1, answer);
	answer = savings_plan(init_bal, per_month, rate  , years);
	printf("\tat %.1f%% per year: $%.0f\n", rate  , answer);
	answer = savings_plan(init_bal, per_month, rate+1, years);
	printf("\tat %.1f%% per year: $%.0f\n", rate+1, answer);
	*/
	test();

	return 0;
}
