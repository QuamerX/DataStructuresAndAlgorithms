#ifndef TWO_THREE_TREE_H
#define TWO_THREE_TREE_H

#include <stdint.h>

/* modify this for needed data type */
typedef int TTT_DATA_TYPE;

typedef enum
{
    eTraverse_PRE_ORDER,
    eTraverse_IN_ORDER,
    eTraverse_POST_ORDER
}EnumTraverse_t;

typedef struct TTT_Node_t
{
    TTT_DATA_TYPE leftKey;
    TTT_DATA_TYPE rightKey;
    struct TTT_Node_t* left;
    struct TTT_Node_t* middle;
    struct TTT_Node_t* right;
    uint8_t keyCount;
}TTT_Node_t;

TTT_Node_t* TTT_CreateNode(TTT_DATA_TYPE key);

TTT_Node_t* TTT_Insert(TTT_Node_t* root, TTT_DATA_TYPE key);

int8_t TTT_Search(TTT_Node_t* root, TTT_DATA_TYPE key);

TTT_Node_t* TTT_Access(TTT_Node_t* root, TTT_DATA_TYPE key);

TTT_Node_t* TTT_Delete(TTT_Node_t* root, TTT_DATA_TYPE key);

void TTT_Print(TTT_Node_t* root);

void TTT_Traverse(TTT_Node_t* root, EnumTraverse_t traverseType);

void TTT_Destroy(TTT_Node_t* root);

#endif /* TWO_THREE_TREE_H */
