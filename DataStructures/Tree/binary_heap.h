#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stdint.h>

/* modify this for needed data type */
typedef int BH_DATA_TYPE;

typedef struct
{
    BH_DATA_TYPE* heap;
    uint32_t index;
}BH_Handle_t;

BH_Handle_t* BH_Create(uint32_t size);

int8_t BH_Insert(BH_Handle_t* handle, BH_DATA_TYPE data);

int8_t BH_Search(BH_Handle_t* handle, BH_DATA_TYPE data);

int8_t BH_Delete(BH_Handle_t* handle, BH_DATA_TYPE data);

void BH_Print(BH_Handle_t* handle);

void BH_Destroy(BH_Handle_t* handle);

#endif // BINARY_HEAP_H

