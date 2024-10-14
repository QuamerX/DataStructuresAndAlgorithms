#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>

typedef int DATA_TYPE;

struct Node
{
	int data;
	struct Node* next;
};

typedef struct 
{
	struct Node* head;
	struct Node* tail;
	uint32_t length;
}LinkedList_t;

LinkedList_t* LinkedList_Create(void);

void LinkedList_Destroy(LinkedList_t* handle);

void LinkedList_Display(LinkedList_t* handle);

DATA_TYPE LinkedList_Max(LinkedList_t* handle);

/**
 *  We cannot use Binary Search on linked list 
 *  because we cannot directly access the middle element 
 */
struct Node* LinkedList_Search(LinkedList_t* handle, DATA_TYPE data);

#endif /* LINKED_LIST_H */