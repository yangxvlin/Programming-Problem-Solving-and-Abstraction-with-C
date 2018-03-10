#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("Enter text: ");
	
	bool inaword;
	char character, last_character;
	int chr = 0, len, false_to_true = 0;
	
	while((scanf("%c", &character) == 1) && (character != 4)) {
		
		if((character == ' ') || (character == '\n')) {
			inaword = 0;
			chr++;

			if(((64 < last_character) && (last_character < 91)) || 
			   ((96 < last_character) && (last_character < 123))) {
				inaword = 1;
			}
			
			if(inaword) {
				false_to_true++;
			}
		}
		last_character = character;
		
	}
	printf("Possible_words:%9d\nQualified_words:%8d", chr, false_to_true);
}