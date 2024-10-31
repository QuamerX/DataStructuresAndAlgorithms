#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdint.h>

typedef int DOUBLE_LL_DATA_TYPE;

struct Double_LL_Node
{
	DOUBLE_LL_DATA_TYPE data;
	struct Double_LL_Node* prev;
	struct Double_LL_Node* next;
};

typedef struct 
{
	struct Double_LL_Node* head;
	struct Double_LL_Node* tail;
	uint32_t length;
}DoubleLinkedList_t;

DoubleLinkedList_t* DoubleLinkedList_Create(void);

void DoubleLinkedList_Destroy(DoubleLinkedList_t* handle);

void DoubleLinkedList_Display(DoubleLinkedList_t* handle);

/**
 *  Time Complexity = O(n)
 *
 *  Traversing whole list starting from head
 */
DOUBLE_LL_DATA_TYPE DoubleLinkedList_Max(DoubleLinkedList_t* handle);

struct Double_LL_Node* DoubleLinkedList_CreateNode(DOUBLE_LL_DATA_TYPE data);

int8_t DoubleLinkedList_InsertFirstNode(DoubleLinkedList_t* handle, DOUBLE_LL_DATA_TYPE data);

int8_t DoubleLinkedList_DeleteLastNode(DoubleLinkedList_t* handle);

/**
 *  Time Complexity = O(1)
 *
 */
int8_t DoubleLinkedList_InsertAtHead(DoubleLinkedList_t* handle, DOUBLE_LL_DATA_TYPE data);

/**
 *  Time Complexity = O(1)
 *
 */
int8_t DoubleLinkedList_InsertAtTail(DoubleLinkedList_t* handle, DOUBLE_LL_DATA_TYPE data);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if index is 0
 *  - Max = O(n) if index is lenght of the list
 */
int8_t DoubleLinkedList_InsertAtIndex(DoubleLinkedList_t* handle, DOUBLE_LL_DATA_TYPE data, uint32_t index);

/**
 *  Time Complexity = O(1)
 *
 *  We hold the head node so its simple to delete head
 */
int8_t DoubleLinkedList_DeleteAtHead(DoubleLinkedList_t* handle);

/**
 *  Time Complexity = O(1)
 * 
 *  We hold the tail node so its simple to delete tail
 */
int8_t DoubleLinkedList_DeleteAtTail(DoubleLinkedList_t* handle);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if index is 0
 *  - Max = O(n) if index is lenght of the list
 */
int8_t DoubleLinkedList_DeleteAtIndex(DoubleLinkedList_t* handle, uint32_t index);

/**
 *  Time Complexity = O(n)
 */
void DoubleLinkedList_Reverse(DoubleLinkedList_t* handle);

/**
 *  Time Complexity = O(n)
 */
void DoubleLinkedList_Reverse_SlidingPointers(DoubleLinkedList_t* handle);

/**
 *  Time Complexity = O(1)
 */
DoubleLinkedList_t* DoubleLinkedList_Concat(DoubleLinkedList_t* first, DoubleLinkedList_t* second);

/**
 *  Tortoise and Hare algorithm
 * 
 *  This algorithm starts with two pointers at the head
 *  Slow pointer will jump 1 element while fast pointer jumps 2 element
 *  If they ever meet at the same node this means there is a loop in Linked List.
 */
int8_t DoubleLinkedList_DetectLoop(DoubleLinkedList_t* handle);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if data is at the head
 *  - Max = O(n) if data is at the tail
 * 
 *  We cannot use Binary Search on linked list 
 *  because we cannot directly access the middle element 
 */
struct Double_LL_Node* DoubleLinkedList_Search(DoubleLinkedList_t* handle, DOUBLE_LL_DATA_TYPE data);

#endif /* DOUBLE_LINKED_LIST_H */