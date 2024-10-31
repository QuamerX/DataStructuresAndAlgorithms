#ifndef LINKED_LIST_BASED_QUEUE_H
#define LINKED_LIST_BASED_QUEUE_H

#include <stdint.h>

typedef int LLB_QUEUE_DATA_TYPE;

struct LLB_Queue_Node
{
	LLB_QUEUE_DATA_TYPE data;
	struct LLB_Queue_Node* next;
};

typedef struct
{
	struct LLB_Queue_Node* front;
	struct LLB_Queue_Node* rear;
	uint32_t length;
}LLB_Queue_t;

LLB_Queue_t* LLB_Queue_Create(void);

void LLB_Queue_Destroy(LLB_Queue_t* handle);

void LLB_Queue_Display(LLB_Queue_t* handle);

struct LLB_Queue_Node* LLB_Queue_CreateNode(LLB_QUEUE_DATA_TYPE data);

int8_t LLB_Queue_InsertFirstNode(LLB_Queue_t* handle, LLB_QUEUE_DATA_TYPE data);

int8_t LLB_Queue_DeleteLastNode(LLB_Queue_t* handle);

/**
 *  Time Complexity = O(1)
 */
int8_t LLB_Queue_Enqueue(LLB_Queue_t* handle, LLB_QUEUE_DATA_TYPE data);

/**
 *  Time Complexity = O(1)
 */
int8_t LLB_Queue_Dequeue(LLB_Queue_t* handle);

/**
 *  Time Complexity = O(1)
 */
int8_t LLB_Queue_Front(LLB_Queue_t* handle, LLB_QUEUE_DATA_TYPE* data);

/**
 *  Time Complexity = O(1)
 */
int8_t LLB_Queue_Rear(LLB_Queue_t* handle, LLB_QUEUE_DATA_TYPE* data);

#endif /* LINKED_LIST_BASED_QUEUE_H */