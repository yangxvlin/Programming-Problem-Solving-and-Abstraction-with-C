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

void print_foot_list(list_t *list);
void print_head_list(list_t *list);
int is_list_element(list_t *list, data_t value);
int cmp(data_t value, data_t data);
list_t *insert_at_foot(list_t *list, data_t value);
list_t *insert_at_head(list_t *list, data_t value);
list_t *make_empty_list(void);

int main() {
	list_t *list;
	list_t *list2;
	int i;
	list = make_empty_list();
	for (i = 0; i < 10; i++) {
		list = insert_at_head(list, i);
		//list2 = insert_at_foot(list2, i*i);
		//printf("%d %d\n", i, list->head->data);
	}
	for (i = 0; i < 10; i++) {
		//list = insert_at_head(list, i);
		list = insert_at_head(list2, i);
		list2 = insert_at_foot(list2, i*i);
		//printf("%d %d\n", i, list2->head->data);
	}
	//print_list(list);
	//printf("%d\n", list->head->next->data);
	//printf("%d\n", is_list_element(list, 9));
	printf("%d\n", is_list_element(list, 10));
	printf("%d\n", is_list_element(list2, 81));
	//print_head_list(list);
	//print_head_list(list2);
}

void print_head_list(list_t *list) {
	//printf("%d\n", list->foot->next);
	while (list->head->next != NULL) {
		printf("%d ", list->head->data);
		list->head = list->head->next;
		//list -= sizeof(*list);
		//printf("%d %d\n",sizeof(list), sizeof(*list));
		//list = list->head->next;
	}
	printf("\n");
}

void print_foot_list(list_t *list) {
	while (list->foot->next != NULL) {
		printf("%d ", list->foot->data);
		list->foot = list->foot->next;
		//list -= sizeof(*list);
		//printf("%d %d\n",sizeof(list), sizeof(*list));
		//list = list->head->next;
	}
	printf("\n");
}

int is_list_element(list_t *list, data_t value) {
	while (1) {
		if (cmp(list->head->data, value) == 0) {
			return 1;
		} else if (list->head->next == NULL) {
			return 0;
		}
		//printf("%d %d\n",cmp(list->foot->data, value), list->foot->next);
		list->head = list->head->next;
	}
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

list_t *make_empty_list(void) {
	list_t *list;
	list = (list_t*)malloc(sizeof(*list));
	assert(list != NULL);
	list->head = list->foot = NULL;
	return list;
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

