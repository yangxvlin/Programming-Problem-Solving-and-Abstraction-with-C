//ammoffat@

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXCHARS 10      /* Max chars per word */
#define MAXWORDS 1000    /* Max distinct words */

typedef char word_t[MAXCHARS+1];
int getword(word_t W, int limit);

int
main(int argc, char *argv[]) {
	word_t one_word, all_words[MAXWORDS];
	int numdistinct=0, totwords=0, i, found;
	while (getword(one_word, MAXCHARS) != EOF) {
		totwords = totwords+1;
		/* linear search in array of previous words... */
		found = 0;
		for (i=0; i<numdistinct && !found; i++) {
			found = (strcmp(one_word, all_words[i]) == 0);
		}
		if (!found && numdistinct<MAXWORDS) {
			strcpy(all_words[numdistinct], one_word);
			numdistinct += 1;
		}
		/* NB - program silently discards words after
		   MAXWORDS distinct ones have been found */
	}
	printf("%d words read\n", totwords);
	for (i=0; i<numdistinct; i++) {
		printf("word #%d is \"%s\"\n", i, all_words[i]);
	}
	return 0;
}

int
getword(char W[], int limit) {
	int c, len=0;
	/* first, skip over any non alphabetics */
	while ((c=getchar())!=EOF && !isalpha(c)) {
		/* do nothing more */
	}
	if (c==EOF) {
		return EOF;
	}
	/* ok, first character of next word has been found */
	W[len++] = c;
	while (len<limit && (c=getchar())!=EOF && isalpha(c)) {
		/* another character to be stored */
		W[len++] = c;
	}
	/* now close off the string */
	W[len] = '\0';
	return 0;
}