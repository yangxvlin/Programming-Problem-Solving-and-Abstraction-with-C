#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char data_t;
typedef struct node node_t;
typedef struct list list_t;

struct list {
	node_t *head;
	node_t *tail;
};

struct node {
	data_t data;
	node_t *pre;
	node_t *next;
};

list_t *make_empty_list(void);
list_t *insert_head(list_t *list, char ch);
list_t *insert_tail(list_t *list, char ch);
list_t *delete_head(list_t *list);
list_t *delete_tail(list_t *list);

int main() {
	list_t *mylist;
	mylist = make_empty_list();
	
	char c;
	while (scanf("%c", &c) == 1) {
		mylist = insert_tail(mylist, c);
		mylist = insert_head(mylist, c);
		
	}
	
	while (mylist->head && mylist->tail) {
		mylist = delete_head(mylist);
		mylist = delete_tail(mylist);
	}

	return 0;
}

list_t *make_empty_list(void) {
	list_t *tmp;
	tmp = (list_t*)malloc(sizeof(list_t));
	assert(tmp != NULL);
	tmp->head = tmp->tail = NULL;
	return tmp;	
}

list_t *insert_head(list_t *list, char ch) {
	node_t *tmp;
	tmp = (node_t*)malloc(sizeof(node_t));
	
	tmp->data = ch;
	tmp->pre = list->head;
	tmp->next = list->head;
	
	list->head = tmp;
	
	if (list->tail == NULL) {
		list->tail = tmp;
	}
	
	return list;
}

list_t *insert_tail(list_t *list, char ch) {
	node_t *tmp;
	tmp = (node_t*)malloc(sizeof(node_t));
	
	tmp->data = ch;
	tmp->pre = list->tail;
	tmp->next = NULL;
	
	if (list->tail == NULL) {
		list->head = list->tail = tmp;
	} else {
		list->tail->next = tmp;
		list->tail = tmp;
	}
	
	return list;
}

list_t *delete_head(list_t *list) {
	node_t *tmp;
	tmp = list->head;
	printf("%c ", list->head->data);
	list->head = list->head->next;
	
	free(tmp);
	tmp = NULL;
	return list;
}


list_t *delete_tail(list_t *list) {
	node_t *tmp;
	tmp = list->tail;
	printf("%c ", list->tail->data);
	list->tail = list->tail->pre;
	
	free(tmp);
	tmp = NULL;
	return list;
}
