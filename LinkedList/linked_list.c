#include <stdlib.h>
#include "linked_list.h"

LinkedList_t* LinkedList_Create() 
{
	LinkedList_t* handle = (LinkedList_t*)malloc(sizeof(LinkedList_t));
	if (handle != NULL)
	{
		handle->head = NULL;
		handle->tail = NULL;
		handle->length = 0;
	}
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

struct Node* LinkedList_CreateNode(DATA_TYPE data) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode != NULL)
	{
		newNode->data = data;
	}
	return newNode;
}

void LinkedList_InsertFirstNode(LinkedList_t* handle, DATA_TYPE data) 
{
	struct Node* newNode = LinkedList_CreateNode(data);
	if (newNode != NULL)
	{
		handle->head = newNode;
		handle->tail = handle->head;
		handle->length = 1;
	}
}

int8_t LinkedList_InsertAtHead(LinkedList_t* handle, DATA_TYPE data)
{
	int8_t success = -1;
	if (handle->length == 0)
	{
		LinkedList_InsertFirstNode(handle, data);
	}
	else
	{
		struct Node* newHead = LinkedList_CreateNode(data);
		if (newHead != NULL)
		{
			newHead->next = handle->head;
			handle->head = newHead;
			handle->length++;
			success = 0;
		}
	}
	return success;
}

int8_t LinkedList_InsertAtTail(LinkedList_t* handle, DATA_TYPE data)
{
	int8_t success = -1;
	if (handle->length == 0)
	{
		LinkedList_InsertFirstNode(handle, data);
	}
	else
	{
		struct Node* newTail = LinkedList_CreateNode(data);
		if (newTail != NULL)
		{
			handle->tail->next = newTail;
			handle->tail = newTail;
			handle->length++;
			success = 0;
		}
	}
	return success;
}

int8_t LinkedList_InsertAtIndex(LinkedList_t* handle, DATA_TYPE data, uint32_t index)
{
	int8_t success = -1;
	if (index <= handle->length)
	{
		if (index == 0)
		{
			success = LinkedList_InsertAtHead(handle, data);
		}
		else if (index == handle->length)
		{
			success = LinkedList_InsertAtTail(handle, data);
		}
		else
		{
			struct Node* newNode = LinkedList_CreateNode(data);
			if (newNode != NULL)
			{
				struct Node* iterator = handle->head;
				for (size_t i = 0; i < handle->length; i++)
				{
					if (i == index - 1)
					{
						newNode->next = iterator->next;
						iterator->next = newNode;
						handle->length++;
						success = 0;
						break;
					}
					iterator = iterator->next;
				}
			}
		}
		
	}
	return success;
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
