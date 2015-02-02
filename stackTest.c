#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "expr_assert.h"
#include "string.h"
#include <ctype.h>


void test_createStack_creates_new_stack(){
	Stack s1 = createStack();
	assertEqual((int)s1.top,'\0');
	assertEqual(s1.size,0);
}
//int push(Stack, void *);
void test_push_element_will_add_element_in_stack(){
	Stack s = createStack();
	int data1 = 3;
	assertEqual(push(&s,&data1),1);
	assertEqual(*(int*)s.top->std_id,data1);
}

// void * pop(Stack );
void test_pop_deletes_the_data_from_the_top_of_stack(){
	Stack s = createStack();
	int data1 = 3;
	int data2 = 4;
	int data3 = 4;
	push(&s,&data1);
	push(&s,&data2);
	push(&s,&data3);
	assertEqual(*(int*)s.top->std_id,data3);
	assertEqual(*(int*)pop(&s),data3);
	assertEqual(*(int*)s.top->std_id,data2);
	assertEqual(*(int*)pop(&s),data2);
	assertEqual(*(int*)s.top->std_id,data1);
	assertEqual(*(int*)pop(&s),data1);
	assertEqual((int)s.top,0);
	assertEqual((int)pop(&s),0);
}
