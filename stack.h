#include "LinkedList.h"
typedef struct stack Stack;

struct stack{
	int size;
	Node *top;
};



Stack createStack(void);
int push(Stack *, void *);
void * pop(Stack*);