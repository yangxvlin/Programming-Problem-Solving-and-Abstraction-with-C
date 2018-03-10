#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int data_t;
typedef struct node node_t;

struct node {
	data_t data;
	node_t *next;
};

typedef struct {
	node_t *head;
	node_t *foot;
} list_t;

list_t *make_empty_list(void);
list_t *insert_in_order(list_t *list, data_t value);
void print_free_list(list_t *list);
list_t *insert_at_head(list_t *list, data_t value);
list_t *insert_at_foot(list_t *list, data_t value);
int cmp(data_t value, data_t data);
node_t *recursive_insert(node_t *element, data_t value, node_t *before);

int main() {
	list_t *list;
	list = make_empty_list();
	
	int i;
	
	while (scanf("%d", &i) == 1) {
		list = insert_in_order(list, i);
		//printf("#%d\n", list->head->data);
	}
	
	print_free_list(list);
}

list_t *make_empty_list(void) {
	list_t *list;
	list = (list_t*)malloc(sizeof(*list));
	assert(list != NULL);
	list->head = list->foot = NULL;
	//list->foot->next = NULL;
	return list;
}

int cmp(data_t value, data_t data) {
	//printf("%d %d\n", value, data);
	if (value > data) {
		return 1;
	} else if (value < data) {
		return -1;
	} else if (value == data) {
		return 0;
	}
}

list_t *insert_in_order(list_t *list, data_t value) {
	if ((list->head == NULL) && (list->foot == NULL)) {
		node_t *new;
		new = (node_t*)malloc(sizeof(*new));
		new->data = value;
		new->next = NULL;
		list->foot = new;
		list->head = list->foot;
		printf("first value loaded\n");
		return list;
	}
	
	if ((cmp(list->head->data, value) == 0) || (cmp(list->head->data, value) == 1)) {
		return insert_at_head(list, value);
	} else {
		//new->next = list->head;
		recursive_insert(list->head, value, list->head);
		return list;
		//insert_in_order(list->head, value);
	}
	/*
	printf("%d %d %d %d %d\n", list->head->next, list->head, list->head->data, list->foot->next, list->foot);
	return list;
	*/
}

node_t *recursive_insert(node_t *element, data_t value, node_t *before) {
	//printf("%d ", element->data);
	if ((cmp(element->data, value) == -1) && (element->next != NULL)) {
		recursive_insert(element->next, value, element);
	} else {
		node_t *new;
		new = (node_t*)malloc(sizeof(*new));
		new->data = value;
		//new->next = NULL;
		if (element->next == NULL) {
			new->next = NULL;
			element = new;
			before->next = element;
		} else {
			new->next = element;
			element = new;
			before->next = element;
			//printf("\n");
		}
		return element;
	}
}

void print_free_list(list_t *list) {
	while (list->head != NULL) {
		//printf("%d %d ", list->foot, list->foot->next);
		printf("%d ", list->head->data);
		list->head = list->head->next;
	}
}

list_t *insert_at_foot(list_t *list, data_t value) {
	node_t *new;
	new = (node_t*)malloc(sizeof(*new));
	assert((list != NULL) && (new != NULL));
	new->data = value;
	new->next = NULL;
	
	if (list->foot == NULL) {
		list->foot = new;
		list->head = new;
	} else {
		list->foot->next = new;
		list->foot = new;
	}
	
	return list;
}

list_t *insert_at_head(list_t *list, data_t value) {
	node_t *new;
	new = (node_t*)malloc(sizeof(*list));
	assert((list != NULL) && (new != NULL));
	new->data = value;
	new->next = list->head;
	list->head = new;
	
	if (list->foot = NULL) {
		list->foot = new;
	}
	
	return list;
}


