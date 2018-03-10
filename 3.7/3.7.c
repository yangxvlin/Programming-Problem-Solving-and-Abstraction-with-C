/*converter*/
#include <stdio.h>

int main()
{
	char unit;
	double num, result;
	printf("Enter F C M K P G: ");
	scanf("%lf %c", &num, &unit);
	
	switch(unit)
	{
		case 'F':
			result = (num - 32) * 5 / 9;
			printf("The temperature %.1lfF converts to %.1lfC", num, result);
			break;
		case 'C':
			result = num * 9 / 5 + 32;
			printf("The temperature %.1lfC converts to %.1lfF", num, result);
			break;
		case 'M':
			result = num * 1.609;
			printf("The distance %.1lf miles converts to %.1lf kilometers", num, result);
			break;
		case 'K':
			result = num / 1.609;
			printf("The distance %.1lf kilometers converts to %.1lf miles", num, result);
			break;
		case 'P':
			result = num * 0.454;
			printf("%.1lf pounds = %.1lf kilograms", num, result);
			break;
		case 'G':
			result = num / 0.454;
			printf("%.1lf kilograms = %.1lf pounds", num, result);
			break;
	}
}