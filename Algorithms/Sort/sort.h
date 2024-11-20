#ifndef SORT_H
#define SORT_H

typedef enum 
{
    eOrderType_ASC,
    eOrderType_DESC
}EnumOrderType_t;

void BubbleSort(int* arrayToSort, int arraySize, EnumOrderType_t orderType);
void InsertionSort(int* arrayToSort, int arraySize, EnumOrderType_t orderType);
void SelectionSort(int* arrayToSort, int arraySize, EnumOrderType_t orderType);
void MergeSort(int* arrayToSort, int arraySize, EnumOrderType_t orderType);
void QuickSort(int* arrayToSort, int arraySize, EnumOrderType_t orderType);

#endif /* SORT_H */
