/* Nested structures.
*/
#include <stdio.h>

#define NAMESTRLEN 40
#define MAXSUBJECTS 8
#define MAXSTAFF 50

typedef char namestr[NAMESTRLEN+1];

typedef struct {
	namestr     given, others, family;
} fullname_t;

typedef struct {
	int         yy, mm, dd;
} date_t;

typedef struct {
	int         subjectcode;
	date_t      enrolled;
	int         status;
	int         finalmark;
} subject_t;

typedef struct {
	fullname_t  name;
	int         employeenumber;
	date_t      dob;
	date_t      datecommenced;
	int         status;
	int         annualsalary;
} staff_t;

typedef struct {
	fullname_t  name;
	int         studentnumber;
	date_t      dob;
	int         nsubjects;
	subject_t   subjects[MAXSUBJECTS];
} student_t;

void print_people(staff_t people[], int n);
void sort_staff_by_number(staff_t people[], int nval);

int
main(int argc, char *argv[]) {
	staff_t people[MAXSTAFF];
	char *p1 = "Yang";
	int counter = 0;
	while ((*p1 != '\0') && (counter < NAMESTRLEN)) {	
		people[0].name.family[counter] = *p1;
		p1++;
		counter++;
	}
	people[0].name.family[counter] = '\0';
	people[0].employeenumber = 1;
	people[0].dob.yy = 1999;
	people[0].dob.mm = 9;
	people[0].dob.dd = 27;
	people[0].datecommenced.yy = 2010;
	people[0].status = 0;
	people[0].annualsalary = 1000000;
	
	char *p2 = "Xulin";
	counter = 0;
	while ((*p2 != '\0') && (counter < NAMESTRLEN)) {	
		people[1].name.given[counter] = *p2;
		p2++;
		counter++;
	}
	people[1].name.given[counter] = '\0';
	people[1].employeenumber = 0;
	people[1].dob.yy = 1998;
	people[1].dob.mm = 9;
	people[1].dob.dd = 27;
	people[1].datecommenced.yy = 2017;
	people[1].status = 99;
	people[1].annualsalary = 9000000;
	
	sort_staff_by_number(people, 2);
	print_people(people, 2);
	
	return(0);
}

void print_people(staff_t people[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("name: %s %s %s\n", people[i].name.given, people[i].name.others, people[i].name.family);
		printf("id: %d, birth: %2d/%2d/%d\n", people[i].employeenumber, people[i].dob.dd, people[i].dob.mm, people[i].dob.yy);
		printf("work since: %2d/%2d/%d\n", people[i].datecommenced.dd, people[i].datecommenced.mm, people[i].datecommenced.yy);
		printf("status: %d, annualsalary: %d\n\n", people[i].status, people[i].annualsalary);
	}
}

void sort_staff_by_number(staff_t people[], int nval) {
	int i;
	staff_t tmp;
	
	for (i = 0; i < nval - 1; i++) {
		if (people[i].employeenumber > people[i + 1].employeenumber) {
			tmp = people[i];
			people[i] = people[i + 1];
			people[i + 1] = tmp;
		}
	}
}

