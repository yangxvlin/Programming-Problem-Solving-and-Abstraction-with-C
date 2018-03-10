#include <stdio.h>

int main()
{
	int arr[100], num, i = 0, j = 0, k;
	printf("Enter numbers: ");
	while(scanf("%d", &num) == 1)
	{
		arr[i] = num;
		i++;
	}
	
	while(j < i)
	{
		printf("%02d |", arr[j]);
		for(k = 0; k < arr[j]; ++k)
			putchar('*');
		putchar('\n');
		j++;
	}
}