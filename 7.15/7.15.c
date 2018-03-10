#include <stdio.h>
#include <string.h>

void frequency_sort(int arr[][2], int n);
void swap(int arr[][2], int n1, int n2);
int max(int arr[][2], int n);
int same_frequency(int freq1[][2], int freq2[][2], int n);
int frequency(char *word, int freq[][2], int n);
int is_anagram(char *p1, char *p2);
void test(char *p1[], int n);
int combination(char *p[], char *result[][2], int n);
int combination_number (int n, int m);
int factorial(int n);

int main() {
	char *w1[6] = {"luster", "result", "ulster", "rustle", "av", "123456789000"};
	test(w1, 6);
	
	char *w2[3] = {"programming is fun", "prof margin musing", "manuring from pigs"};
	test(w2, 3);
}

int factorial(int n) {
	int i, multiple = 1;
	
	for (i = n; i > 1; i--) {
		multiple *= i;
	}
	
	return multiple;
}

int combination_number (int n, int m) {
	return factorial(n) / (factorial(n - m) * factorial(m));
}

int combination(char *p[], char *result[][2], int n) {
	int num = 0, i, j;
	
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			result[num][0] = p[i];
			result[num][1] = p[j];
			num++;
		}
	}
	
	return num;
}

void test(char *p1[], int n) {
	int combnation_num, i, comb_num = combination_number(n, 2);
	//printf("%d\n", comb_num);
	char *possibility[comb_num][2];
	
	combnation_num = combination(p1, possibility, n);
	//test(w1, w2);
	for (i = 0; i < combnation_num; i++) {
		printf("%d: %s and %s is %d\n", i, possibility[i][0], possibility[i][1],
			is_anagram(possibility[i][0], possibility[i][1]));
	}
	//printf("%s with %s is %d", p1, p2, is_anagram(p1, p2));
	
	putchar('\n');
}

int is_anagram(char *p1, char *p2) {
	int word1_len = strlen(p1), word2_len = strlen(p2);
	
	if (word1_len == word2_len) {
		int freq_w1[word1_len][2], freq_w2[word2_len][2], char_len_w1, char_len_w2;
		char_len_w1 = frequency(p1, freq_w1, word1_len);
		char_len_w2 = frequency(p2, freq_w2, word2_len);
		
		if ((char_len_w1 == char_len_w2) && (same_frequency(freq_w1, freq_w2, char_len_w2))) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

int frequency(char *word, int freq[][2], int n) {
	int num = 0, i, new_word = 1;
	while (*word != '\0') {
		if (num == 0) {
			freq[num][0] = *word;
			freq[num][1] = 1;
			num++;
		}
		else {
			new_word = 1;
			
			for (i = 0; i < num; i++) {
				if (freq[num][0] == *word) {
					new_word = 0;
					freq[num][1]++;
					break;
				}
			}
			
			if (new_word) {
				freq[num][0] = *word;
				freq[num][1] = 1;
				num++;
			}
		}
		
		word++;
	}
	
	return num;
}

int same_frequency(int freq1[][2], int freq2[][2], int n) {
	frequency_sort(freq1, n);
	frequency_sort(freq2, n);
	
	int i;
	
	for (i = 0; i < n; i++) {
		if ((freq1[i][0] != freq2[i][0]) || (freq1[i][1] != freq2[i][1])) {
			return 0;
		}
	}
	
	return 1;
}

int max(int arr[][2], int n) {
	int index, i, max_ch;
	for (i = 0; i <= n; i++) {
		if (i == 0) {
			index = i;
			max_ch = arr[i][0];
		}
		else if (arr[i][0] > max_ch) {
			max_ch = arr[i][0];
			index = i;
		}
	}
	
	return index;
}

void swap(int arr[][2], int n1, int n2) {
	int tmp;
	tmp = arr[n1][0];
	arr[n1][0] = arr[n2][0];
	arr[n2][0] = tmp;
	
	tmp = arr[n1][1];
	arr[n1][1] = arr[n2][1];
	arr[n2][1] = tmp;
}

void frequency_sort(int arr[][2], int n) {
	int i, max_ch, index;
	for (i = n - 1; i > 0; i--) {
		index = max(arr, i);
		
		if ((index != i)&& (arr[index][0] != arr[i][0])) {
			swap(arr, index, i);
		}
	}
}

