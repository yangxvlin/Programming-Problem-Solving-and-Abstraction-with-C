#include <stdio.h>

int main()
{
	int charge;
	printf("Enter amount in cents: ");
	scanf("%d", &charge);
	
	printf("The coins required to make %d cents are: \n", charge);
	
	while(charge > 0)
	{
		if(charge >= 50)
		{
			printf("50");
			charge -= 50;
		}
		else if(charge >= 20)
		{
			printf("20");
			charge -= 20;
		}
		else if(charge >= 10)
		{
			printf("10");
			charge -= 10;
		}
		else if(charge >= 5)
		{
			printf("5");
			charge -= 5;
		}
		else if(charge >= 2)
		{
			printf("2");
			charge -= 2;
		}
		else if(charge >= 1)
		{
			printf("1");
			charge -= 1;
		}
		if(charge != 0)
			printf(", ");
	}
}