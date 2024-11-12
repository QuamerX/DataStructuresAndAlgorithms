#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

AVL_Node_t* AVL_CreateNode(AVL_DATA_TYPE data)
{
    AVL_Node_t* new_node = (AVL_Node_t*)malloc(sizeof(AVL_Node_t));
    if (new_node != NULL) 
    {
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

int AVL_BalanceFactor(AVL_Node_t* node)
{
	int leftHeight = AVL_Height(node->left);
	int rightHeight = AVL_Height(node->right);
	
	return (leftHeight - rightHeight);
}

int AVL_Height(AVL_Node_t* node)
{
    if (node == NULL)
    {   
    	return -1;
    }

    int leftHeight = AVL_Height(node->left);
    int rightHeight = AVL_Height(node->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

AVL_Node_t* AVL_RightRotate(AVL_Node_t* root)
{
	/* TODO: Implement */
	return root;
}

AVL_Node_t* AVL_LeftRotate(AVL_Node_t* root)
{
	/* TODO: Implement */
	return root;
}

AVL_Node_t* AVL_RightLeftRotate(AVL_Node_t* root)
{
	/* TODO: Implement */
	return root;
}

AVL_Node_t* AVL_LeftRightRotate(AVL_Node_t* root)
{
	/* TODO: Implement */
	return root;
}

AVL_Node_t* AVL_Balance(AVL_Node_t* root)
{
    if(AVL_Height(root) == 1)
    {
    	/* Left subtree's level is higher */
    	/* TODO: Implement */
    	return root;
    }
    else if(AVL_Height(root) == -1)
    {
    	/* Right subtree's level is higher */
    	/* TODO: Implement */
    	return root;
    }
    else if(AVL_Height(root) > 1)
    {
    	/* Tree is left-heavy */
    	/* TODO: Implement */
    	return root;
    }
    else if(AVL_Height(root) > 1)
    {
    	/* Tree is right-heavy */
    	/* TODO: Implement */
    	return root;
    }
    else
    {
    	/* Perfectly balanced */
    	return root;
    }
}

AVL_Node_t* AVL_Insert(AVL_Node_t* root, AVL_DATA_TYPE data)
{
    if (root == NULL)
    {
        return AVL_CreateNode(data);
    }
    else
    {
        if (data < root->data) 
        {
            root->left = AVL_Insert(root->left, data);
        }
        else if (data > root->data) 
        {
            root->right = AVL_Insert(root->right, data);
        }
    }
    root = AVL_Balance(root);
    return root;
}

int8_t AVL_Search(AVL_Node_t* root, AVL_DATA_TYPE data)
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
            return AVL_Search(root->left, data);
        }
        else if (data > root->data)
        {
            return AVL_Search(root->right, data);
        }
        else
        {
            success = 0;
        }
    }
    return success;
}

AVL_Node_t* AVL_Access(AVL_Node_t* root, AVL_DATA_TYPE data) 
{
    if (root == NULL || data == root->data)
    {
        return root;
    }
    else
    {
        if (data < root->data)
        {
            return AVL_Access(root->left, data);
        }
        else if (data > root->data)
        {
            return AVL_Access(root->right, data);
        }
        else
        {
        	return NULL;
        }
    }
}

AVL_Node_t* AVL_FindNewRoot(AVL_Node_t* root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

AVL_Node_t* AVL_Delete(AVL_Node_t* root, AVL_DATA_TYPE data) 
{
    if (root != NULL)
    {
        if (data < root->data)
        {
            root->left = AVL_Delete(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = AVL_Delete(root->right, data);
        }
        else
        {
            if (root->left == NULL) 
            {
                AVL_Node_t* newRoot = root->right;
                free(root);
                return newRoot;
            }
            else if (root->right == NULL) 
            {
                AVL_Node_t* newRoot = root->left;
                free(root);
                return newRoot;
            }
            AVL_Node_t* newRoot = AVL_FindNewRoot(root->left); /* In-order predecessor */
            root->data = newRoot->data; 
            root->left = AVL_Delete(root->left, newRoot->data);
        }
    }
    root = AVL_Balance(root);
    return root;
}

void AVL_Print(AVL_Node_t* root)
{
    printf("--------------\n");
    printf("Pre-order: ");
    AVL_Traverse(root, eTraverse_PRE_ORDER);
    printf("\n");
    printf("In-order: ");
    AVL_Traverse(root, eTraverse_IN_ORDER);
    printf("\n");
    printf("Post-order: ");
    AVL_Traverse(root, eTraverse_POST_ORDER);
    printf("\n");
    printf("++++++++++++++\n");
}

void AVL_Traverse(AVL_Node_t* root, EnumTraverse_t traverseType) 
{
    if (root != NULL) 
    {
        if (traverseType == eTraverse_PRE_ORDER)
        {
            printf("%d ", root->data);
            AVL_Traverse(root->left, traverseType);
            AVL_Traverse(root->right, traverseType);
        }
        else if (traverseType == eTraverse_IN_ORDER)
        {
            AVL_Traverse(root->left, traverseType);
            printf("%d ", root->data);
            AVL_Traverse(root->right, traverseType);
        }
        else
        {
            AVL_Traverse(root->left, traverseType);
            AVL_Traverse(root->right, traverseType);
            printf("%d ", root->data);
        }
    }
}

void AVL_Destroy(AVL_Node_t* root) 
{
    if (root != NULL) 
    {
        AVL_Destroy(root->left);
        AVL_Destroy(root->right);
        free(root);
    }
}

