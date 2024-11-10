#ifndef ARRAY_BASED_STACK_H
#define ARRAY_BASED_STACK_H

#include <stdint.h>

/* modify this for needed data type */
typedef int AB_STACK_DATA_TYPE;

typedef struct
{
    AB_STACK_DATA_TYPE* ptr;
    uint32_t size; /* Capacity */
    int64_t topIndex;
}AB_Stack_t;

/* Returns NULL if creation fails */
AB_Stack_t* AB_Stack_Create(int size);

/* Free stack elements and it's handle pointer */
void AB_Stack_Destroy(AB_Stack_t* handle);

/* Prints decimal based stacks */
void AB_Stack_Display(AB_Stack_t* handle);

/**
 *  Time Complexity = O(1)
 */
int8_t AB_Stack_Push(AB_Stack_t* handle, AB_STACK_DATA_TYPE data);

/**
 *  Time Complexity = O(1)
 */
int8_t AB_Stack_Pop(AB_Stack_t* handle);

/**
 *  Time Complexity = O(1)
 */
int8_t AB_Stack_Peek(AB_Stack_t* handle, AB_STACK_DATA_TYPE* peekedData);

#endif /* ARRAY_BASED_STACK_H */