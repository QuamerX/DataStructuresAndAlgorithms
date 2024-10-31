#include <stdlib.h>
#include "linked_list_based_stack.h"

LLB_Stack_t* LLB_Stack_Create()
{
	LLB_Stack_t* handle = (LLB_Stack_t*)malloc(sizeof(LLB_Stack_t));
	if (handle != NULL)
	{
		handle->top = NULL;
		handle->length = 0;
	}
	return handle;
}

void LLB_Stack_Destroy(LLB_Stack_t* handle)
{
	if (handle != NULL)
	{
		for (uint32_t i = 0; i < handle->length; i++)
		{
			struct LLB_Node* node = handle->top->next;
			free(handle->top);
			handle->top = node;
		}
		free(handle);
	}
}

void LLB_Stack_Display(LLB_Stack_t* handle)
{
	printf("-----\n");
	struct LLB_Stack_Node* node = handle->top;
	for (uint32_t i = 0; i < handle->length; i++)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("+++++\n");
}

struct LLB_Stack_Node* LLB_Stack_CreateNode(LLB_STACK_DATA_TYPE data)
{
	struct LLB_Stack_Node* newNode = (struct LLB_Node*)malloc(sizeof(struct LLB_Stack_Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}

void LLB_Stack_InsertFirstNode(LLB_Stack_t* handle, LLB_STACK_DATA_TYPE data)
{
	struct LLB_Stack_Node* newNode = LLB_Stack_CreateNode(data);
	if (newNode != NULL)
	{
		handle->top = newNode;
		handle->length = 1;
	}
}

void LLB_Stack_DeleteLastNode(LLB_Stack_t* handle)
{
	free(handle->top);
	handle->top = NULL;
	handle->length = 0;
}

int8_t LLB_Stack_Push(LLB_Stack_t* handle, LLB_STACK_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle->length == 0)
	{
		LLB_Stack_InsertFirstNode(handle, data);
	}
	else
	{
		struct LLB_Stack_Node* newHead = LLB_Stack_CreateNode(data);
		if (newHead != NULL)
		{
			newHead->next = handle->top;
			handle->top = newHead;
			handle->length++;
			success = 0;
		}
	}
	return success;
}

int8_t LLB_Stack_Pop(LLB_Stack_t* handle)
{
	int8_t success = -1;
	if (handle->length > 0)
	{
		if (handle->length == 1)
		{
			LLB_Stack_DeleteLastNode(handle);
		}
		else
		{
			struct LLB_Node* newHead = handle->top->next;
			free(handle->top);
			handle->top = newHead;
			handle->length--;
			success = 0;
		}
	}

	return success;
}

int8_t LLB_Stack_Peek(LLB_Stack_t* handle, LLB_STACK_DATA_TYPE* peekedData)
{
	int8_t success = -1;
	if (handle->length > -1)
	{
		*peekedData = handle->top->data;
		success = 0;
	}
	return success;
}
