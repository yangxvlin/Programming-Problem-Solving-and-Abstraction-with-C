/* deleate all /**//*within //*/
//test: asd // asdc /**/ /* */ // /t d/

#include <stdio.h>

int
main(int argc, char *argv[]) {
	char words[1000], character;
	int i = 0, j, k, incomment = 0, newline = 1;
	
	while ((scanf("%c", &character)) && (character != 4)) {
		words[i] = character;
		i++;
	}
	
	for (j = 0; j < i; ++j) {
		if ((words[j] == '/') && (words[j + 1] == '/')) {
			if (newline == 1) {
				printf("%c", words[j]);	
				words[j + 1] = '*';
				printf("%c", words[j + 1]);	
				newline = 0;
				incomment = 1;
			}
		}
		
		if (incomment) {
			if (words[j] != '\n') {
				
				if (words[j] == '*') {
					if (!((words[j - 1] == '/') || (((j + 1) <= i) && (words[j + 1] == '/')))) {
						printf("%c", words[j]);
					}
				}
				
				if (words[j] == '/') {
					if (!((words[j - 1] == '*') || (((j + 1) <= i) && (words[j + 1] == '*')))) {
						printf("%c", words[j]);
					}
				}
				
				if ((words[j] != '*') && (words[j] != '/')) {
					printf("%c", words[j]);
				}
				
			}
		}
		else if (incomment && (((words[j] == '*') && (words[j + 1] == '/')) ||
			                 ((words[j] == '/') && (words[j + 1] == '*')))) {
			j += 2;
		}
			
		if (!incomment){
			printf("%c", words[j]);	
		}
		
		if (words[j] == '\n') {
			printf("*/\n");
			newline = 1;
			incomment = 0;
		}	
	}
	
	return 0;
}
 