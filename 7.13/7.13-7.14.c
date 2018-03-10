#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int my_strlen(char *p);
char *my_strcat(char *p1, char*p2);
int my_atoi(char *p);

int main() {
	char *str1 = "abcdefghijklmnopqrstuvwxyz";
	char *str2 = "";
	char *str3 = " ";
	char str4[100] = "my";
	char *str5 = "unimelb";
	char str6[100] = "hey hey";
	char *str7 = "";
	char *str8 = " ";
	char *str9 = "123546789123456789";
	char *str10 = "123546789123456789";
	
	printf("lib strlen = %d\n my_strlen = %d\n", strlen(str1), my_strlen(str1));
	printf("lib strlen = %d\n my_strlen = %d\n", strlen(str2), my_strlen(str2));
	printf("lib strlen = %d\n my_strlen = %d\n", strlen(str3), my_strlen(str3));
	
	my_strcat(&str4[0], str5);
	printf("%s", str4);
	printf("#\n");
	
	my_strcat(&str6[0], str7);
	printf("%s", str6);
	printf("#\n");
	my_strcat(&str6[0], str8);
	printf("%s", str6);
	printf("#\n");

	printf("%s: ", str9);
	int num;
	num = my_atoi(str9);
	printf("%d\n", num);
	printf("%s: ", str10);

	int num_1;
	num_1 = atoi(str10);
	printf("%d\n", num_1);
	
}

int my_strlen(char *p) {
	int len = 0;
	
	while (*(p++) != '\0') {
		len++;
	}
	
	return len;
}

char *my_strcat(char *p1, char*p2) {
	int flag = 1;
	char *tmp;
	tmp = p1;
	tmp += my_strlen(p1);
	while (*(p2) != '\0') {
		*(tmp) = *(p2);
		//printf("%s\n", p1);
		tmp++;
		p2++;
	}
	
	return p1;
}

int my_atoi(char *p) {
	int sign = 1, number = 0, sign_multiple = 1, valid_space = 1;
	
	if (p == NULL) {
		return number;
	}
	
	while (((isspace(*p)) && (valid_space)) || isdigit(*p) || (((*p == '+') || (*p == '-')) && (sign))) {
		if ((*p == '+') || (*p == '-')) {
			sign = 0;
			valid_space = 0;
			if (*p == '-') {
				sign_multiple = -1;
			}
		}
		
		if (isdigit(*p)) {
			valid_space = 0;
			number = number * 10 + sign_multiple * (*p - '0');
		}
		p++;
	}
	
	return number;
}
