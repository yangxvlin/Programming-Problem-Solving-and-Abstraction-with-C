#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//typedef int data_t;
typedef struct node node_t;

struct node {
	void *data;
	node_t *next;
	size_t n;
};

typedef struct {
	node_t *head;
	node_t *foot;
} list_t;

list_t *make_empty_list(void);
list_t *insert_in_order(node_t *new, list_t *list);
list_t *insert_at_head(node_t *new, list_t *list);
void *insert_at_foot(node_t *new, node_t *foot, node_t *before);
void *insert_at_before(node_t *new, node_t *element, node_t *before);
int recursive_compare(void *new_data, void *list_data);
void *recursive_insert(node_t *new, node_t *element, node_t *before);
void print_list(list_t *list);

int main() {
	list_t *list;
	list = make_empty_list();
	printf("%d\n", list->head);
	printf("input words:\n");
	char c;
	node_t *new;
	
	while ((c = getchar()) != EOF) {
		if (new == NULL) {
			new = (node_t*)malloc(sizeof(*new));
			new->n = 0;
			new->next = NULL;
			printf("%d\n", new);
		}
		//printf("%c ", c);
		if (c != '\n') {
			new->data = (void*)malloc(sizeof(char*));
			//printf("%c ", c);
			*(char*)new->data = c;
			//printf("%c ", c);
			new->data++;
			new->n++;
			//printf("%c %d %s\n", c, new->n, new->data);
		}
		//} else {
		//new->data = (void*)malloc(sizeof(char*));
		if (c == '\n') {
			*(char*)new->data = '\0';
			//new->data++;
			new->n++;
			list = insert_in_order(new, list);
			//printf("%s\n", list->head->data);
			free(new);
		}
	}
	print_list(list);
}

void print_list(list_t *list) {
	printf("%d %d\n", list->head, list->foot);
	/*
	while (list->head != list->foot->next) {
		printf("%d\n", list->head);
		printf("%d %s\n", list->head->n, list->head->data);
		list->head = list->head->next;
	}
	*/
}

list_t *insert_in_order(node_t *new, list_t *list) {
	assert(list != NULL);
	if ((list->head == NULL) && (list->foot == NULL)) {
		list->head = new;
		list->foot = new;
		return list;
	} else {
		if (recursive_compare(new->data, list->head->data) == -1) {
			return insert_at_head(new, list);
		} else {
			recursive_insert(new, list->head->next, list->head);
			return list;
		}
	}
}

list_t *insert_at_head(node_t *new, list_t *list) {
	new->next = list->head;
	list->head = new;
	return list;
}

void *insert_at_foot(node_t *new, node_t *foot, node_t *before) {
	foot->next = foot;
	foot = new;
	before->next = foot;
 }

void *insert_at_before(node_t *new, node_t *element, node_t *before) {
	element->next = element;
	element = new;
	before->next = element;
}
 
int recursive_compare(void *new_data, void *list_data) {
	if (*(char*)new_data == '\0') {
		return -1;
	}
	
	if (*(char*)list_data == '\0') {
		return 1;
	}
	
	if (*(char*)new_data < *(char*)list_data) {
		return -1;
	}
	
	if (*(char*)new_data > *(char*)list_data) {
		return 1;
	}
	
	if (*(char*)new_data == *(char*)list_data) {
		recursive_compare(new_data++, list_data++);
	}
}

void *recursive_insert(node_t *new, node_t *element, node_t *before) {
	if (element->next == NULL) {
		insert_at_foot(new, element, before);
		//return;
	}
	
	if (recursive_compare(new->data, element->data) == -1) {
			return insert_at_before(new, element, before);
	} else {
		recursive_insert(new, element->next, before->next);
	}
}

list_t *make_empty_list(void) {
	list_t *list;
	list = (list_t*)malloc(sizeof(*list));
	assert(list != NULL);
	list->head = list->foot = NULL;
	return list;
}


/*
int readword(char word[]) {
	int c = 0, len = 0;
	
	while (((c = getchar()) != EOF) && !isalpha(c)) {
	}
	
	if (c == EOF) {
		return EOF;
	}
	word[len] = c;
	len++;
	while (((c = getchar()) != EOF) && !isalpha(c)) {
		word[len] = c;
		len++;
	}
	word[len] = '\0';
	return len++;
}
*/
