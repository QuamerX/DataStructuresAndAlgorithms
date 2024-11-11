#include <stdlib.h>
#include <stdio.h>
#include "linked_list_based_queue.h"

LLB_Queue_t* LLB_Queue_Create()
{
	LLB_Queue_t* handle = (LLB_Queue_t*)malloc(sizeof(LLB_Queue_t));
	if (handle != NULL)
	{
		handle->front = NULL;
		handle->rear = NULL;
		handle->length = 0;
	}
	return handle;
}

void LLB_Queue_Destroy(LLB_Queue_t* handle)
{
	if (handle != NULL)
	{
		while (LLB_Queue_Dequeue(handle) == 0);
		free(handle);
	}
}

void LLB_Queue_Display(LLB_Queue_t* handle)
{
	if (handle != NULL) 
	{
		printf("-----\n");
		struct LLB_Queue_Node* node = handle->front;
		for (int i = 0; i < handle->length; i++)
		{
			printf("%d\n", node->data);
			node = node->next;
		}
		printf("+++++\n");
	}
	else
	{
		printf("Queue Handle Is NULL\n");
	}
}

struct LLB_Queue_Node* LLB_Queue_CreateNode(LLB_QUEUE_DATA_TYPE data)
{
	struct LLB_Queue_Node* newNode = (struct LLB_Queue_Node*)malloc(sizeof(struct LLB_Queue_Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}

int8_t LLB_Queue_InsertFirstNode(LLB_Queue_t* handle, LLB_QUEUE_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle != NULL)
	{
		struct LLB_Queue_Node* newNode = LLB_Queue_CreateNode(data);
		if (newNode != NULL)
		{
			handle->front = newNode;
			handle->rear = newNode;
			handle->length = 1;
			success = 0;
		}
	}
	return success;
}

int8_t LLB_Queue_DeleteLastNode(LLB_Queue_t* handle)
{
	int8_t success = -1;
	if (handle != NULL)
	{
		free(handle->front);
		handle->front = NULL;
		handle->rear = NULL;
		handle->length = 0;
		success = 0;
	}
	return success;
}

int8_t LLB_Queue_Enqueue(LLB_Queue_t* handle, LLB_QUEUE_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle != NULL)
	{
		if (handle->length == 0)
		{
			success = LLB_Queue_InsertFirstNode(handle, data);
		}
		else
		{
			struct LLB_Queue_Node* newNode = LLB_Queue_CreateNode(data);
			if (newNode != NULL)
			{
				handle->rear->next = newNode;
				handle->rear = newNode;
				handle->length++;
				success = 0;
			}
		}
	}
	return success;
}

int8_t LLB_Queue_Dequeue(LLB_Queue_t* handle)
{
	int8_t success = -1;
	if (handle != NULL && handle->length > 0)
	{
		if (handle->length == 1)
		{
			success = LLB_Queue_DeleteLastNode(handle);
		}
		else
		{
			struct LLB_Queue_Node* newHead = handle->front->next;
			free(handle->front);
			handle->front = newHead;
			handle->length--;
			success = 0;
		}
	}
	return success;
}

int8_t LLB_Queue_Front(LLB_Queue_t* handle, LLB_QUEUE_DATA_TYPE* data)
{
	int8_t success = -1;
	if (handle != NULL && handle->length > 0)
	{
		*data = handle->front->data;
		success = 0;
	}
	return success;
}

int8_t LLB_Queue_Rear(LLB_Queue_t* handle, LLB_QUEUE_DATA_TYPE* data)
{
	int8_t success = -1;
	if (handle != NULL && handle->length > 0)
	{
		*data = handle->rear->data;
		success = 0;
	}
	return success;
}
