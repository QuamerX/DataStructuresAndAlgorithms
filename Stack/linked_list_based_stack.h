#ifndef LINKED_LIST_BASED_STACK_H
#define LINKED_LIST_BASED_STACK_H

#include <stdint.h>

typedef int LLB_STACK_DATA_TYPE;

struct LLB_Stack_Node
{
	LLB_STACK_DATA_TYPE data;
	struct LLB_Stack_Node* next;
};

typedef struct
{
	struct LLB_Stack_Node* top;
	uint32_t length;
}LLB_Stack_t;

LLB_Stack_t* LLB_Stack_Create(void);

void LLB_Stack_Destroy(LLB_Stack_t* handle);

void LLB_Stack_Display(LLB_Stack_t* handle);

struct LLB_Stack_Node* LLB_Stack_CreateNode(LLB_STACK_DATA_TYPE data);

int8_t LLB_Stack_InsertFirstNode(LLB_Stack_t* handle, LLB_STACK_DATA_TYPE data);

int8_t LLB_Stack_DeleteLastNode(LLB_Stack_t* handle);

/**
 *  Time Complexity = O(1)
 *
 */
int8_t LLB_Stack_Push(LLB_Stack_t* handle, LLB_STACK_DATA_TYPE data);

/**
 *  Time Complexity = O(1)
 *
 *  We hold the head node so its simple to delete head
 */
int8_t LLB_Stack_Pop(LLB_Stack_t* handle);

/**
 *  Time Complexity = O(1)
 *
 *  We hold the head node so its simple to delete head
 */
int8_t LLB_Stack_Peek(LLB_Stack_t* handle, LLB_STACK_DATA_TYPE* peekedData);

#endif /* LINKED_LIST_BASED_STACK_H */