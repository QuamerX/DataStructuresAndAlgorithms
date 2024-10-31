#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>

typedef int LL_DATA_TYPE;

struct LL_Node
{
	LL_DATA_TYPE data;
	struct LL_Node* next;
};

typedef struct 
{
	struct LL_Node* head;
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
LL_DATA_TYPE LinkedList_Max(LinkedList_t* handle);

struct LL_Node* LinkedList_CreateNode(LL_DATA_TYPE data);

void LinkedList_InsertFirstNode(LinkedList_t* handle, LL_DATA_TYPE data);

void LinkedList_DeleteLastNode(LinkedList_t* handle);

/**
 *  Time Complexity = O(1)
 *
 */
int8_t LinkedList_InsertAtHead(LinkedList_t* handle, LL_DATA_TYPE data);

/**
 *  Time Complexity = O(n)
 *
 *  Have to iterate through all list
 */
int8_t LinkedList_InsertAtTail(LinkedList_t* handle, LL_DATA_TYPE data);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if index is 0
 *  - Max = O(n) if index is lenght of the list
 */
int8_t LinkedList_InsertAtIndex(LinkedList_t* handle, LL_DATA_TYPE data, uint32_t index);

/**
 *  Time Complexity = O(1)
 *
 *  We hold the head node so its simple to delete head
 */
int8_t LinkedList_DeleteAtHead(LinkedList_t* handle);

/**
 *  Time Complexity = O(n)
 * 
 *  Since we don't hold the previous node's pointer like double linked list
 *  we have to go all the way to the tail.
 */
int8_t LinkedList_DeleteAtTail(LinkedList_t* handle);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if index is 0
 *  - Max = O(n) if index is lenght of the list
 */
int8_t LinkedList_DeleteAtIndex(LinkedList_t* handle, uint32_t index);

/**
 *  Time Complexity = O(n)
 */
LinkedList_t* LinkedList_Reverse(LinkedList_t* handle);

/**
 *  Time Complexity = O(n)
 */
void LinkedList_Reverse_SlidingPointers(LinkedList_t* handle);

/**
 *  Time Complexity = O(n)
 * 
 *  n = element count of first list
 *  m = element count of second list
 */
LinkedList_t* LinkedList_Concat(LinkedList_t* first, LinkedList_t* second);

/**
 *  Tortoise and Hare algorithm
 * 
 *  This algorithm starts with two pointers at the head
 *  Slow pointer will jump 1 element while fast pointer jumps 2 element
 *  If they ever meet at the same node this means there is a loop in Linked List.
 */
int8_t LinkedList_DetectLoop(LinkedList_t* handle);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if data is at the head
 *  - Max = O(n) if data is at the tail
 * 
 *  We cannot use Binary Search on linked list 
 *  because we cannot directly access the middle element 
 */
struct LL_Node* LinkedList_Search(LinkedList_t* handle, LL_DATA_TYPE data);

#endif /* LINKED_LIST_H */