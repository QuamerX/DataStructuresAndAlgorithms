#ifndef ARRAY_H
#define ARRAY_H

/* modify this for needed data type */
typedef int DATA_TYPE;

typedef struct
{
    DATA_TYPE* ptr;
    int size; /* Capacity */
    int length; /* Current element count */
}Array_t;

/* Returns NULL if creation fails */
Array_t* Array_Create(int size);

/* Free array elements and it's handle pointer */
void Array_Destroy(Array_t* handle);

/* Prints decimal based arrays */
void Array_Display(Array_t* handle);

/**
 *  Time Complexity = O(1)
 *
 *  Processing only two statements
 *  and they don't depend on array's element count
 */
int8_t Array_Add(Array_t* handle, DATA_TYPE data);

/**
 *  Time Complexity:
 * 
 *  - Min = O(1) if you insert at the end of array
 *  - Max = O(n) if you insert at the beginning of array
 */
int8_t Array_Insert(Array_t* handle, uint32_t index, DATA_TYPE data);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if you delete at the end of array
 *  - Max = O(n) if you delete at the beginning of array
 */
void Array_Delete(Array_t* handle, uint32_t index);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if the element is at the beginning of array
 *  - Max = O(n) if the element is at the end of array
 */
int64_t Array_LineerSearch(Array_t* handle, DATA_TYPE data);

/**
 *  This technique helps to reduce search time
 *  by moving more seached elements one step closer to the first index
 *  
 *  + Helps reduce search time for most searched elements over time
 *  
 *  - Only useful if certain items are searched frequently
 */
void Transposition(Array_t* handle, uint32_t index);
int64_t Array_LineerSearch_Transposition(Array_t* handle, DATA_TYPE data);

/**
 *  This technique helps to reduce search time
 *  by moving more seached elements directly to the first index
 * 
 *  + Helps reduce search time for most searched elements over time
 * 
 *  - Doesn't maintain any order and 
 *    random searches could increase search time for later
 */
void MoveToFront(Array_t* handle, uint32_t index);
int64_t Array_LineerSearch_MoveToFront(Array_t* handle, DATA_TYPE data);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if the element is at the beginning of array
 *  - Max = O(log(2)n) if the element is at the end of array
 * 
 *  @note: Only used on sorted arrays
 */
int64_t Array_BinarySearch(Array_t* handle, DATA_TYPE data);

void Array_Sort(Array_t* handle);

/**
 *  Time Complexity = O(1)
 */
int8_t Array_Get(Array_t* handle, uint32_t index, DATA_TYPE* data);

/**
 *  Time Complexity = O(1)
 */
void Array_Set(Array_t* handle, uint32_t index, DATA_TYPE data);

/**
 *  Time Complexity = O(n)
 */
DATA_TYPE Array_Min(Array_t* handle);

/**
 *  Time Complexity = O(n)
 */
DATA_TYPE Array_Max(Array_t* handle);

void Array_Reverse(Array_t* handle);
void Array_Rotate(Array_t* handle);

#endif