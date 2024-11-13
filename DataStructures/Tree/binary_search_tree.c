#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

BST_Node_t* BST_CreateNode(BST_DATA_TYPE data)
{
    BST_Node_t* newNode = (BST_Node_t*)malloc(sizeof(BST_Node_t));
    if (newNode != NULL) 
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

BST_Node_t* BST_Insert(BST_Node_t* root, BST_DATA_TYPE data)
{
    if (root == NULL)
    {
        return BST_CreateNode(data);
    }
    else
    {
        if (data < root->data) 
        {
            root->left = BST_Insert(root->left, data);
        }
        else if (data > root->data) 
        {
            root->right = BST_Insert(root->right, data);
        }
    }
    return root;
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
        else if (data > root->data)
        {
            return BST_Access(root->right, data);
        }
        else
        {
        	return NULL;
        }
    }
}

BST_Node_t* BST_FindNewRoot(BST_Node_t* root)
{
	while (root != NULL && root->right != NULL)
	{
	    root = root->right;
	}
	return root;
}

BST_Node_t* BST_Delete(BST_Node_t* root, BST_DATA_TYPE data) 
{
    if (root != NULL)
    {
        if (data < root->data)
        {
            root->left = BST_Delete(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = BST_Delete(root->right, data);
        }
        else
        {
            if (root->left == NULL) 
            {
                BST_Node_t* newRoot = root->right;
                free(root);
                return newRoot;
            }
            else if (root->right == NULL) 
            {
                BST_Node_t* newRoot = root->left;
                free(root);
                return newRoot;
            }
            BST_Node_t* newRoot = BST_FindNewRoot(root->left); /* In-order predecessor */
            root->data = newRoot->data; 
    		root->left = BST_Delete(root->left, newRoot->data);
        }
    }
    return root;
}

void BST_Print(BST_Node_t* root)
{
	printf("--------------\n");
	printf("Pre-order: ");
	BST_Traverse(root, eTraverse_PRE_ORDER);
	printf("\n");
	printf("In-order: ");
	BST_Traverse(root, eTraverse_IN_ORDER);
	printf("\n");
	printf("Post-order: ");
	BST_Traverse(root, eTraverse_POST_ORDER);
	printf("\n");
	printf("++++++++++++++\n");
}

void BST_Traverse(BST_Node_t* root, EnumTraverse_t traverseType) 
{
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
