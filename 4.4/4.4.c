#include <stdio.h>

int main()
{
	int i;
	printf("    ");
	for(i = 0; i < 8; ++i)
	{
		printf(" +%d ", i);
	}
	printf("\n");
	
	printf("    +");
	for(i = 0; i < 30; ++i)
	{
		printf("-");
	}

	for(i = 32; i <= 127; ++i)
	{
		if((i - 32) % 8 == 0)
			{
				printf("\n%3d | ", i);
			}
		printf("%c   ", i);

	}
	printf("\n");
}