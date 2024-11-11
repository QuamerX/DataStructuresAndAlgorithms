#include <stdio.h>
#include <stdlib.h>
#include "Algorithms/Sort/sort.h"

int arr[100];
int size;

void CreateArray(void);
void PrintArray(int* arrayToPrint, int arraySize);

int main() 
{
	CreateArray();
    PrintArray(arr, size);
    QuickSort(arr, size, eOrderType_ASC);
    PrintArray(arr, size);
    return 0;
}

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
