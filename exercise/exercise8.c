#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node_t;
typedef int data_t;

struct node {
	data_t data;
	node_t *next;
};

node_t *make_empty_stack(node_t *p);
void push(node_t *head, int num);
void pop();

int main() {
	node_t *head = NULL;
	head = make_empty_stack(head);
	head->next = NULL;
	int a;
	while (scanf("%d", &a) == 1) {
	printf("%d ", a);
	push(head, a);
	//printf("%d\n", head->next->data);
	}
	printf("\n");
	
	pop(head->next);
	free(head);
	return 0;
}

node_t *make_empty_stack(node_t *p) {
	assert(p == NULL);
	
	if (p == NULL) {
		p = (node_t*)malloc(sizeof(node_t));
	}
	return p;
}

void push(node_t *head, int num) {
	node_t *tmp = NULL;
	tmp = make_empty_stack(tmp);
	tmp->data = num;
	if (!head->next) {
		tmp->next = NULL;
	} else {
		tmp->next = head->next;
	}
	head->next = tmp;
	//return head;
}

void pop(node_t *head) {
	node_t *tmp;
	printf("poping: \n");
	while (head) {
		tmp = head;
		printf("%d ", head->data);
		head = head->next;
		free(tmp);
		tmp = NULL;
	}
	free(tmp);
	printf("\npop finished\n");
}