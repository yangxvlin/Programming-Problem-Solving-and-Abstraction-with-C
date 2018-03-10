#include <stdio.h>

int main()
{
	printf("Enter text: ");
	
	char character;
	int line = 0, space = 0, chr = 0;
	while((scanf("%c", &character) == 1) && (character != 4))
	{
		if(character == '\n')
			line += 1;
		else if(character == ' ')
			space += 1;
		else
			chr += 1;
	}
	printf("Lines:%9d\nSpaces:%8d\nChars:%9d\n", line, space, chr);
}