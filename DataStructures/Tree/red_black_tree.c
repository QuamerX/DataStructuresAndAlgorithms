#include <stdio.h>
#include <stdlib.h>
#include "red_black_tree.h"

RB_Node_t* RB_CreateNode(RB_DATA_TYPE data)
{
    RB_Node_t* newNode = (RB_Node_t*)malloc(sizeof(RB_Node_t));
    if (newNode != NULL) 
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->color = eColor_RED;
        newNode->isRoot = 0;
    }
    return newNode;
}

RB_Node_t* RB_CreateRoot(RB_DATA_TYPE data)
{
    RB_Node_t* newNode = (RB_Node_t*)malloc(sizeof(RB_Node_t));
    if (newNode != NULL) 
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->color = eColor_BLACK;
        newNode->isRoot = 1;
    }
    return newNode;
}

int RB_Height(RB_Node_t* root)
{
    if (root == NULL)
    {   
    	return -1;
    }

    int leftHeight = RB_Height(root->left);
    int rightHeight = RB_Height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int RB_BalanceFactor(RB_Node_t* root)
{
	int leftHeight = RB_Height(root->left);
	int rightHeight = RB_Height(root->right);
	
	return (leftHeight - rightHeight);
}

RB_Node_t* RB_LeftRotate(RB_Node_t* root)
{
	if(root != NULL)
	{	
		RB_Node_t* newRoot = root->right;
		root->right = newRoot->left;
		newRoot->left = root;
		return newRoot;
	}
	return root;
}

RB_Node_t* RB_RightRotate(RB_Node_t* root)
{
	if(root != NULL)
	{	
		RB_Node_t* newRoot = root->left;
		root->left = newRoot->right;
		newRoot->right = root;
		return newRoot;
	}
	return root;
}

RB_Node_t* RB_LeftRightRotate(RB_Node_t* root)
{
    root->left = RB_LeftRotate(root->left);
    return RB_RightRotate(root);
}

RB_Node_t* RB_RightLeftRotate(RB_Node_t* root)
{
    root->right = RB_RightRotate(root->right);
    return RB_LeftRotate(root);
}

EnumColor_t RB_NodeColor(RB_Node_t* root)
{
    if (root == NULL)
    {
        return eColor_BLACK;
    }
    return root->color;
}

uint8_t RB_IsDoubleRed(RB_Node_t* left, RB_Node_t* right)
{
    if(RB_NodeColor(left) == eColor_RED && RB_NodeColor(right) == eColor_RED)
    {
        return 1;
    }
    return 0;
}

RB_Node_t* RB_Balance(RB_Node_t* root)
{
	if(root == NULL)
	{
		return root;
	}

    if (RB_IsDoubleRed(root->left, root->left->left))
    {
        if (RB_NodeColor(root->right) == eColor_RED) /* Uncle red */
        {
            
        }
        else
        {

        }
    }
    else if (RB_IsDoubleRed(root->left, root->left->right))
    {
        if (RB_NodeColor(root->right) == eColor_RED) /* Uncle red */
        {
            
        }
        else
        {

        }
    }
    else if (RB_IsDoubleRed(root->right, root->right->left))
    {
        if (RB_NodeColor(root->left) == eColor_RED) /* Uncle red */
        {
            
        }
        else
        {

        }
    }
    else if (RB_IsDoubleRed(root->right, root->right->right))
    {
        if (RB_NodeColor(root->left) == eColor_RED) /* Uncle red */
        {
            
        }
        else
        {

        }
    }
    return root;
}


RB_Node_t* RB_Insert(RB_Node_t* root, RB_DATA_TYPE data)
{
    if (root != NULL)
    {
        if (data < root->data) 
        {
            root->left = RB_Insert(root->left, data);
        }
        else if (data > root->data) 
        {
            root->right = RB_Insert(root->right, data);
        }
    }
    return RB_Balance(root);
}

int8_t RB_Search(RB_Node_t* root, RB_DATA_TYPE data)
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
            return RB_Search(root->left, data);
        }
        else if (data > root->data)
        {
            return RB_Search(root->right, data);
        }
        else
        {
            success = 0;
        }
    }
    return success;
}

RB_Node_t* RB_Access(RB_Node_t* root, RB_DATA_TYPE data) 
{
    if (root == NULL || data == root->data)
    {
        return root;
    }
    else
    {
        if (data < root->data)
        {
            return RB_Access(root->left, data);
        }
        else if (data > root->data)
        {
            return RB_Access(root->right, data);
        }
        else
        {
        	return NULL;
        }
    }
}

RB_Node_t* RB_FindMax(RB_Node_t* root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

RB_Node_t* RB_Delete(RB_Node_t* root, RB_DATA_TYPE data) 
{
    if (root == NULL) 
    {
        return root;
    }

    if (data < root->data) 
    {
        root->left = RB_Delete(root->left, data);
    } 
    else if (data > root->data) 
    {
        root->right = RB_Delete(root->right, data);
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
            RB_Node_t* temp = root;
            root = root->right;
            free(temp);
        } 
        else if (root->right == NULL) 
        {
            RB_Node_t* temp = root;
            root = root->left;
            free(temp);
        } 
        else 
        {
            RB_Node_t* temp = RB_FindMax(root->left);
            root->data = temp->data;
            root->left = RB_Delete(root->left, temp->data);
        }
    }

    return RB_Balance(root);
}

void RB_Print(RB_Node_t* root)
{
    printf("--------------\n");
    printf("Pre-order: ");
    RB_Traverse(root, eTraverse_PRE_ORDER);
    printf("\n");
    printf("In-order: ");
    RB_Traverse(root, eTraverse_IN_ORDER);
    printf("\n");
    printf("Post-order: ");
    RB_Traverse(root, eTraverse_POST_ORDER);
    printf("\n");
    printf("++++++++++++++\n");
}

void RB_Traverse(RB_Node_t* root, EnumTraverse_t traverseType) 
{
    if (root != NULL) 
    {
        if (traverseType == eTraverse_PRE_ORDER)
        {
            if (root->color == eColor_BLACK)
            {
                printf("[%d-BLACK]", root->data);
            }
            else
            {
                printf("[%d-RED]", root->data);
            }
            RB_Traverse(root->left, traverseType);
            RB_Traverse(root->right, traverseType);
        }
        else if (traverseType == eTraverse_IN_ORDER)
        {
            RB_Traverse(root->left, traverseType);
            if (root->color == eColor_BLACK)
            {
                printf("[%d-BLACK]", root->data);
            }
            else
            {
                printf("[%d-RED]", root->data);
            }
            RB_Traverse(root->right, traverseType);
        }
        else
        {
            RB_Traverse(root->left, traverseType);
            RB_Traverse(root->right, traverseType);
            if (root->color == eColor_BLACK)
            {
                printf("[%d-BLACK]", root->data);
            }
            else
            {
                printf("[%d-RED]", root->data);
            }
        }
    }
}

void RB_Destroy(RB_Node_t* root) 
{
    if (root != NULL) 
    {
        RB_Destroy(root->left);
        RB_Destroy(root->right);
        free(root);
    }
}

