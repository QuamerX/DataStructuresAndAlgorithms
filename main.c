#include <stdio.h>
#include <stdlib.h>
#include "Algorithms/Sort/sort.h"
#include "DataStructures/Tree/avl_tree.h"

int arr[100];
int size;

void CreateArray(void);
void PrintArray(int* arrayToPrint, int arraySize);

int main() 
{
	AVL_Node_t* root = NULL;
	root = AVL_Insert(root, 50);
	root = AVL_Insert(root, 75);
	root = AVL_Insert(root, 25);
	root = AVL_Insert(root, 30);
	root = AVL_Insert(root, 12);
	root = AVL_Insert(root, 35);
	root = AVL_Insert(root, 80);
	root = AVL_Insert(root, 7);
	root = AVL_Insert(root, 85);
	AVL_Print(root);
	root = AVL_Delete(root, 50);
	AVL_Print(root);
	root = AVL_Insert(root, 78);
	AVL_Print(root);
	root = AVL_Delete(root, 30);
	AVL_Print(root);
    return 0;
}

/*
int main() 
{
	BST_Node_t* root = NULL;
	root = BST_Insert(root, 37);
	root = BST_Insert(root, 75);
	root = BST_Insert(root, 25);
	root = BST_Insert(root, 12);
	root = BST_Insert(root, 30);
	root = BST_Insert(root, 36);
	root = BST_Insert(root, 31);
	root = BST_Insert(root, 35);
	BST_Print(root);
	root = BST_Delete(root, 37);
	BST_Print(root);
    return 0;
}
*/

/*
int main() 
{
	CreateArray();
    PrintArray(arr, size);
    QuickSort(arr, size, eOrderType_ASC);
    PrintArray(arr, size);
    return 0;
}
*/

void CreateArray()
{
	printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    if(size > 100)
    {
    	size = 100;
    }
    
    for(int i = 0; i < size; i++)
    {
    	arr[i] = (rand() % 100) + 1;
    }
}

void PrintArray(int* arrayToPrint, int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
    	printf("%d ", arrayToPrint[i]);
    }
    printf("\n");
}
