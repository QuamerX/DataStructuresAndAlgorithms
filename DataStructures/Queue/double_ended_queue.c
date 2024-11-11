#include <stdlib.h>
#include <stdio.h>
#include "double_ended_queue.h"

DEQueue_t* DEQueue_Create()
{
	DEQueue_t* handle = (DEQueue_t*)malloc(sizeof(DEQueue_t));
	if (handle != NULL)
	{
		handle->front = NULL;
		handle->rear = NULL;
		handle->length = 0;
	}
	return handle;
}

void DEQueue_Destroy(DEQueue_t* handle)
{
	if (handle != NULL)
	{
		for (uint32_t i = 0; i < handle->length; i++)
		{
			DEQueue_DeleteFront(handle);
		}
		free(handle);
	}
}

void DEQueue_Display(DEQueue_t* handle)
{
	printf("-----\n");
	struct DEQueue_Node* node = handle->front;
	for (int i = 0; i < handle->length; i++)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("+++++\n");
}

struct DEQueue_Node* DEQueue_CreateNode(DEQUE_DATA_TYPE data)
{
	struct DEQueue_Node* newNode = (struct DEQueue_Node*)malloc(sizeof(struct DEQueue_Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	return newNode;
}

int8_t DEQueue_InsertFirstNode(DEQueue_t* handle, DEQUE_DATA_TYPE data)
{
	int8_t success = -1;
	struct DEQueue_Node* newNode = DEQueue_CreateNode(data);
	if (handle != NULL && handle->length == 0 && newNode != NULL)
	{
		handle->front = newNode;
		handle->rear = handle->front;
		handle->length = 1;
		success = 0;
	}
	return success;
}

int8_t DEQueue_DeleteLastNode(DEQueue_t* handle)
{
	int8_t success = -1;
	if (handle != NULL && handle->length == 1)
	{
		free(handle->front);
		handle->front = NULL;
		handle->rear = NULL;
		handle->length = 0;
		success = 0;
	}
	return success;
}

int8_t DEQueue_InsertFront(DEQueue_t* handle, DEQUE_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle != NULL)
	{
		if (handle->length == 0)
		{
			success = DEQueue_InsertFirstNode(handle, data);
		}
		else
		{
			struct DEQueue_Node* newHead = DEQueue_CreateNode(data);
			if (newHead != NULL)
			{
				newHead->next = handle->front;
				handle->front->prev = newHead;
				handle->front = newHead;
				handle->length++;
				success = 0;
			}
		}
	}
	return success;
}

int8_t DEQueue_InsertRear(DEQueue_t* handle, DEQUE_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle != NULL)
	{
		if (handle->length == 0)
		{
			success = DEQueue_InsertFirstNode(handle, data);
		}
		else
		{
			struct DEQueue_Node* newTail = DEQueue_CreateNode(data);
			if (newTail != NULL)
			{
				handle->rear->next = newTail;
				newTail->prev = handle->rear;
				handle->rear = newTail;
				handle->length++;
				success = 0;
			}
		}
	}
	return success;
}

int8_t DEQueue_DeleteFront(DEQueue_t* handle)
{
	int8_t success = -1;
	if (handle != NULL)
	{
		if (handle->length > 0)
		{
			if (handle->length == 1)
			{
				success = DEQueue_DeleteLastNode(handle);
			}
			else
			{
				struct DEQueue_Node* newHead = handle->front->next;
				free(handle->front);
				handle->front = newHead;
				handle->length--;
				success = 0;
			}
		}
	}
	return success;
}

int8_t DEQueue_DeleteRear(DEQueue_t* handle)
{
	int8_t success = -1;
	if (handle != NULL)
	{
		if (handle->length > 0)
		{
			if (handle->length == 1)
			{
				success = DEQueue_DeleteLastNode(handle);
			}
			else
			{
				struct DEQueue_Node* newTail = handle->rear->prev;
				free(handle->rear);
				newTail->next = NULL;
				handle->rear = newTail;
				handle->length--;
				success = 0;
			}
		}
	}
	return success;
}
