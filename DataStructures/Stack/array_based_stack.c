#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "array_based_stack.h"

AB_Stack_t* AB_Stack_Create(int size)
{
	AB_Stack_t* stackPointer = (AB_Stack_t*)malloc(sizeof(AB_Stack_t));
	if (stackPointer != NULL)
	{
		stackPointer->ptr = (AB_STACK_DATA_TYPE*)malloc(sizeof(AB_STACK_DATA_TYPE) * size);
		if (stackPointer->ptr != NULL)
		{
			stackPointer->size = size;
			stackPointer->topIndex = -1;
		}
		else
		{
			/* Eventhough handle created, elements didn't so free the handle */
			free(stackPointer);
			stackPointer = NULL;
		}
	}
	return stackPointer;
}

void AB_Stack_Destroy(AB_Stack_t* handle)
{
	if (handle != NULL)
	{
		free(handle->ptr);
		free(handle);
	}
}

void AB_Stack_Display(AB_Stack_t* handle)
{
	printf("-----\n");
	for (int i = 0; i < handle->topIndex + 1; i++)
	{
		printf("%d\n", handle->ptr[i]);
	}
	printf("+++++\n");
}

int8_t AB_Stack_Push(AB_Stack_t* handle, AB_STACK_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle->topIndex < handle->size - 1)
	{
		handle->topIndex++;
		handle->ptr[handle->topIndex] = data;
		success = 0;
	}
	return success;
}

int8_t AB_Stack_Pop(AB_Stack_t* handle)
{
	int8_t success = -1;
	if (handle->topIndex > -1)
	{
		handle->topIndex--;
		success = 0;
	}
	return success;
}

int8_t AB_Stack_Peek(AB_Stack_t* handle, AB_STACK_DATA_TYPE* peekedData)
{
	int8_t success = -1;
	if (handle->topIndex > -1)
	{
		*peekedData = handle->ptr[handle->topIndex];
		success = 0;
	}
	return success;
}
