#ifndef DEQUE_H
#define DEQUE_H

#include <stdint.h>

typedef int DEQUE_DATA_TYPE;

struct DEQueue_Node 
{
    DEQUE_DATA_TYPE data;
    struct DEQueue_Node* next;
    struct DEQueue_Node* prev;
};

typedef struct 
{
    struct DEQueue_Node* front;
    struct DEQueue_Node* rear;
    uint32_t length;
}DEQueue_t;

DEQueue_t* DEQueue_Create(void);

void DEQueue_Destroy(DEQueue_t* deque);

struct DEQueue_Node* DEQueue_CreateNode(DEQUE_DATA_TYPE data);

int8_t DEQueue_InsertFirstNode(DEQueue_t* handle, DEQUE_DATA_TYPE data);

int8_t DEQueue_DeleteLastNode(DEQueue_t* handle);

/**
 *  Time Complexity = O(1)
 */
int8_t DEQueue_InsertFront(DEQueue_t* deque, DEQUE_DATA_TYPE data);

/**
 *  Time Complexity = O(1)
 */
int8_t DEQueue_InsertRear(DEQueue_t* deque, DEQUE_DATA_TYPE data);

/**
 *  Time Complexity = O(1)
 */
int8_t DEQueue_DeleteFront(DEQueue_t* deque);

/**
 *  Time Complexity = O(1)
 */
int8_t DEQueue_DeleteRear(DEQueue_t* deque);


#endif /* DEQUE_H */
