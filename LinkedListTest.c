#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "expr_assert.h"
#include "string.h"
#include <ctype.h>
void test_createList_creates_empty_LinkedList(){
	LinkedList ret = createList();
	LinkedList expected = {NULL,NULL,0};
	assert(ret.count == expected.count);
    assert(ret.head == expected.head);
}

void test_create_node_creates_new_node(){
	int x=10;
	Node *p = create_node((void *)&x);
	assertEqual(*((int *)p->std_id),10);
	assertEqual(((int)p->next),'\0');
	free(p);
}

void test_add_to_list_will_add_a_node_to_list(){
	int x = 10;
	Node *node1 = create_node((void *)&x);
	LinkedList list = createList();
	assertEqual(add_to_list(&list, node1),1);
	assertEqual(*(int*)list.head->std_id,10);
	assertEqual(list.count,1);
}

void test_add_to_list_adds_node_to_linked_list_and_add_resets_head_tail_and_count_for_int_node() {
	int data = 20;
	char data2 = 'A';
	Node* node = create_node((void*)&data);
	Node* node2 = create_node((void*)&data2);
	LinkedList list = createList();

	assertEqual(add_to_list(&list,node), 1);
	assertEqual(list.count,1);
	assertEqual(*(int*)list.head->std_id,data);
	assertEqual((int)node,(int)list.tail);
	assertEqual((int)((Node*)list.tail)->next,0);

	assertEqual(add_to_list(&list,node2),1);
	assertEqual(list.count,2);
	assertEqual((int)node,(int)list.head);
	assertEqual((int)node2,(int)list.tail);
	assertEqual((int)((Node*)list.tail)->next,0);
}

void test_get_first_element_will_get_the_first_node_from_list(){
	int data = 10,*result;
	Node* node = create_node((void*)&data);
	LinkedList list = createList();
	add_to_list(&list, node);
	result = get_first_element(list);
	assertEqual(*result,10);
}

void test_get_last_element_will_get_the_last_node_from_list(){
	int data = 10,*result;
	Node* node = create_node((void*)&data);
	LinkedList list = createList();
	add_to_list(&list, node);
	result = get_last_element(list);
	assertEqual(*result,10);
}
// void * getElementAt(LinkedList, int )

void add(void* data){
	*(int*)data = (*(int*)data) + 1;
}

void test_traverse_will_travel_through_all_nodes_and_retrieves_data(){
	int a = 10, b = 20;
	Node* node1 = create_node((void*)&a);
	Node* node2 = create_node((void*)&b);
	LinkedList list = createList();
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	traverse(list,add);
	assertEqual(*((int *)list.head->std_id),11);
}

void toLower(void* data){
	*(char*)data = tolower(*(char*)data);
}

void test_traverse_will_travel_through_all_nodes_and_retrieves_data_of_type_char(){
	char a = 'A', b = 'B';
	Node* node1 = create_node((void*)&a);
	Node* node2 = create_node((void*)&b);
	LinkedList list = createList();
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	traverse(list,toLower);
	assertEqual(*((char *)list.head->std_id),'a');
}

void test_get_Element_At_will_get_the_element_at_particular_position(){
	int a = 10, b = 20, c = 30, *result;
	Node* node1 = create_node((void*)&a);
	Node* node2 = create_node((void*)&b);
	Node* node3 = create_node((void*)&c);
	LinkedList list = createList();
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	result = getElementAt(list,0);
	assertEqual(*result,10);
}

void test_index_of_will_get_the_element_at_given_index(){
	int a = 10, b = 20, c = 10,*result;
	Node* node1 = create_node((void*)&a);
	Node* node2 = create_node((void*)&b);
	Node* node3 = create_node((void*)&c);
	LinkedList list = createList();
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	result = (int *)indexOf(list,(void*)&c);
	assertEqual((int)result,(int)&c);
}

void test_delete_will_delete_particular_element_from_list(){
	int a = 10, b = 20, c = 10,*result;
	Node* node1 = create_node((void*)&a);
	Node* node2 = create_node((void*)&b);
	Node* node3 = create_node((void*)&c);
	LinkedList list = createList();
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	result = deleteElementAt(&list,1);
	assertEqual(*result,20);
}

void test_asArray_will_return_the_number_of_elements_added_to_array(){
	int a = 10, b = 20, c = 30,*result;
	int array[3]; 
	Node* node1 = create_node((void*)&a);
	Node* node2 = create_node((void*)&b);
	Node* node3 = create_node((void*)&c);
	LinkedList list = createList();
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	result = (int*)asArray(list,(void**)&array);
	assertEqual((int)result,3);
	assertEqual(*(int*)array[0],10);
	assertEqual(*(int*)array[1],20);
	assertEqual(*(int*)array[2],30);
}

int isEven(void* data){
	return ((*(int *)data) % 2) == 0;
}

void test_filter_will_return_the_references_to_the_data(){
	int a = 10, b = 3, c = 6;
	int array[3]; 
	Node* node1 = create_node((void*)&a);
	Node* node2 = create_node((void*)&b);
	Node* node3 = create_node((void*)&c);
	LinkedList list = createList(),*result;
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);

	result = filter(list,&isEven);
	assertEqual(result->count,2);
	assertEqual(*(int*)result->head->std_id,a);
	assertEqual(*(int*)result->tail->std_id,c);

	free(node1);
	free(node2);
	free(node3);
}

void test_filter_returns_the_filtered_linked_list() {
	int data1 = 15,data2 = 20,data3 = 30;
	int* result;
	int* array[3];

	Node* n1 = create_node((void*)&data1);
	Node* n2 = create_node((void*)&data2);
	Node* n3 = create_node((void*)&data3);
	LinkedList list = createList(), *filtered;
	add_to_list(&list,n1);
	add_to_list(&list,n2);
	add_to_list(&list,n3);
	
	filtered = filter(list,&isEven);
	assertEqual(filtered->count,2 );
	assertEqual(*(int*)filtered->head->std_id,data2);
	assertEqual(*(int*)filtered->tail->std_id,data3);

	free(n1);
	free(n2);
	free(n3);
}
