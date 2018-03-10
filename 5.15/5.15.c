#include <stdio.h>

int oooo(int n);
int eeee(int n);
int easier_eeee(int n);
int easier_oooo(int n);

int eeee(int n) {
	if (n == 0) {
		return (1);
	} else {
		return oooo(n - 1);
	}
}

int oooo(int n) {
	if (n == 0) {
		return (0);
	} else {
		return eeee(n - 1);
	}
}

/*easier implementation*/
int easier_eeee(int n) {
	if (n == 0) {
		return (1);
	}
	if (n < 0) {
		return (0);
	} else {
		return easier_eeee(n - 2);
	}
}

int easier_oooo(int n) {
	if (n == 0) {
		return (0);
	}
	if (n < 0) {
		return 1;
	} else {
		return easier_oooo(n - 2);
	}
}

int main(){
	printf("%d %d %d\n", 5, eeee(5), oooo(5));
	printf("easier implementation:%d %d\n", easier_eeee(5), easier_oooo(5));
	printf("%d %d %d\n", 6, eeee(6), oooo(6));
	printf("easier implementation:%d %d\n", easier_eeee(6), easier_oooo(6));
}