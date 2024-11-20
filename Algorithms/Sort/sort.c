#include <stdlib.h>
#include "sort.h"

void Swap(int* a, int* b);

void SelectionSort(int* arrayToSort, int arraySize, EnumOrderType_t orderType)
{
    /* O(n^2) */
    if (orderType == eOrderType_ASC)
    {
        for (int i = 0; i < arraySize; i++)
        {
            for (int j = i + 1; j < arraySize; j++)
            {
                if (arrayToSort[j] < arrayToSort[i])
                {
                    Swap(&(arrayToSort[i]), &(arrayToSort[j]));
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < arraySize; i++)
        {
            for (int j = i + 1; j < arraySize; j++)
            {
                if (arrayToSort[j] > arrayToSort[i])
                {
                    Swap(&(arrayToSort[i]), &(arrayToSort[j]));
                }
            }
        }
    }
}

void BubbleSort(int* arrayToSort, int arraySize, EnumOrderType_t orderType)
{
    /* O(n^2) */
    int sortContinues;
    if (orderType == eOrderType_ASC)
    {
        do
        {
            sortContinues = 0;
            for (int i = arraySize - 1; i > 0; i--)
            {
                if (arrayToSort[i - 1] > arrayToSort[i])
                {
                    Swap(&(arrayToSort[i]), &(arrayToSort[i - 1]));
                    sortContinues = 1;
                }
            }
        } while (sortContinues);
    }
    else
    {
        do
        {
            sortContinues = 0;
            for (int i = arraySize - 1; i > 0; i--)
            {
                if (arrayToSort[i - 1] < arrayToSort[i])
                {
                    Swap(&(arrayToSort[i]), &(arrayToSort[i - 1]));
                    sortContinues = 1;
                }
            }
        } while (sortContinues);
    }
}

void InsertionSort(int* arrayToSort, int arraySize, EnumOrderType_t orderType) 
{
    if (orderType == eOrderType_ASC)
    {
        for (int i = 1; i < arraySize; i++)
        {
            int j;
            int key = arrayToSort[i];
            for (j = i - 1; j >= 0 && arrayToSort[j] > key; j--)
            {
                arrayToSort[j + 1] = arrayToSort[j];
            }
            arrayToSort[j + 1] = key;
        }
    }
    else
    {
        for (int i = 1; i < arraySize; i++)
        {
            int j;
            int key = arrayToSort[i];
            for (j = i - 1; j >= 0 && arrayToSort[j] < key; j--)
            {
                arrayToSort[j + 1] = arrayToSort[j];
            }
            arrayToSort[j + 1] = key;
        }
    }
}

void Merge(int* arrayToSort, int leftIndex, int midIndex, int rightIndex, EnumOrderType_t orderType)
{
	/* Creating Left and Right arrays */
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;
    int* leftArray = (int*)malloc(leftArraySize * sizeof(int));
    int* rightArray = (int*)malloc(rightArraySize * sizeof(int));
    for (int i = 0; i < leftArraySize; i++)
    {
        leftArray[i] = arrayToSort[leftIndex + i];
    }
    for (int j = 0; j < rightArraySize; j++)
    {
        rightArray[j] = arrayToSort[midIndex + 1 + j];
    }

	/* Comparing and sorting Left and Right arrays */
    int i = 0, j = 0, k = leftIndex;
    if (orderType == eOrderType_ASC)
    {
        while (i < leftArraySize && j < rightArraySize)
        {
            if (leftArray[i] <= rightArray[j])
            {
                arrayToSort[k++] = leftArray[i++];
            }
            else
            {
                arrayToSort[k++] = rightArray[j++];
            }
        }
    }
    else
    {
        while (i < leftArraySize && j < rightArraySize)
        {
            if (leftArray[i] >= rightArray[j])
            {
                arrayToSort[k++] = leftArray[i++];
            }
            else
            {
                arrayToSort[k++] = rightArray[j++];
            }
        }
    }

	/* Add remaining elements in arrays after compare and sort operation */
    while (i < leftArraySize) arrayToSort[k++] = leftArray[i++];
    while (j < rightArraySize) arrayToSort[k++] = rightArray[j++];

    free(leftArray);
    free(rightArray);
}

void MergeSortRecursive(int* arrayToSort, int leftIndex, int rightIndex, EnumOrderType_t orderType)
{
    if (leftIndex < rightIndex)
    {
        int midIndex = (rightIndex - leftIndex) / 2;
        MergeSortRecursive(arrayToSort, leftIndex, (leftIndex + midIndex), orderType);
        MergeSortRecursive(arrayToSort, (leftIndex + midIndex + 1), rightIndex, orderType);
        Merge(arrayToSort, leftIndex, leftIndex + midIndex, rightIndex, orderType);
    }
}

void MergeSort(int* arrayToSort, int arraySize, EnumOrderType_t orderType)
{
    MergeSortRecursive(arrayToSort, 0, arraySize - 1, orderType);
}

int QuickSortPartition(int* arrayToSort, int lowIndex, int highIndex, EnumOrderType_t orderType) 
{
    /* Use the last element as the pivot */
    int pivot = arrayToSort[highIndex];
    int i = lowIndex;
    int j = highIndex - 1;
	if(orderType == eOrderType_ASC)
	{
		while (j >= i) 
		{
            if (arrayToSort[i] >= pivot && arrayToSort[j] <= pivot) 
		    {
		        Swap(&arrayToSort[i], &arrayToSort[j]);
                i++;
                j--;
		    }
            else
            {
                if (arrayToSort[i] <= pivot) 
                {
                    i++;
                }
                if (arrayToSort[j] >= pivot) 
                {
                    j--;
                }
            }
		}
	}
	else
	{
		while (j >= i) 
		{            
            if (arrayToSort[i] <= pivot && arrayToSort[j] >= pivot) 
		    {
		        Swap(&arrayToSort[i], &arrayToSort[j]);
                i++;
                j--;
		    }
            else
            {
                if (arrayToSort[i] >= pivot) 
                {
                    i++;
                }
                if (arrayToSort[j] <= pivot) 
                {
                    j--;
                }
            }
		}
	}
    Swap(&arrayToSort[j + 1], &arrayToSort[highIndex]);
    return j + 1;
}

void QuickSortRecursive(int* arrayToSort, int lowIndex, int highIndex, EnumOrderType_t orderType)
{
	if(lowIndex < highIndex)
	{
		int pivotIndex = QuickSortPartition(arrayToSort, lowIndex, highIndex, orderType);
        QuickSortRecursive(arrayToSort, lowIndex, pivotIndex - 1, orderType);
        QuickSortRecursive(arrayToSort, pivotIndex + 1, highIndex, orderType);
	}
}

void QuickSort(int* arrayToSort, int arraySize, EnumOrderType_t orderType)
{
	QuickSortRecursive(arrayToSort, 0, arraySize - 1, orderType);
}

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

