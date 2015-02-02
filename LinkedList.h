typedef struct linkedlist LinkedList;
typedef struct node Node;

struct linkedlist{
	Node *head;
	Node *tail;
	int count;
};

struct node{
	void  *std_id;
	Node *next;
};

LinkedList createList(void);
Node *create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList, void (*)(void *data));
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList*, int);
int asArray(LinkedList, void **);
LinkedList * filter(LinkedList, int (*)(void *));