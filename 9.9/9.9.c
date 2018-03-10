#include <stdio.h>
#include <math.h>

typedef struct{
	char ch[3];
	int number;
} rec_t;

void hanoi(char from, char free, char to, int n);
void iter_hanoi(char *from, char *free, char *to, int n);
void print_rec(rec_t rec[], int n);
void pop_stack(rec_t stack[], int num);
void push_stack(rec_t stack[], char from, char free, char to, int space, int location);
void preparation(char *from, char *free, char *to);
void solution(char *from, char *free, char *to);


int main() {
	hanoi('A', 'B', 'C', 4);
	printf("------------------------\n");
	
	char a = 'A', b = 'B', c = 'C';
	char *p1, *p2, *p3;
	p1 = &a;
	p2 = &b;
	p3 = &c;
	iter_hanoi(p1, p2, p3, 4);
}

void hanoi(char from, char free, char to, int n) {
	 int i;
	 
	if (n == 0) {
		return;
	}
	
	hanoi(from, to, free, n-1);
	
	for (i = 1; i < n; i++) {
		printf("   |");
	}
	printf("%d move from %c to %c\n",n, from, to);
	hanoi(free, from, to, n-1);
}

void iter_hanoi(char *from, char *free, char *to, int n) {
	int i = 0, j, k,m, counter = 0, second_rec_counter = 0, start = 0, end = 0;
	char tmp;
	int max = pow(2, n) - 1;
	//printf("%d\n", max);
	rec_t rec[max];
	rec_t stack[max];
	stack[0].number = n;
	stack[0].ch[0] = *from;
	stack[0].ch[1] = *free;
	stack[0].ch[2] = *to;
	
	while (i >= 0) {
		while (stack[i].number>1) {
			//preparation(from, free, to);
			push_stack(stack, stack[i].ch[0], stack[i].ch[2], stack[i].ch[1], stack[i].number, i+1);
			//preparation(from, free, to);
			//printf("%d %c %c %c\n", stack[i].number, stack[i].ch[0], stack[i].ch[1], stack[i].ch[2]);
			//printf("pre %c %c %c\n", stack[i].ch[0], stack[i].ch[1], stack[i].ch[2]);
			i++;
			end++;
		}
		
		if (stack[i].number == 1) {
			//printf("%d ",i);
			pop_stack(stack, i);
			i--;
		}
		
		if (i >= 0) {
			//printf("%d ",i);
			pop_stack(stack, i);
			i--;
			//printf("sol %c %c %c\n", *from, *free, *to);
			//solution(from, free, to);
			//printf("*sol %c %c %c\n", stack[i+1].ch[0], stack[i+1].ch[1], stack[i+1].ch[2]);
			push_stack(stack, stack[i+1].ch[1], stack[i+1].ch[0], stack[i+1].ch[2], stack[i+1].number, i+1);
			//printf("%d %c %c %c\n", stack[i].number, stack[i].ch[0], stack[i].ch[1], stack[i].ch[2]);
			//printf("sol %c %c %c\n", stack[i+1].ch[0], stack[i+1].ch[1], stack[i+1].ch[2]);
			i++;
			end++;
		}
		/*
		printf("%d %d\n",i, end);
		print_rec(rec, end);
		printf("***------\n");
		print_rec(stack, end);
		printf("---------\n");
		
		if (i > n) {
			break;
		}
		*/
	}
	
	//printf("##############\n");
	//print_rec(stack, end);
}

void pop_stack(rec_t stack[], int num) {
	int i;
	
	for (i = stack[num].number; i > 1; i--) {
		printf("   |");
	}
	printf("%d move from %c to %c\n", stack[num].number, stack[num].ch[0], stack[num].ch[2]);
}

void push_stack(rec_t stack[], char from, char free, char to, int number, int location) {
	stack[location].ch[0] = from;
	stack[location].ch[1] = free;
	stack[location].ch[2] = to;
	stack[location].number = number-1;
}

void preparation(char *from, char *free, char *to) {
	char tmp;
	tmp = *free;
	*free = *to;
	*to = tmp;
}

void solution(char *from, char *free, char *to) {
	char tmp;
	tmp = *free;
	*free = *from;
	*from = tmp;
	/*
	tmp = *to;
	*to = *from;
	*from = tmp;
	*/
}

void print_rec(rec_t rec[], int n) {
	int i, k;
	
	for (i = 0; i < n; i++) {
		/*
		for (k = 1; k < rec[i].number; k++) {
			printf("   |");
		}
		*/
		printf("move from %c to %c\n", rec[i].ch[0], rec[i].ch[2]);
	}
}

