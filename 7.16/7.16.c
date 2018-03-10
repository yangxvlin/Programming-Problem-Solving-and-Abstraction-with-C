/* Break the input up into a sequence of words, and only report
   the unique ones.
   
test example:
Mary had a little lamb, little lamb, little lamb,
Mary had a little fourleggedwhitefluffything.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXCHARS 10      /* Max chars per word */
#define MAXWORDS 1000    /* Max distinct words */

typedef char word_t[MAXCHARS+1];
int getword(char W[], int limit);

int
main(int argc, char *argv[]) {
	word_t one_word, all_words[MAXWORDS];
	int numdistinct=0, totwords=0, i, found;
	int freq[MAXWORDS];
	
	while (getword(one_word, MAXCHARS) != EOF) {
		totwords = totwords+1;
		/* linear search in array of previous words... */
		found = 0;
		
		for (i=0; i<numdistinct && !found; i++) {
			found = (strcmp(one_word, all_words[i]) == 0);
			if (found) {
				freq[i]++;
			}
		}
		
		if (!found && numdistinct<MAXWORDS) {
			strcpy(all_words[numdistinct], one_word);
			freq[numdistinct] = 1;
			numdistinct += 1;
		}
		/* NB - program silently discards words after
		   MAXWORDS distinct ones have been found */
	}
	printf("%d words read\n", totwords);
	printf("%d\n", numdistinct);


	/*print the frequency of each word*/
	for (i=0; i<numdistinct; i++) {
		printf("word #%d is \'%s\' with frequenct: %d\n", i, all_words[i], freq[i]);
	}

	/*
	printf("word #%d is \"%s\" with frequenct: %d\n", 0, all_words[1], freq[1]);

	printf("word #%d is \"%s\" with frequenct: %d\n", 1, all_words[1], freq[1]);
	printf("word #%d is \"%s\" with frequenct: %d\n", 2, all_words[2], freq[2]);
	printf("word #%d is \"%s\" with frequenct: %d\n", 3, all_words[3], freq[3]);
	printf("word #%d is \"%s\" with frequenct: %d\n", 4, all_words[4], freq[4]);
	printf("word #%d is \"%s\" with frequenct: %d\n", 5, all_words[5], freq[5]);
	printf("word #%d is \"%s\" with frequenct: %d\n", 6, all_words[6], freq[6]);
	printf("word #%d is \"%s\" with frequenct: %d\n", 7, all_words[7], freq[7]);
	*/
	return 0;
}

int getword(char W[], int limit) {
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


