#include <stdint.h>
#include "search.h"

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