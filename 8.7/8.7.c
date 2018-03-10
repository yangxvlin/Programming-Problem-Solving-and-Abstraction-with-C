/*
823678 66
765876 94
904904 100
864876 48
785671 68
854565 89
*/

#include <stdio.h>

#define MAX_VAL 1000

typedef struct {
	int id;
	int mark;
} student_t;

int read_number(student_t student_info[]);
void student_sort(student_t student_info[], int num);
void print_array(student_t student_info[], int num);

int main() {
	int num = 0;
	student_t student[MAX_VAL];
	
	num = read_number(student);
	
	student_sort(student, num);
	print_array(student, num);
}

void print_array(student_t student_info[], int num) {
	int i;
	printf("Studennt    Mark\n");
	for (i = 0; i < num; i++) {
		printf("%8d    %4d\n", student_info[i].id, student_info[i].mark);
	}
}

void student_sort(student_t student_info[], int num) {
	int i, j, tmp_val, tmp_freq;
	
	for (i = 0; i < num; ++i) {
		for (j = i; j < num; ++j) {
			if (student_info[i].id > student_info[j].id) {
				tmp_val = student_info[i].id;
				student_info[i].id = student_info[j].id;
				student_info[j].id = tmp_val;
				
				tmp_freq = student_info[i].mark;
				student_info[i].mark = student_info[j].mark;
				student_info[j].mark = tmp_freq;
			}
		}
	}
}

int read_number(student_t student_info[]) {
	int i = 0, student, mark, excess = 0;
	
	while (scanf("%d %d", &student, &mark) && (student != 4)) {
		if (i == MAX_VAL) {
			excess++;
		}
		else {
			student_info[i].id = student;
			student_info[i].mark = mark;
			i++;
		}
	}
	
	printf("%d values read into array\n", i);
	if (excess) {
		printf("%d values not read into array\n", excess);
	}
	return i;
}

