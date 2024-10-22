#include <stdlib.h>
#include "double_linked_list.h"

DoubleLinkedList_t* DoubleLinkedList_Create() 
{
	DoubleLinkedList_t* handle = (DoubleLinkedList_t*)malloc(sizeof(DoubleLinkedList_t));
	if (handle != NULL)
	{
		handle->head = NULL;
		handle->tail = NULL;
		handle->length = 0;
	}
	return handle;
}

void DoubleLinkedList_Destroy(DoubleLinkedList_t* handle)
{
	for (uint32_t i = 0; i < handle->length; i++)
	{
		struct Node* node = handle->head->next;
		free(handle->head);
		handle->head = node;
	}
	free(handle);
}

void DoubleLinkedList_Display(DoubleLinkedList_t* handle)
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

DATA_TYPE DoubleLinkedList_Max(DoubleLinkedList_t* handle)
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

struct Node* DoubleLinkedList_CreateNode(DATA_TYPE data) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	return newNode;
}

void DoubleLinkedList_InsertFirstNode(DoubleLinkedList_t* handle, DATA_TYPE data) 
{
	struct Node* newNode = DoubleLinkedList_CreateNode(data);
	if (newNode != NULL)
	{
		handle->head = newNode;
		handle->tail = handle->head;
		handle->length = 1;
	}
}

void DoubleLinkedList_DeleteLastNode(DoubleLinkedList_t* handle)
{
	free(handle->head);
	handle->head = NULL;
	handle->tail = NULL;
	handle->length = 0;
}

int8_t DoubleLinkedList_InsertAtHead(DoubleLinkedList_t* handle, DATA_TYPE data)
{
	int8_t success = -1;
	if (handle->length == 0)
	{
		DoubleLinkedList_InsertFirstNode(handle, data);
	}
	else
	{
		struct Node* newHead = DoubleLinkedList_CreateNode(data);
		if (newHead != NULL)
		{
			newHead->next = handle->head;
			handle->head->prev = newHead;
			handle->head = newHead;
			handle->length++;
			success = 0;
		}
	}
	return success;
}

int8_t DoubleLinkedList_InsertAtTail(DoubleLinkedList_t* handle, DATA_TYPE data)
{
	int8_t success = -1;
	if (handle->length == 0)
	{
		DoubleLinkedList_InsertFirstNode(handle, data);
	}
	else
	{
		struct Node* newTail = DoubleLinkedList_CreateNode(data);
		if (newTail != NULL)
		{
			handle->tail->next = newTail;
			newTail->prev = handle->tail;
			handle->tail = newTail;
			handle->length++;
			success = 0;
		}
	}
	return success;
}

int8_t DoubleLinkedList_InsertAtIndex(DoubleLinkedList_t* handle, DATA_TYPE data, uint32_t index)
{
	int8_t success = -1;
	if (index <= handle->length)
	{
		if (index == 0)
		{
			success = DoubleLinkedList_InsertAtHead(handle, data);
		}
		else if (index == handle->length)
		{
			success = DoubleLinkedList_InsertAtTail(handle, data);
		}
		else
		{
			struct Node* newNode = DoubleLinkedList_CreateNode(data);
			if (newNode != NULL)
			{
				/* index closer to head */
				if (handle->length - (index + 1) > handle->length / 2)
				{
					struct Node* iterator = handle->head;
					for (uint32_t i = 0; i < handle->length; i++)
					{
						if (i == index - 1)
						{
							newNode->next = iterator->next;
							newNode->prev = iterator;
							iterator->next->prev = newNode;
							iterator->next = newNode;
							handle->length++;
							success = 0;
							break;
						}
						iterator = iterator->next;
					}
				}
				else /* index closer to tail */
				{
					struct Node* iterator = handle->tail;
					for (uint32_t i = handle->length; i > 0; i--)
					{
						if (i == index + 1)
						{
							newNode->prev = iterator->prev;
							iterator->prev->next = newNode;
							iterator->prev = newNode;
							newNode->next = iterator;
							handle->length++;
							success = 0;
							break;
						}
						iterator = iterator->prev;
					}
				}
			}
		}
	}
	return success;
}

int8_t DoubleLinkedList_DeleteAtHead(DoubleLinkedList_t* handle)
{
	int8_t success = -1;
	if (handle->length > 0)
	{
		if (handle->length == 1)
		{
			DoubleLinkedList_DeleteLastNode(handle);
		}
		else
		{
			struct Node* newHead = handle->head->next;
			free(handle->head);
			handle->head = newHead;
			handle->length--;
			success = 0;
		}
	}

	return success;
}

int8_t DoubleLinkedList_DeleteAtTail(DoubleLinkedList_t* handle)
{
	int8_t success = -1;
	if (handle->length > 0)
	{
		if (handle->length == 1)
		{
			DoubleLinkedList_DeleteLastNode(handle);
		}
		else
		{
			struct Node* newTail = handle->tail->prev;
			free(handle->tail);
			newTail->next = NULL;
			handle->tail = newTail;
			handle->length--;
			success = 0;
		}
	}
	return success;
}

int8_t DoubleLinkedList_DeleteAtIndex(DoubleLinkedList_t* handle, uint32_t index)
{
	int8_t success = -1;
	if (handle->length > 0)
	{
		if (index <= handle->length)
		{
			if (index == 0)
			{
				success = DoubleLinkedList_DeleteAtHead(handle);
			}
			else if (index == handle->length)
			{
				success = DoubleLinkedList_DeleteAtTail(handle);
			}
			else
			{
				struct Node* iterator = handle->head;
				for (uint32_t i = 0; i < index - 1; i++)
				{
					iterator = iterator->next;
				}
				struct Node* linkNode = iterator->next->next;
				free(iterator->next);
				iterator->next = linkNode;
				handle->length--;
				success = 0;
			}
		}
	}
	return success;
}

void DoubleLinkedList_Reverse(DoubleLinkedList_t* handle)
{
	struct Node* iterator = handle->head;
	while (1)
	{
		if (iterator->next == NULL)
		{
			iterator->next = iterator->prev;
			iterator->prev = NULL;
			handle->tail = handle->head;
			handle->head = iterator;
			break;
		}
		struct Node* swapNode = iterator->next;
		iterator->next = iterator->prev;
		iterator->prev = swapNode;
		iterator = swapNode;
	}
}

DoubleLinkedList_t* DoubleLinkedList_Concat(DoubleLinkedList_t* first, DoubleLinkedList_t* second) 
{
	if (first->length == 0)
	{
		return second;
	}
	else if (second->length == 0)
	{
		return first;
	}
	else
	{
		first->tail->next = second->head;
		first->tail = second->tail;
		first->length += second->length;
		free(second); /* Delete the handle of second list */
		return first;
	}
}

int8_t DoubleLinkedList_DetectLoop(DoubleLinkedList_t* handle)
{
	struct Node* slow = handle->head;
	struct Node* fast = handle->head;
	if (handle->length > 1)
	{
		while (slow != NULL && fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				return 1;
			}
		}
	}
	return 0;
}

struct Node* DoubleLinkedList_Search(DoubleLinkedList_t* handle, DATA_TYPE data)
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
