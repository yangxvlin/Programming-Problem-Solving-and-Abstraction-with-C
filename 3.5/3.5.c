#include <stdio.h>

int main()
{
	int day, month, year, count, i;
	printf("Enter date in dd/mm/yyyy format: ");
	scanf("%d/%d/%d", &day, &month, &year);
	
	count = 0;
	
	for(i = (month - 1); i >= 0; --i)
	{
		switch(i)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				count += 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				count += 30;
				break;
			case 2:
				count +=(28 + (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)));
				break;
			case 0:
				count += day;
				break;
		}
	}

	printf("%02d/%02d/%04d is day number %d in the year", day, month, year, count);
}