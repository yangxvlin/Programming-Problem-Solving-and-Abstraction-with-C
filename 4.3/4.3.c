#include <stdio.h>

int main()
{
	double num_0 = 0.0, num_1 = 0.0, num_2 = 1.0, tmp_0, tmp_1;
	int i = 0;
	
	while(num_2 <= 10000000000)
	{
		i++;
		printf("day%d is %.0lf\n", i, num_2);
		
		tmp_0 = num_2;
		num_0 = num_1;
		num_1 = tmp_0;
		num_2 = num_0 + num_1;
	}
}