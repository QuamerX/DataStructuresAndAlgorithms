#include "linked_list.h"

LinkedList_t* LinkedList_Create() 
{
	LinkedList_t* handle = (LinkedList_t*)malloc(sizeof(LinkedList_t));
	return handle;
}

void LinkedList_Destroy(LinkedList_t* handle)
{
	for (uint32_t i = 0; i < handle->length; i++)
	{
		struct Node* node = handle->head->next;
		free(handle->head);
		handle->head = node;
	}
	free(handle);
}

void LinkedList_Display(LinkedList_t* handle)
{
	printf("-----\n");
	struct Node* node = handle->head;
	for (int i = 0; i < handle->length; i++)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("+++++\n");
}

DATA_TYPE LinkedList_Max(LinkedList_t* handle)
{
	struct Node* node = handle->head;
	DATA_TYPE max = handle->head->data;
	for (uint32_t i = 0; i < handle->length; i++)
	{
		if (node->data > max)
		{
			max = node->data;
		}
		node = node->next;
	}
	return max;
}

struct Node* LinkedList_Search(LinkedList_t* handle, DATA_TYPE data)
{
	struct Node* returnNode = NULL;
	struct Node* node = handle->head;
	for (uint32_t i = 0; i < handle->length; i++)
	{
		if (node->data == data)
		{
			returnNode = node;
			break;
		}
		node = node->next;
	}
	return returnNode;
}
