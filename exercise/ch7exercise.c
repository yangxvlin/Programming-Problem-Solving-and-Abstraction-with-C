#include <stdio.h>

#define IS_SORTED 1
#define NOT_SORTED 0

int is_sorted(int *list, int len);

int main() {
	int a[] = {1, 2, 3, 4, 5, 6};
	printf("%d\n", is_sorted(a, 6));
	int b[] = {1, 2, 4, 4, 5, 6};
	printf("%d\n", is_sorted(b, 6));
}

int is_sorted(int *list, int len) {
	int i;
	for (i = 0; i < len-1; i++) {
		if (list[i] >= list[i+1]) {
			return NOT_SORTED;
		}
	}
	
	return IS_SORTED;
}

