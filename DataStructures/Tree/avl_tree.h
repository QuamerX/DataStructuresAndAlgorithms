#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdint.h>

/* modify this for needed data type */
typedef int AVL_DATA_TYPE;

typedef enum
{
    eTraverse_PRE_ORDER,
    eTraverse_IN_ORDER,
    eTraverse_POST_ORDER
}EnumTraverse_t;

typedef struct AVL_Node_t
{
    AVL_DATA_TYPE data;
    struct AVL_Node_t* left;
    struct AVL_Node_t* right;
}AVL_Node_t;

AVL_Node_t* AVL_CreateNode(AVL_DATA_TYPE data);

int AVL_Height(AVL_Node_t* node);

AVL_Node_t* AVL_Insert(AVL_Node_t* root, AVL_DATA_TYPE data);

int8_t AVL_Search(AVL_Node_t* root, AVL_DATA_TYPE data);

AVL_Node_t* AVL_Access(AVL_Node_t* root, AVL_DATA_TYPE data);

AVL_Node_t* AVL_Delete(AVL_Node_t* root, AVL_DATA_TYPE data);

void AVL_Print(AVL_Node_t* root);

void AVL_Traverse(AVL_Node_t* root, EnumTraverse_t traverseType);

void AVL_Destroy(AVL_Node_t* root);

#endif // AVL_TREE_H

