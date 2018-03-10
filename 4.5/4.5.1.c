#include <stdio.h>

int main()
{
	int num, i = 0;
	printf("Enter numbers: ");
	while ((scanf("%d", &num) == 1) && (num != EOF))
	{
		printf("%2d |", num);
		for (i = 0; i < num; i++) {
			putchar('*');
		}
		printf("\n");
	}
	
}