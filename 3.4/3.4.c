#include <stdio.h>

int main()
{
	int day, month, year, new_day, new_month, new_year;
	printf("Enter date in format dd/mm/yyyy: ");
	scanf("%d/%d/%d", &day, &month, &year);
	printf("Date read: %02d/%02d/%04d\n", day, month, year);
	
	new_day = day + 1;
	new_month = month;
	new_year = year;
	
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(new_day > 31)
			{
				new_day = 1;
				new_month++;
				if(new_month > 12)
				{
					new_month = 1;
					new_year++;
					printf("Tomorrow: %02d/%02d/%04d\n", new_day, new_month,
													 new_year);
				}
				else
				{
					printf("Tomorrow: %02d/%02d/%04d\n", new_day, new_month,
													 new_year);
				}
			}
			else
			{
				printf("Tomorrow: %02d/%02d/%04d\n", new_day, new_month,
													 new_year);
			}
			
		case 4:
		case 6:
		case 9:
		case 11:
			if(new_day > 30)
			{
				new_day = 1;
				new_month++;
				printf("Tomorrow: %02d/%02d/%04d\n", new_day, new_month,
													 new_year);
			}
			else
			{
				printf("Tomorrow: %02d/%02d/%04d\n", new_day, new_month,
													 new_year);
			}
		case 2:
			if(new_day > 28 + (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
			{
				new_day = 1;
				new_month++;
				printf("Tomorrow: %02d/%02d/%04d\n", new_day, new_month,
													 new_year);
			}
			else
			{
				printf("Tomorrow: %02d/%02d/%04d\n", new_day, new_month,
													 new_year);
			}
			
		defaullt:
			break;
	}
}