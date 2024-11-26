#ifndef SEARCH_H
#define SEARCH_H

#include "../../DataStructures/Array/array.h"

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if the element is at the beginning of array
 *  - Max = O(n) if the element is at the end of array
 */
int64_t Array_LineerSearch(Array_t* handle, ARRAY_DATA_TYPE data);

/**
 *  This technique helps to reduce search time
 *  by moving more seached elements one step closer to the first index
 *
 *  + Helps reduce search time for most searched elements over time
 *
 *  - Only useful if certain items are searched frequently
 */
int64_t Array_LineerSearch_Transposition(Array_t* handle, ARRAY_DATA_TYPE data);

/**
 *  This technique helps to reduce search time
 *  by moving more seached elements directly to the first index
 *
 *  + Helps reduce search time for most searched elements over time
 *
 *  - Doesn't maintain any order and
 *    random searches could increase search time for later
 */
int64_t Array_LineerSearch_MoveToFront(Array_t* handle, ARRAY_DATA_TYPE data);

/**
 *  Time Complexity:
 *
 *  - Min = O(1) if the element is at the beginning of array
 *  - Max = O(log(2)n) if the element is at the end of array
 *
 *  @note: Only used on sorted arrays
 */
int64_t Array_BinarySearch(Array_t* handle, ARRAY_DATA_TYPE data);

#endif /* SEARCH_H */