#include <stdio.h>

void int_sort2(int *p1, int *p2) {
	int x1, x2;
	printf("oringinal: %d %d\n", *p1, *p2);
	if (*p1 > *p2) {
		x2 = *p1;
		x1 = *p2;
	}
	else {
		x1 = *p1;
		x2 = *p2;
	}
	printf("sorted: %d %d\n\n", x1, x2);
}

void test() {
	int a = 15, b = 10, c = 6, d = 2, e = -1, f = -2;
	int_sort2(&a, &b);
	int_sort2(&c, &d);
	int_sort2(&e, &f);
}

int main() {
	test();
}