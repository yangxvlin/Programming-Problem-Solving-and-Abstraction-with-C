#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print_arry(char arr[], int n);
int cut_string(char str1[], char str2[], char origin[], int n);
int is_palindrome(char *address);
int character_only(char *origin, char processed[]);

int main() {
	char *string1 = "rats live on no evil star";
	char *string2 = "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal - Panama!";
	char *string3 = "rats live on a no evil star";
	char *string4 = "aa";
	char *string5 = "aaa";
	char *string6 = "a";
	
	printf("%d\n", is_palindrome(string1));
	printf("%d\n", is_palindrome(string2));
	printf("%d\n", is_palindrome(string3));
	printf("%d\n", is_palindrome(string4));
	printf("%d\n", is_palindrome(string5));
	printf("%d\n", is_palindrome(string6));
}

int is_palindrome(char *address) {
	int i, standardized_len = 0, len = strlen(address), half;
	char standardized[len];
	
	standardized_len = character_only(address, standardized);
	
	char left[standardized_len / 2], right[standardized_len / 2];
	
	half = cut_string(left, right, standardized, standardized_len);

	i = strncasecmp(&left[0], &right[0], half);
	
	if (i == 0) {
		return 1;
	}
	else {
		return 0;
	}

}

int character_only(char *origin, char processed[]) {
	int i, processed_size = 0;

	for (i = 0; i < strlen(origin); i++) {
		if ((((64 < *(origin + i)) && (*(origin + i) < 91)) ||
			((96 < *(origin + i)) && (*(origin + i) < 123))) && (*(origin + i) != ' ')) {
			
			processed[processed_size] = *(origin + i);
			processed_size++;
		}
	}

	return processed_size;
}

int cut_string(char str1[], char str2[], char origin[], int n) {
	int i, mid;
	
	for (i = 0; i < n; i++) {
		if (((n % 2 == 0) && (i < n / 2)) || ((n % 2 == 1) && (i <= n / 2))) {
			str1[i] = origin[i];
		}
		
		if (((n % 2 == 0) && (i >= n / 2))|| ((n % 2 == 1) && (i >= n / 2))) {
			str2[n - i - 1] = origin[i];
		}
	}
	
	return n / 2;
}

void print_arry(char arr[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%c", arr[i]);
	}
	
	putchar('#');
	putchar('\n');
}
