#ifndef ARRAY_BASED_QUEUE_H
#define ARRAY_BASED_QUEUE_H

#include <stdint.h>

/* modify this for needed data type */
typedef int AB_QUEUE_DATA_TYPE;

typedef struct
{
    AB_QUEUE_DATA_TYPE* ptr;
    int64_t frontIndex;
    int64_t rearIndex;
    uint32_t length;
    uint32_t size; /* Capacity */
}AB_Queue_t;

/* Returns NULL if creation fails */
AB_Queue_t* AB_Queue_Create(int size);

/* Free array elements and it's handle pointer */
void AB_Queue_Destroy(AB_Queue_t* handle);

/* Prints decimal based arrays */
void AB_Queue_Display(AB_Queue_t* handle);

/**
 *  Time Complexity = O(1)
 */
int8_t AB_Queue_Enqueue(AB_Queue_t* handle, AB_QUEUE_DATA_TYPE data);

/**
 *  Time Complexity = O(1)
 */
int8_t AB_Queue_Dequeue(AB_Queue_t* handle);

/**
 *  Time Complexity = O(1)
 */
int8_t AB_Queue_Front(AB_Queue_t* handle, AB_QUEUE_DATA_TYPE* data);

/**
 *  Time Complexity = O(1)
 */
int8_t AB_Queue_Rear(AB_Queue_t* handle, AB_QUEUE_DATA_TYPE* data);

#endif /* ARRAY_BASED_QUEUE_H */