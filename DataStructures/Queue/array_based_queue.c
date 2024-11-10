#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "array_based_queue.h"

AB_Queue_t* AB_Queue_Create(int size)
{
	AB_Queue_t* arrayPointer = (AB_Queue_t*)malloc(sizeof(AB_Queue_t));
	if (arrayPointer != NULL)
	{
		arrayPointer->ptr = (AB_QUEUE_DATA_TYPE*)malloc(sizeof(AB_QUEUE_DATA_TYPE) * size);
		if (arrayPointer->ptr != NULL)
		{
			arrayPointer->size = size;
			arrayPointer->frontIndex = 0;
			arrayPointer->rearIndex = -1;
			arrayPointer->length = 0;
		}
		else
		{
			/* Eventhough handle created, array didn't so free the handle */
			free(arrayPointer);
			arrayPointer = NULL;
		}
	}
	return arrayPointer;
}

void AB_Queue_Destroy(AB_Queue_t* handle)
{
	if (handle != NULL)
	{
		free(handle->ptr);
		free(handle);
	}
}

void AB_Queue_Display(AB_Queue_t* handle)
{
	printf("-----\n");
	for (int i = 0; i < handle->length; i++)
	{
		printf("%d\n", handle->ptr[(handle->frontIndex + i) % handle->size]);
	}
	printf("+++++\n");
}

int8_t AB_Queue_Enqueue(AB_Queue_t* handle, AB_QUEUE_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle != NULL && handle->length < handle->size)
	{
		handle->rearIndex = (handle->rearIndex + 1) % handle->size;
		handle->ptr[handle->rearIndex] = data;
		handle->length++;
		success = 0;
	}
	return success;
}

int8_t AB_Queue_Dequeue(AB_Queue_t* handle)
{
	int8_t success = -1;
	if (handle != NULL && handle->length > 0)
	{
		handle->frontIndex = (handle->frontIndex + 1) % handle->size;
		handle->length--;
		success = 0;
	}
	return success;
}

int8_t AB_Queue_Front(AB_Queue_t* handle, AB_QUEUE_DATA_TYPE* data)
{
	int8_t success = -1;
	if (handle != NULL && handle->frontIndex > -1)
	{
		*data = handle->ptr[handle->frontIndex];
		success = 0;
	}
	return success;
}

int8_t AB_Queue_Rear(AB_Queue_t* handle, AB_QUEUE_DATA_TYPE* data)
{
	int8_t success = -1;
	if (handle != NULL && handle->rearIndex > -1)
	{
		*data = handle->ptr[handle->rearIndex];
		success = 0;
	}
	return success;
}