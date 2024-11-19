#include <stdio.h>
#include <stdlib.h>
#include "Algorithms/Sort/sort.h"
#include "DataStructures/Tree/red_black_tree.h"

int arr[100];
int size;

void CreateArray(void);
void PrintArray(int* arrayToPrint, int arraySize);

int main() 
{
	RB_Node_t* root = RB_CreateRoot(50);
	RB_Print(root);
	root = RB_Insert(root, 65);
	RB_Print(root);
	root = RB_Insert(root, 20);
	RB_Print(root);
	root = RB_Insert(root, 15);
	RB_Print(root);
	root = RB_Insert(root, 35);
	RB_Print(root);
	root = RB_Insert(root, 55);
	RB_Print(root);
	root = RB_Insert(root, 70);
	RB_Print(root);
	root = RB_Insert(root, 80);
	RB_Print(root);
	root = RB_Insert(root, 68);
	RB_Print(root);
	root = RB_Insert(root, 90);
	RB_Print(root);

	root = RB_Delete(root, 55);
	RB_Print(root);
	root = RB_Delete(root, 30);
	RB_Print(root);
	root = RB_Delete(root, 90);
	RB_Print(root);
	root = RB_Delete(root, 80);
	RB_Print(root);
	root = RB_Delete(root, 50);
	RB_Print(root);
	root = RB_Delete(root, 35);
	RB_Print(root);
	root = RB_Delete(root, 15);
	RB_Print(root);

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
