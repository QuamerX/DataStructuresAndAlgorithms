#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdint.h>

/* modify this for needed data type */
typedef int BST_DATA_TYPE;

typedef enum
{
    eTraverse_PRE_ORDER,
    eTraverse_IN_ORDER,
    eTraverse_POST_ORDER
}EnumTraverse_t;

typedef struct BST_Node_t
{
    BST_DATA_TYPE data;
    struct BST_Node_t* left;
    struct BST_Node_t* right;
}BST_Node_t;

BST_Node_t* BST_CreateNode(BST_DATA_TYPE data);

BST_Node_t* BST_Insert(BST_Node_t* root, BST_DATA_TYPE data);

int8_t BST_Search(BST_Node_t* root, BST_DATA_TYPE data);

BST_Node_t* BST_Access(BST_Node_t* root, BST_DATA_TYPE data);

BST_Node_t* BST_Delete(BST_Node_t* root, BST_DATA_TYPE data);

void BST_Print(BST_Node_t* root);

void BST_Traverse(BST_Node_t* root, EnumTraverse_t traverseType);

void BST_Destroy(BST_Node_t* root);

#endif /* BINARY_SEARCH_TREE_H */

