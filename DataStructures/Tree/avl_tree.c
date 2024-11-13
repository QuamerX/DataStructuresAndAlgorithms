#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

AVL_Node_t* AVL_CreateNode(AVL_DATA_TYPE data)
{
    AVL_Node_t* newNode = (AVL_Node_t*)malloc(sizeof(AVL_Node_t));
    if (newNode != NULL) 
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

int AVL_Height(AVL_Node_t* root)
{
    if (root == NULL)
    {   
    	return -1;
    }

    int leftHeight = AVL_Height(root->left);
    int rightHeight = AVL_Height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int AVL_BalanceFactor(AVL_Node_t* root)
{
	int leftHeight = AVL_Height(root->left);
	int rightHeight = AVL_Height(root->right);
	
	return (leftHeight - rightHeight);
}

AVL_Node_t* AVL_LeftRotate(AVL_Node_t* root)
{
	if(root != NULL)
	{	
		AVL_Node_t* newRoot = root->right;
		root->right = newRoot->left;
		newRoot->left = root;
		return newRoot;
	}
	return root;
}

AVL_Node_t* AVL_RightRotate(AVL_Node_t* root)
{
	if(root != NULL)
	{	
		AVL_Node_t* newRoot = root->left;
		root->left = newRoot->right;
		newRoot->right = root;
		return newRoot;
	}
	return root;
}

AVL_Node_t* AVL_LeftRightRotate(AVL_Node_t* root)
{
    root->left = AVL_LeftRotate(root->left);
    return AVL_RightRotate(root);
}

AVL_Node_t* AVL_RightLeftRotate(AVL_Node_t* root)
{
    root->right = AVL_RightRotate(root->right);
    return AVL_LeftRotate(root);
}

AVL_Node_t* AVL_Balance(AVL_Node_t* root)
{
	if(root == NULL)
	{
		return root;
	}

    int balanceFactor = AVL_BalanceFactor(root);
    if(balanceFactor == 2) /* Left Heavy */
    {
        if (AVL_BalanceFactor(root->left) >= 0)
        {
            root = AVL_RightRotate(root);
        }
        else if (AVL_BalanceFactor(root->left) == -1)
        {
            root = AVL_LeftRightRotate(root);
        }
    }
    else if(balanceFactor == -2) /* Right Heavy */
    {
        if (AVL_BalanceFactor(root->right) <= 0)
        {
            root = AVL_LeftRotate(root);
        }
        else if (AVL_BalanceFactor(root->right) == 1)
        {
            root = AVL_RightLeftRotate(root);
        }
    }
    return root;
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
    return AVL_Balance(root);
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

AVL_Node_t* AVL_FindMax(AVL_Node_t* root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

AVL_Node_t* AVL_Delete(AVL_Node_t* root, AVL_DATA_TYPE data) 
{
    if (root == NULL) 
    {
        return root;
    }

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
        if (root->left == NULL && root->right == NULL) 
        {
            free(root);
            root = NULL;
        } 
        else if (root->left == NULL) 
        {
            AVL_Node_t* temp = root;
            root = root->right;
            free(temp);
        } 
        else if (root->right == NULL) 
        {
            AVL_Node_t* temp = root;
            root = root->left;
            free(temp);
        } 
        else 
        {
            AVL_Node_t* temp = AVL_FindMax(root->left);
            root->data = temp->data;
            root->left = AVL_Delete(root->left, temp->data);
        }
    }

    return AVL_Balance(root);
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

