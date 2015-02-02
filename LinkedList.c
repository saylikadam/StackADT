#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList createList(void){
	LinkedList list = {NULL,NULL,0};
	if(0 == list.count){
		return list;	
	}
	return list;	
}

Node * create_node(void *data){
	Node *newNode = malloc( sizeof(Node));
	newNode->std_id = data;
	newNode->next = NULL;
	return newNode;
}

int add_to_list(LinkedList *list,Node *node1){
	if(list->head == NULL)
		list->head = node1;
	else{
		list->tail->next = node1;
	}
	list->tail = node1;
	list->tail->next  = 0;
	list->count++;
	return 1;
}

void *get_first_element(LinkedList list){
		return list.head->std_id;
}

void *get_last_element(LinkedList list){
	return list.tail->std_id;
}

void traverse(LinkedList list, void (*addFunc)(void *data)){
	Node *walker = list.head;
	while(walker != NULL){
		addFunc((void *)walker->std_id);
		walker = walker->next;
	}
}

void *getElementAt(LinkedList list, int index){
	int i = 0;
	Node *walker = list.head;
	while(walker != NULL){
		if(i == index){
			return walker->std_id;
		}
		i++;
		walker = walker->next;
	}
	return NULL;
}

int indexOf(LinkedList list, void *data){
	Node *walker = list.head;
	while(walker != NULL){
		if(data == walker->std_id)
			return (int)walker->std_id;
		walker = walker->next;
	}
	return -1;
}


int asArray(LinkedList list, void **array){
	int count = 0;
	while(count<list.count){
		array[count] = getElementAt(list,count);
		count++;
	}
	return count;
}

LinkedList * filter(LinkedList list, int (*func)(void *)){
	Node *walker = list.head;		
	LinkedList *newList = calloc( 1, sizeof(list));
	while(walker != NULL){
		if(func(walker->std_id)){
			add_to_list(newList, create_node(walker->std_id));
		}
		walker = walker->next;
	}
	newList->tail->next = 0;
	return newList;
}

void * deleteElementAt(LinkedList* list, int index){
	int i = 0;	
	void* deletedData; 
	Node *firstNode = list->head,*previousNode = 0;

	if(index < 0 || index >= list->count)
		return 0;

	for(i = 0 ;i< index ;i++){
		previousNode = firstNode;
		firstNode = firstNode->next;
	}

	deletedData = firstNode->std_id;
	previousNode?(previousNode->next =firstNode->next):(list->head =list->head->next);
	
	list->count--;
	return deletedData;

	// previousNode->next = firstNode->next;
	// list->head = list->head->next;

}

