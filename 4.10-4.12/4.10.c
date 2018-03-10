/* Cut out FORTRAN-style comments.
*/
#include <stdio.h>

int
main(int argc, char *argv[]) {
	int incomment=0, newlinelast=1;
	char ch, last_character;
	
	while ((scanf("%c", &ch) == 1) && (ch != EOF)) {
		if ((last_character == '/') && (ch == '/') && newlinelast) {
			newlinelast = 0;
			incomment = 1;
			ch = '*';
		}
		
		
		
		if ((ch == '\n') && incomment) {
			printf("*/\n");
			
			incomment=0;
			newlinelast=1;
		}
		else {
			putchar(ch);
		}
		
		/*
		if (ch == 'C' && newlinelast) {
			incomment = 1;
		}
		
		if (!incomment) {
			putchar(ch);
		}
		
		if (ch == '\n') {
			incomment = 0;
			newlinelast = 1;
		} else {
			newlinelast = 0;
		}
		*/
		
		last_character = ch;
	}
	return 0;
}