#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// creates a Stack structure on which the following operations can be performed
Stack createStack(void){
	Stack s1 = {0,'\0'};
	if(s1.size == 0){
		return s1;
	}
	return s1;
}

int push(Stack* s,void* data){
	Node* n = create_node(data);
	if(s->size != 0){
		n->next = s->top;
	}
	s->top = n;
	s->size++;
	return 1;
}

void* pop(Stack* s){
	void* deleted_data;
	if(s->top == 0){
		return 0;
	}
	deleted_data= s->top->std_id;
	s->top = s->top->next;
	return deleted_data;
}