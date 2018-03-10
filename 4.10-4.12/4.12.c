#include <stdio.h>

int
main(int argc, char *argv[]) {
	char words[1000], character;
	int i = 0, j, k, incomment = 0, newline = 1, flag = 1;
	
	while ((scanf("%c", &character)) && (character != 4)) {
		words[i] = character;
		i++;
	}
	
	for (j = 0; j < i; ++j) {
		if ((words[j] == '/') && (words[j + 1] == '*') && (flag)) {
			flag = 0;
			if ((j + 2) < i) {
				j += 1;
			}
		}
		if (flag) {
			printf("%c", words[j]);
		}
		
		if ((words[j] == '*') && (words[j + 1] == '/') && (!flag)) {
			flag = 1;
			if ((j + 2) < i) {
				j += 1;
			}
		}
	}
	
	return 0;
}