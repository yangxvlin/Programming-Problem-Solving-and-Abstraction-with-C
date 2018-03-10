#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_FILE 10

int main(int argc, char *argv[]) {
	printf("%d files get\n", argc);
	if (argc > MAX_FILE) {
		printf("too much file\n");
		exit(EXIT_FAILURE);
	}
	if (argc < 2) {
		printf("too less file\n");
		exit(EXIT_FAILURE);
	}
	
	FILE *fp[MAX_FILE];
	int i;
	char c;

	for (i = 1; i < argc-1; i++) {
		
		if ((fp[i] = fopen(argv[i], "r")) == NULL) {
			printf("open failed\n");
		}
		if ((fp[i+1] = fopen(argv[i+1], "a")) == NULL) {
			printf("open failed\n");
		}
		
		
		while ((c = getc(fp[i])) && (c != EOF)) {
			assert(putc(c, fp[i+1]) != EOF);
			//printf("%c ", c);
		}
		//printf("\n");
		
		fclose(fp[i]);
		fclose(fp[i+1]);
	}
	
	
	return 0;
}