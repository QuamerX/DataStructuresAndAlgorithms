#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

BST_Node_t* BST_CreateNode(BST_DATA_TYPE data)
{
    BST_Node_t* new_node = (BST_Node_t*)malloc(sizeof(BST_Node_t));
    if (new_node != NULL) 
    {
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

BST_Node_t* BST_InsertRecursive(BST_Node_t* root, BST_DATA_TYPE data)
{
    if (root == NULL)
    {
        return BST_CreateNode(data);
    }
    else
    {
        if (data < root->data) 
        {
            root->left = BST_InsertRecursive(root->left, data);
        }
        else if (data > root->data) 
        {
            root->right = BST_InsertRecursive(root->right, data);
        }
        else 
        {
            return root;
        }
    }
    return root;
}

int8_t BST_Insert(BST_Node_t* root, BST_DATA_TYPE data) 
{
    int8_t success = 0;
    if (BST_InsertRecursive(root, data) == NULL)
    {
        success = -1;
    }
    return success;
}

int8_t BST_Search(BST_Node_t* root, BST_DATA_TYPE data)
{
    int8_t success = 0;
    if (root == NULL) 
    {
        success = -1;
    }
    else
    {
        if (data < root->data)
        {
            return BST_Search(root->left, data);
        }
        else if (data > root->data)
        {
            return BST_Search(root->right, data);
        }
        else
        {
            success = 0;
        }
    }
    return success;
}

BST_Node_t* BST_Access(BST_Node_t* root, BST_DATA_TYPE data) 
{
    if (root == NULL || data == root->data)
    {
        return root;
    }
    else
    {
        if (data < root->data)
        {
            return BST_Access(root->left, data);
        }
        else
        {
            return BST_Access(root->right, data);
        }
    }
}

BST_Node_t* BST_FindMinOnLeft(BST_Node_t* root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

BST_Node_t* BST_FindMaxOnRight(BST_Node_t* root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

int8_t BST_Delete(BST_Node_t* root, BST_DATA_TYPE data) 
{
    int8_t success = 0;
    if (root == NULL)
    {
        success = -1;
    }
    else
    {
        if (data < root->data)
        {
            success = BST_Delete(root->left, data);
        }
        else if (data > root->data)
        {
            success = BST_Delete(root->right, data);
        }
        else
        {
            if (root->left == NULL) 
            {
                BST_Node_t* temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL) 
            {
                BST_Node_t* temp = root->left;
                free(root);
                return temp;
            }

            BST_Node_t* temp = BST_FindMinOnLeft(root->right);
            root->data = temp->data;
            root->right = BST_Delete(root->right, temp->data);
        }
    }

    return success;
}

void BST_Traverse(BST_Node_t* root, EnumTraverse_t traverseType) {
    if (root != NULL) 
    {
        if (traverseType == eTraverse_PRE_ORDER)
        {
            printf("%d ", root->data);
            BST_Traverse(root->left, traverseType);
            BST_Traverse(root->right, traverseType);
        }
        else if (traverseType == eTraverse_IN_ORDER)
        {
            BST_Traverse(root->left, traverseType);
            printf("%d ", root->data);
            BST_Traverse(root->right, traverseType);
        }
        else
        {
            BST_Traverse(root->left, traverseType);
            BST_Traverse(root->right, traverseType);
            printf("%d ", root->data);
        }
    }
}

void BST_Destroy(BST_Node_t* root) 
{
    if (root != NULL) 
    {
        BST_Destroy(root->left);
        BST_Destroy(root->right);
        free(root);
    }
}
