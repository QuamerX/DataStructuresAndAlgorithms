#include <stdio.h>
#include <stdlib.h>
#include "binary_heap.h"

void SwapValues(BH_Handle_t *handle, uint32_t swapIndex1, uint32_t swapIndex2);

BH_Handle_t* BH_Create(uint32_t size, EnumHeapType_t heapType)
{
    BH_Handle_t *handle = (BH_Handle_t *)malloc(sizeof(BH_Handle_t));
    if (handle != NULL)
    {
        handle->index = 1;
        handle->heap = (BH_DATA_TYPE *)calloc(sizeof(BH_DATA_TYPE), size);
        handle->size = size;
        handle->heapType = heapType;
        if (handle->heap == NULL)
        {
            free(handle);
            handle = NULL;
        }
    }
    return handle;
}

void BH_CompareAndSwap(BH_Handle_t *handle)
{
}

int8_t BH_Insert(BH_Handle_t *handle, BH_DATA_TYPE data)
{
    int8_t success = -1;
    if (handle != NULL)
    {
        uint32_t index = handle->index;
        handle->heap[index] = data;
        if (index < handle->size)
        {
            uint32_t parentIndex = index / 2;
            while (parentIndex > 0)
            {
                if (handle->heapType == MIN_HEAP)
                {
                    if (handle->heap[index] < handle->heap[parentIndex])
                    {
                        SwapValues(handle, index, parentIndex);
                        index = parentIndex;
                        parentIndex = index / 2;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (handle->heap[index] > handle->heap[parentIndex])
                    {
                        SwapValues(handle, index, parentIndex);
                        index = parentIndex;
                        parentIndex = index / 2;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            success = 0;
        }
        handle->index++;
    }
    return success;
}

int8_t BH_Search(BH_Handle_t *handle, BH_DATA_TYPE data)
{
    int8_t success = -1;
    for (uint32_t i = 1; i < handle->index; i++)
    {
        if (handle->heap[i] == data)
        {
            success = 0;
        }
    }
    return success;
}

int8_t BH_Delete(BH_Handle_t *handle)
{
    if (handle != NULL)
    {
        SwapValues(handle, 1, handle->index - 1);
        handle->index--;
        uint32_t rootIndex = 1;
        while (1)
        {
            uint32_t leftChildIndex = rootIndex * 2;
            uint32_t rightChildIndex = (rootIndex * 2) + 1;
            if (leftChildIndex >= handle->index && rightChildIndex >= handle->index)
            {
                break;
            }
            else if (leftChildIndex < handle->index && rightChildIndex >= handle->index)
            {
                if (handle->heapType == MIN_HEAP)
                {
                    if (handle->heap[rootIndex] > handle->heap[leftChildIndex])
                    {
                        SwapValues(handle, rootIndex, leftChildIndex);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (handle->heap[rootIndex] < handle->heap[leftChildIndex])
                    {
                        SwapValues(handle, rootIndex, leftChildIndex);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if (handle->heapType == MIN_HEAP)
                {
                    if (handle->heap[leftChildIndex] <= handle->heap[rightChildIndex])
                    {
                        if (handle->heap[rootIndex] > handle->heap[leftChildIndex])
                        {
                            SwapValues(handle, rootIndex, leftChildIndex);
                            rootIndex = leftChildIndex;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        if (handle->heap[rootIndex] > handle->heap[rightChildIndex])
                        {
                            SwapValues(handle, rootIndex, rightChildIndex);
                            rootIndex = rightChildIndex;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    if (handle->heap[leftChildIndex] >= handle->heap[rightChildIndex])
                    {
                        if (handle->heap[rootIndex] < handle->heap[leftChildIndex])
                        {
                            SwapValues(handle, rootIndex, leftChildIndex);
                            rootIndex = leftChildIndex;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        if (handle->heap[rootIndex] < handle->heap[rightChildIndex])
                        {
                            SwapValues(handle, rootIndex, rightChildIndex);
                            rootIndex = rightChildIndex;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        return 0;
    }
    return -1;
}

void BH_HeapSort(BH_Handle_t* handle)
{
    uint32_t elementCount = handle->index - 1;
    for (size_t i = 0; i < elementCount; i++)
	{
		BH_Delete(handle);
	}
    handle->index = elementCount + 1;
    BH_Print(handle);
}

void BH_Print(BH_Handle_t *handle)
{
    if (handle != NULL)
    {
        for (uint32_t i = 1; i < handle->index; i++)
        {
            printf("%d ", handle->heap[i]);
        }
        printf("\n");
    }
}

void BH_Destroy(BH_Handle_t *handle)
{
    free(handle->heap);
    free(handle);
}

void SwapValues(BH_Handle_t *handle, uint32_t swapIndex1, uint32_t swapIndex2)
{
    if (handle != NULL)
    {
        uint32_t temp = handle->heap[swapIndex1];
        handle->heap[swapIndex1] = handle->heap[swapIndex2];
        handle->heap[swapIndex2] = temp;
    }
}
