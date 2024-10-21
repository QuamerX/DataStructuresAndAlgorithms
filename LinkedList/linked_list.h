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

/**
 *  Time Complexity = O(n)
 *
 *  Traversing whole list starting from head
 */
DATA_TYPE LinkedList_Max(LinkedList_t* handle);

struct Node* LinkedList_CreateNode(DATA_TYPE data);

void LinkedList_InsertFirstNode(LinkedList_t* handle, DATA_TYPE data);

/**
 *  Time Complexity = O(1)
 *
 *  We hold the head node so its simple to insert at head
 */
int8_t LinkedList_InsertAtHead(LinkedList_t* handle, DATA_TYPE data);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if we hold the tail node
 *  - Max = O(n) if we don't hold the tail node and have to reach the end starting from head node
 */
int8_t LinkedList_InsertAtTail(LinkedList_t* handle, DATA_TYPE data);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if index is 0
 *  - Max = O(n) if index is lenght of the list
 */
int8_t LinkedList_InsertAtIndex(LinkedList_t* handle, DATA_TYPE data, uint32_t index);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if data is at the head
 *  - Max = O(n) if data is at the tail
 * 
 *  We cannot use Binary Search on linked list 
 *  because we cannot directly access the middle element 
 */
struct Node* LinkedList_Search(LinkedList_t* handle, DATA_TYPE data);

#endif /* LINKED_LIST_H */