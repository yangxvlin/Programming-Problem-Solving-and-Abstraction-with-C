/* Break the input up into a sequence of words, and only report
   the unique ones.
*/
#include <stdio.h>
#include <string.h>

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

#include "getword.c"