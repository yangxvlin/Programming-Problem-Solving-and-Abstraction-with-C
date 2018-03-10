#include <stdio.h>

int isperfect(int n);

long int
nextperfect(long int n) {
	long int i;
	i = n + 1;
	while(isperfect(i) == 0) {
		if (i > 33550337) {
			return 4;
			break;
		}
		i++;
	}
	return i;
}