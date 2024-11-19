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
        newNode->isFirstRoot = 0;
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
        newNode->isFirstRoot = 1;
    }
    return newNode;
}

RB_Node_t* RB_RecolorNode(RB_Node_t* node, EnumColor_t color)
{
    if (node != NULL)
    {
        if (node->isFirstRoot == 1)
        {
            node->color = eColor_BLACK;
        }
        else
        {
            node->color = color;
        }
    }
    return node;
}

EnumColor_t RB_GetNodeColor(RB_Node_t* root)
{
    if (root == NULL)
    {
        return eColor_BLACK;
    }
    return root->color;
}

RB_Node_t* RB_LeftRotate(RB_Node_t* root)
{
	if(root != NULL)
	{	
		RB_Node_t* newRoot = root->right;
		root->right = newRoot->left;
		newRoot->left = root;
        if (root->isFirstRoot == 1)
        {
            root->isFirstRoot = 0;
            newRoot->isFirstRoot = 1;
        }
		return newRoot;
	}
	return root;
}

RB_Node_t* RB_LeftRotateAndChangeColor(RB_Node_t* root)
{
	if(root != NULL)
	{	
		RB_Node_t* newRoot = root->right;
		root->right = newRoot->left;
        if (RB_GetNodeColor(root->right) == eColor_BLACK)
        {
            RB_RecolorNode(root->right, eColor_RED);
        }
		newRoot->left = root;
        if (root->isFirstRoot == 1)
        {
            root->isFirstRoot = 0;
            newRoot->isFirstRoot = 1;
        }
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
        if (root->isFirstRoot == 1)
        {
            root->isFirstRoot = 0;
            newRoot->isFirstRoot = 1;
        }
		return newRoot;
	}
	return root;
}

RB_Node_t* RB_RightRotateAndChangeColor(RB_Node_t* root)
{
	if(root != NULL)
	{	
		RB_Node_t* newRoot = root->left;
		root->left = newRoot->right;
        if (RB_GetNodeColor(root->left) == eColor_BLACK)
        {
            RB_RecolorNode(root->left, eColor_RED);
        }
		newRoot->right = root;
        if (root->isFirstRoot == 1)
        {
            root->isFirstRoot = 0;
            newRoot->isFirstRoot = 1;
        }
		return newRoot;
	}
	return root;
}

RB_Node_t* RB_LeftRightRotate(RB_Node_t* root)
{
    root->left = RB_LeftRotate(root->left);
    root = RB_RightRotate(root);
    return root;
}

RB_Node_t* RB_RightLeftRotate(RB_Node_t* root)
{
    root->right = RB_RightRotate(root->right);
    root = RB_LeftRotate(root);
    return root;
}

uint8_t RB_IsDoubleRed(RB_Node_t* parent, RB_Node_t* child)
{
    if(RB_GetNodeColor(parent) == eColor_RED && RB_GetNodeColor(child) == eColor_RED)
    {
        return 1;
    }
    return 0;
}

RB_Node_t* RB_Recolor(RB_Node_t* root)
{
    if(root == NULL)
	{
		return root;
	}
    root = RB_RecolorNode(root, eColor_RED);
    root->left = RB_RecolorNode(root->left, eColor_BLACK);
    root->right = RB_RecolorNode(root->right, eColor_BLACK);
    return root;
}

RB_Node_t* RB_RecolorAfterRotate(RB_Node_t* root)
{
    if(root == NULL)
	{
		return root;
	}
    root = RB_RecolorNode(root, eColor_BLACK);
    root->left = RB_RecolorNode(root->left, eColor_RED);
    root->right = RB_RecolorNode(root->right, eColor_RED);
    return root;
}

RB_Node_t* RB_Balance(RB_Node_t* root)
{
	if(root == NULL)
	{
		return root;
	}

    if (root->left != NULL)
    {
        if (RB_IsDoubleRed(root->left, root->left->left))
        {
            if (RB_GetNodeColor(root->right) == eColor_RED) /* Uncle red */
            {
                root = RB_Recolor(root);
            }
            else
            {
                root = RB_RightRotate(root);
                root = RB_RecolorAfterRotate(root);
            }
        }
        else if (RB_IsDoubleRed(root->left, root->left->right))
        {
            if (RB_GetNodeColor(root->right) == eColor_RED) /* Uncle red */
            {
                root = RB_Recolor(root);
            }
            else
            {
                root = RB_LeftRightRotate(root);
                root = RB_RecolorAfterRotate(root);
            }
        }
    }
    if (root->right != NULL)
    {
        if (RB_IsDoubleRed(root->right, root->right->left))
        {
            if (RB_GetNodeColor(root->left) == eColor_RED) /* Uncle red */
            {
                root = RB_Recolor(root);
            }
            else
            {
                root = RB_RightLeftRotate(root);
                root = RB_RecolorAfterRotate(root);
            }
        }
        else if (RB_IsDoubleRed(root->right, root->right->right))
        {
            if (RB_GetNodeColor(root->left) == eColor_RED) /* Uncle red */
            {
                root = RB_Recolor(root);
            }
            else
            {
                root = RB_LeftRotate(root);
                root = RB_RecolorAfterRotate(root);
            }
        }
    }
    return root;
}

RB_Node_t* RB_Insert(RB_Node_t* root, RB_DATA_TYPE data)
{
    if (root == NULL)
    {
        root = RB_CreateNode(data);
    }
    else
    {
        if (data < root->data) 
        {
            root->left = RB_Insert(root->left, data);
        }
        else if (data > root->data) 
        {
            root->right = RB_Insert(root->right, data);
        }
        return RB_Balance(root);
    }
    return root;
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

RB_Node_t* RB_ResolveDoubleBlack(RB_Node_t* parent, EnumSide_t side, RB_Node_t* root)
{
    RB_Node_t* sibling = (side == eSide_LEFT ? parent->right : parent->left);
    if (sibling->color == eColor_BLACK) /* Recolor */
    {
        if (RB_GetNodeColor(sibling->left) == eColor_BLACK &&
            RB_GetNodeColor(sibling->right) == eColor_BLACK)
        {
            RB_RecolorNode(sibling, eColor_RED);
            RB_RecolorNode(parent, eColor_BLACK);
        }
    }
    else /* Rotation */
    {
        parent = (side == eSide_LEFT ? RB_LeftRotateAndChangeColor(parent) : RB_RightRotateAndChangeColor(parent));
        RB_Node_t* newRoot = (side == eSide_LEFT ? parent->left : parent->right);
        root = RB_Balance(newRoot);
    }
    return root;
}

RB_Node_t* RB_DeleteRecursive(RB_Node_t* parent, EnumSide_t side, RB_Node_t* root, RB_DATA_TYPE data)
{
    if (root == NULL) 
    {
        return root;
    }

    if (data < root->data) 
    {
        root->left = RB_DeleteRecursive(root, eSide_LEFT, root->left, data);
    } 
    else if (data > root->data) 
    {
        root->right = RB_DeleteRecursive(root, eSide_RIGHT, root->right, data);
    } 
    else 
    {
        if (root->color == eColor_RED)
        {
            if (root->left == NULL && root->right == NULL) 
            {
                free(root);
                root = NULL;
            } 
            else if (root->left == NULL) 
            {
                root->data = root->right->data;
                free(root->right);
                root->right = NULL;
            } 
            else if (root->right == NULL) 
            {
                root->data = root->left->data;
                free(root->left);
                root->left = NULL;
            } 
            else 
            {
                RB_Node_t* temp = RB_FindMax(root->left);
                root->data = temp->data;
                root->left = RB_DeleteRecursive(root, eSide_LEFT, root->left, temp->data);
            }
        }
        else
        {
            if (root->left == NULL && root->right == NULL) /* Double Black on deleted node */
            {
                root = RB_ResolveDoubleBlack(parent, side, root);
                free(root);
                root = NULL;
            }
            else if (root->left == NULL)
            {
                root->data = root->right->data;
                if (root->right->color == eColor_BLACK)
                {
                    root = RB_ResolveDoubleBlack(parent, side, root);
                }
                free(root->right);
                root->right = NULL;
                
                
            }
            else if (root->right == NULL)
            {
                root->data = root->left->data;
                if (root->left->color == eColor_BLACK)
                {
                    root = RB_ResolveDoubleBlack(parent, side, root);
                }
                free(root->left);
                root->left = NULL;
            }
            else 
            {
                RB_Node_t* temp = RB_FindMax(root->left);
                root->data = temp->data;
                root->left = RB_DeleteRecursive(root, eSide_LEFT, root->left, temp->data);
            }
        }
    }
    return root;
}

RB_Node_t* RB_Delete(RB_Node_t* root, RB_DATA_TYPE data) 
{
    return RB_DeleteRecursive(NULL, (EnumSide_t)NULL, root, data);
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
                printf("[%d - B]", root->data);
            }
            else
            {
                printf("[%d - R]", root->data);
            }
            RB_Traverse(root->left, traverseType);
            RB_Traverse(root->right, traverseType);
        }
        else if (traverseType == eTraverse_IN_ORDER)
        {
            RB_Traverse(root->left, traverseType);
            if (root->color == eColor_BLACK)
            {
                printf("[%d - B]", root->data);
            }
            else
            {
                printf("[%d - R]", root->data);
            }
            RB_Traverse(root->right, traverseType);
        }
        else
        {
            RB_Traverse(root->left, traverseType);
            RB_Traverse(root->right, traverseType);
            if (root->color == eColor_BLACK)
            {
                printf("[%d - B]", root->data);
            }
            else
            {
                printf("[%d - R]", root->data);
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

