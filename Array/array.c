#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "array.h"

Array_t* Array_Create(int size)
{
	Array_t* arrayPointer = (Array_t*)malloc(sizeof(Array_t));
	if (arrayPointer != NULL)
	{
		arrayPointer->ptr = (ARRAY_DATA_TYPE*)malloc(sizeof(ARRAY_DATA_TYPE) * size);
		if (arrayPointer->ptr != NULL)
		{
			arrayPointer->size = size;
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

void Array_Destroy(Array_t* handle)
{
	free(handle->ptr);
	free(handle);	
}

void Array_Display(Array_t* handle)
{
	printf("-----\n");
	for (int i = 0; i < handle->length; i++)
	{
		printf("%d\n", handle->ptr[i]);
	}
	printf("+++++\n");
}

int8_t Array_Add(Array_t* handle, ARRAY_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle->length < handle->size)
	{
		handle->ptr[handle->length] = data;
		handle->length++;
		success = 0;
	}
	return success;
}

int8_t Array_Insert(Array_t* handle, uint32_t index, ARRAY_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle->length < handle->size && index <= handle->length)
	{
		for (int i = handle->length; i > index; i--)
		{
			handle->ptr[i] = handle->ptr[i - 1];
		}
		handle->ptr[index] = data;
		handle->length++;
		success = 0;
	}
	return success;
}

int8_t Array_Delete(Array_t* handle, uint32_t index)
{
	int8_t success = -1;
	if (handle->length > 0 && index < handle->length)
	{
		for (int i = index; i < handle->length - 1; i++)
		{
			handle->ptr[i] = handle->ptr[i + 1];
		}
		handle->length--;
		success = 0;
	}
	return success;
}

int8_t Array_Get(Array_t* handle, uint32_t index, ARRAY_DATA_TYPE* data)
{
	int8_t success = -1;
	if (index >= 0 && index <= handle->length - 1)
	{
		*data = handle->ptr[index];
		success = 0;
	}
	return success;
}

void Array_Set(Array_t* handle, uint32_t index, ARRAY_DATA_TYPE data)
{
	if (index >= 0 && index <= handle->length - 1)
	{
		handle->ptr[index] = data;
	}
}

ARRAY_DATA_TYPE Array_Min(Array_t* handle)
{
	ARRAY_DATA_TYPE min = 0;
	if (handle->length > 0)
	{
		min = handle->ptr[0];
		for (uint32_t i = 1; i < handle->length; i++)
		{
			if (min > handle->ptr[i])
			{
				min = handle->ptr[i];
			}
		}
	}
	return min;
}

ARRAY_DATA_TYPE Array_Max(Array_t* handle)
{
	ARRAY_DATA_TYPE max = 0;
	if (handle->length > 0)
	{
		max = handle->ptr[0];
		for (uint32_t i = 1; i < handle->length; i++)
		{
			if (max < handle->ptr[i])
			{
				max = handle->ptr[i];
			}
		}
	}
	return max;
}

void Array_Reverse(Array_t* handle)
{
	Array_t* reverseArrayHandle = Array_Create(handle->length);
	for (uint32_t i = 0; i < handle->length; i++)
	{
		reverseArrayHandle->ptr[i] = handle->ptr[handle->length - 1 - i];
	}
	for (uint32_t i = 0; i < handle->length; i++)
	{
		handle->ptr[i] = reverseArrayHandle->ptr[i];
	}
	Array_Destroy(reverseArrayHandle);
}

void Array_Rotate(Array_t* handle, EnumDirection_t direction, uint32_t shiftCount)
{
	Array_t* rotatedArrayHandle = Array_Create(handle->length);
	if (direction == eDirection_RIGHT)
	{
		for (uint32_t i = 0; i < handle->length; i++)
		{
			uint32_t calculatedIndex = (i + shiftCount) % handle->length;
			rotatedArrayHandle->ptr[calculatedIndex] = handle->ptr[i];
		}
		for (uint32_t i = 0; i < handle->length; i++)
		{
			handle->ptr[i] = rotatedArrayHandle->ptr[i];
		}
	}
	else
	{
		for (int64_t i = handle->length - 1; i >= 0; i--)
		{
			uint32_t calculatedIndex = (i - (shiftCount % handle->length) + handle->length) % handle->length;
			rotatedArrayHandle->ptr[calculatedIndex] = handle->ptr[i];
		}
		for (uint32_t i = 0; i < handle->length; i++)
		{
			handle->ptr[i] = rotatedArrayHandle->ptr[i];
		}
	}
	Array_Destroy(rotatedArrayHandle);
}

Array_t* Array_Concat(Array_t* handle1, Array_t* handle2)
{
	uint32_t size = handle1->size + handle2->size;
	uint32_t length = handle1->length + handle2->length;
	Array_t* concatArrayHandle = Array_Create(size);
	concatArrayHandle->length = length;
	for (uint32_t i = 0; i < length; i++)
	{
		if (i < handle1->length)
		{
			concatArrayHandle->ptr[i] = handle1->ptr[i];
		}
		else
		{
			concatArrayHandle->ptr[i] = handle2->ptr[i - handle1->length];
		}
	}
	Array_Destroy(handle1);
	Array_Destroy(handle2);
	return concatArrayHandle;
}

void Array_Sort(Array_t* handle)
{
	/* TODO: Add an enum for sorting algorithms */
}

int64_t Array_LineerSearch(Array_t* handle, ARRAY_DATA_TYPE data)
{
	int64_t index = -1;
	for (uint32_t i = 0; i < handle->length; i++)
	{
		if (handle->ptr[i] == data)
		{
			index = i;
			break;
		}
	}
	return index;
}

void Transposition(Array_t* handle, uint32_t index)
{
	if (index > 0)
	{
		ARRAY_DATA_TYPE swapData = handle->ptr[index - 1];
		handle->ptr[index - 1] = handle->ptr[index];
		handle->ptr[index] = swapData;
	}
}

void MoveToFront(Array_t* handle, uint32_t index)
{
	if (index > 0)
	{
		ARRAY_DATA_TYPE swapData = handle->ptr[0];
		handle->ptr[0] = handle->ptr[index];
		handle->ptr[index] = swapData;
	}
}

int64_t Array_LineerSearch_Transposition(Array_t* handle, ARRAY_DATA_TYPE data)
{
	int64_t index = -1;
	for (uint32_t i = 0; i < handle->length; i++)
	{
		if (handle->ptr[i] == data)
		{
			index = i;
			Transposition(handle, i);
			break;
		}
	}
	return index;
}

int64_t Array_LineerSearch_MoveToFront(Array_t* handle, ARRAY_DATA_TYPE data)
{
	int64_t index = -1;
	for (uint32_t i = 0; i < handle->length; i++)
	{
		if (handle->ptr[i] == data)
		{
			index = i;
			MoveToFront(handle, i);
			break;
		}
	}
	return index;
}

int64_t Array_BinarySearch(Array_t* handle, ARRAY_DATA_TYPE data)
{
	uint32_t lowIndex = 0;
	uint32_t midIndex;
	uint32_t highIndex = handle->length - 1;
	while (lowIndex <= highIndex)
	{
		midIndex = (lowIndex + highIndex) / 2;
		if (data == handle->ptr[midIndex])
		{
			return midIndex;
		}
		else if (data < handle->ptr[midIndex])
		{
			highIndex = midIndex - 1;
		}
		else
		{
			lowIndex = midIndex + 1;
		}
	}
	return -1;
}
