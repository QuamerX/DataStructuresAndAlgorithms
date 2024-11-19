#include <stdio.h>
#include <stdlib.h>
#include "binary_heap.h"

BH_Handle_t* BH_Create(uint32_t size)
{
    BH_Handle_t* handle = (BH_Handle_t*)malloc(sizeof(BH_Handle_t));
    if (handle != NULL)
    {
        handle->index = 1;
        handle->heap = (BH_DATA_TYPE*)malloc(sizeof(BH_DATA_TYPE) * size);
        if (handle->heap == NULL)
        {
            free(handle);
            handle = NULL;
        }
    }
    return handle;
}

int8_t BH_Insert(BH_Handle_t* handle, BH_DATA_TYPE data)
{
    int8_t success = -1;
    if (handle == NULL)
    {
        handle->heap[handle->index] = data;
        handle->index++;
        success = 0;
    }
    return success;
}

int8_t BH_Search(BH_Handle_t* handle, BH_DATA_TYPE data)
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

int8_t BH_Delete(BH_Handle_t* handle, BH_DATA_TYPE data)
{
    return 1;
}

void BH_Print(BH_Handle_t* handle)
{
    for (uint32_t i = 1; i < handle->index; i++)
    {
        printf("%d ", handle->heap[i]);
    }
    printf("\n");
}

void BH_Destroy(BH_Handle_t* handle)
{
    free(handle->heap);
    free(handle);
}

