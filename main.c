#include <stdio.h>
#include <stdlib.h>
#include "Algorithms/Sort/sort.h"
#include "DataStructures/Tree/binary_heap.h"

int arr[100];
int size;

void CreateArray(void);
void PrintArray(int* arrayToPrint, int arraySize);

int main()
{
	int arr[] = {10, 20, 15, 30, 40, 50, 35};
	BH_Handle_t* handle = BH_Create(128, MAX_HEAP);
	for (size_t i = 0; i < 7; i++)
	{
		BH_Insert(handle, arr[i]);
		BH_Print(handle);
	}

	BH_HeapSort(handle);

	/*
	for (size_t i = 0; i < 7; i++)
	{
		BH_Delete(handle);
		BH_Print(handle);
	}
	handle->index = 8;
	BH_Print(handle);
	*/
	return 0;
}

/*
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
*/

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
