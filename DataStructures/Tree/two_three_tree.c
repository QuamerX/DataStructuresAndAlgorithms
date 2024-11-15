#include <stdlib.h>
#include <stdio.h>
#include "two_three_tree.h"

TTT_Node_t* TTT_CreateNode(TTT_DATA_TYPE key)
{
    TTT_Node_t* newNode = (TTT_Node_t*)malloc(sizeof(TTT_Node_t));
    if (newNode != NULL) 
    {
        newNode->leftKey = key;
        newNode->left = NULL;
        newNode->middle = NULL;
        newNode->right = NULL;
        newNode->keyCount = 1;
    }
    return newNode;
}

TTT_Node_t* TTT_Split(TTT_Node_t* root)
{
	/* TODO: Implement */
	return root;
}

uint8_t TTT_IsLeafNode(TTT_Node_t* root)
{
	if(root->left == NULL && root->middle == NULL && root->right == NULL)
	{
		return 1;	
	}
	return 0;
}

TTT_Node_t* TTT_Insert(TTT_Node_t* root, TTT_DATA_TYPE key)
{
    if (root == NULL)
    {
        return TTT_CreateNode(key);
    }
    else
    {
    	if(TTT_IsLeafNode(root) == 0)
    	{
    		if(root->keyCount == 1)
			{
				if (key < root->leftKey) 
				{
					root->left = TTT_Insert(root->left, key);
				}
				else
				{
					root->middle = TTT_Insert(root->middle, key);
				}
			}
			else /* root->keyCount == 2 */
			{	
				if (key < root->leftKey) 
				{
					root->left = TTT_Insert(root->left, key);
				}
				else if (key > root->leftKey && key < root->rightKey) 
				{
					root->middle = TTT_Insert(root->middle, key);
				}
				else
				{
					root->right = TTT_Insert(root->right, key);
				}
			}
    	}
		else
		{
			if(root->keyCount == 1)
			{
				if(key > root->leftKey)
				{
					root->rightKey = key;
				}
				else
				{
					root->rightKey = root->leftKey;
					root->leftKey = key;
				}
			}
			else /* root->keyCount == 2 */
			{	
				root = TTT_Split(root);
			}
		}
    }
    return root;
}

int8_t TTT_Search(TTT_Node_t* root, TTT_DATA_TYPE key)
{
    if (root == NULL) 
    {
        return 0;
    }

    if (key == root->leftKey || (root->keyCount == 2 && key == root->rightKey))
    {
        return 1;
    }

	if(root->keyCount == 1)
	{
		if (key < root->leftKey)
	    {
	        return TTT_Search(root->left, key);
	    }
	    else
	    {
	        return TTT_Search(root->middle, key);
	    }
	}
	else
	{
	    if (key < root->leftKey)
	    {
	        return TTT_Search(root->left, key);
	    }
	    else if (key > root->leftKey && key < root->rightKey)
	    {
	        return TTT_Search(root->middle, key);
	    }
	    else
	    {
	    	return TTT_Search(root->right, key);
	    }
	}
}

TTT_Node_t* TTT_Access(TTT_Node_t* root, TTT_DATA_TYPE key) 
{
    if (root == NULL) 
    {
        return NULL;
    }

    if (key == root->leftKey || (root->keyCount == 2 && key == root->rightKey))
    {
        return root;
    }

	if(root->keyCount == 1)
	{
		if (key < root->leftKey)
	    {
	        return TTT_Access(root->left, key);
	    }
	    else
	    {
	        return TTT_Access(root->middle, key);
	    }
	}
	else
	{
	    if (key < root->leftKey)
	    {
	        return TTT_Access(root->left, key);
	    }
	    else if (key > root->leftKey && key < root->rightKey)
	    {
	        return TTT_Access(root->middle, key);
	    }
	    else
	    {
	    	return TTT_Access(root->right, key);
	    }
	}
}

TTT_Node_t* TTT_Delete(TTT_Node_t* root, TTT_DATA_TYPE key)
{
	/* TODO: Implement */
	return root;
}

void TTT_Print(TTT_Node_t* root)
{
    printf("--------------\n");
    printf("Pre-order: ");
    TTT_Traverse(root, eTraverse_PRE_ORDER);
    printf("\n");
    printf("In-order: ");
    TTT_Traverse(root, eTraverse_IN_ORDER);
    printf("\n");
    printf("Post-order: ");
    TTT_Traverse(root, eTraverse_POST_ORDER);
    printf("\n");
    printf("++++++++++++++\n");
}

void TTT_Traverse(TTT_Node_t* root, EnumTraverse_t traverseType) 
{
    if (root != NULL) 
    {
        if (traverseType == eTraverse_PRE_ORDER)
        {
        	if(root->keyCount == 1)
        	{
        		printf(" |%d| ", root->leftKey);
		        TTT_Traverse(root->left, traverseType);
		        TTT_Traverse(root->middle, traverseType);
        	}
        	else
        	{
        		printf(" |%d-%d| ", root->leftKey, root->rightKey);
		        TTT_Traverse(root->left, traverseType);
		        TTT_Traverse(root->middle, traverseType);
		        TTT_Traverse(root->right, traverseType);
        	}
        }
        else if (traverseType == eTraverse_IN_ORDER)
        {
	    	TTT_Traverse(root->left, traverseType);
	        printf("|%d-", root->leftKey);
	        TTT_Traverse(root->middle, traverseType);
		    printf("%d|", root->rightKey);
		    TTT_Traverse(root->right, traverseType);
        }
        else
        {
        	if(root->keyCount == 1)
        	{
		        TTT_Traverse(root->left, traverseType);
		        TTT_Traverse(root->middle, traverseType);
		        printf(" |%d| ", root->leftKey);
        	}
        	else
        	{
		        TTT_Traverse(root->left, traverseType);
		        TTT_Traverse(root->middle, traverseType);
		        TTT_Traverse(root->right, traverseType);
		        printf(" |%d-%d| ", root->leftKey, root->rightKey);
        	}
        }
    }
}


void TTT_Destroy(TTT_Node_t* root)
{
	if (root != NULL) 
    {
        TTT_Destroy(root->left);
        TTT_Destroy(root->middle);
        TTT_Destroy(root->right);
        free(root);
    }
}
