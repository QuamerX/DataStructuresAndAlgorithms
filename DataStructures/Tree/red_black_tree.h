#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdint.h>

/* modify this for needed data type */
typedef int RB_DATA_TYPE;

typedef enum
{
	eColor_RED,
	eColor_BLACK
}EnumColor_t;

typedef enum
{
    eTraverse_PRE_ORDER,
    eTraverse_IN_ORDER,
    eTraverse_POST_ORDER
}EnumTraverse_t;

typedef struct RB_Node_t
{
    RB_DATA_TYPE data;
    EnumColor_t color;
    struct RB_Node_t* left;
    struct RB_Node_t* right;
}RB_Node_t;

RB_Node_t* RB_CreateNode(RB_DATA_TYPE data);

RB_Node_t* RB_CreateRoot(RB_DATA_TYPE data);

RB_Node_t* RB_Insert(RB_Node_t* root, RB_DATA_TYPE data);

int8_t RB_Search(RB_Node_t* root, RB_DATA_TYPE data);

RB_Node_t* RB_Access(RB_Node_t* root, RB_DATA_TYPE data);

RB_Node_t* RB_Delete(RB_Node_t* root, RB_DATA_TYPE data);

void RB_Print(RB_Node_t* root);

void RB_Traverse(RB_Node_t* root, EnumTraverse_t traverseType);

void RB_Destroy(RB_Node_t* root);

#endif // RED_BLACK_TREE_H

