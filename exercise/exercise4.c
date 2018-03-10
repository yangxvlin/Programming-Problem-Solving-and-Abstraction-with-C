#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *string_dupe(char *s);
char **string_set_dupe(char **S);
void string_set_free(char **S);

int main(int argc, char *argv[]) {
	char **copyed = string_set_dupe(argv);

	string_set_free(copyed);
}

char *string_dupe(char *s) {
	char *c = (char *)malloc(strlen(s) + 1);
	//printf("2%s\n", s);
	strcpy(c, s);
	//printf("2->%s\n", c);
	return c;
}

char **string_set_dupe(char **S) {
	char **c = (char **)malloc(sizeof(char*));
	int i;
	for (i = 0; S[i+1]; i++) {
		//printf("1%s\n", S[i+1]);
		
		c[i] = string_dupe(S[i+1]);

		//printf("1->1%s\n", c[i]);
	}
	
	c[i] = NULL;
	return c;
}

void string_set_free(char **S) {
	for (int i = 0; S[i]; i++) {
		printf("3%s\n", S[i]);

		/*
		printf("%c\n", S[i][2]);
		S[i][2] = 'a';
		printf("%c\n", S[i][2]);
		*/
		
		free(S[i]);
		S[i] = NULL;
		
	}

	return;
}