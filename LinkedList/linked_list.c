#include <stdlib.h>
#include "linked_list.h"

LinkedList_t* LinkedList_Create() 
{
	LinkedList_t* handle = (LinkedList_t*)malloc(sizeof(LinkedList_t));
	if (handle != NULL)
	{
		handle->head = NULL;
		handle->length = 0;
	}
	return handle;
}

void LinkedList_Destroy(LinkedList_t* handle)
{
	for (uint32_t i = 0; i < handle->length; i++)
	{
		struct LL_Node* node = handle->head->next;
		free(handle->head);
		handle->head = node;
	}
	free(handle);
}

void LinkedList_Display(LinkedList_t* handle)
{
	printf("-----\n");
	struct LL_Node* node = handle->head;
	for (int i = 0; i < handle->length; i++)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("+++++\n");
}

LL_DATA_TYPE LinkedList_Max(LinkedList_t* handle)
{
	struct LL_Node* node = handle->head;
	LL_DATA_TYPE max = handle->head->data;
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

struct LL_Node* LinkedList_CreateNode(LL_DATA_TYPE data) 
{
	struct LL_Node* newNode = (struct LL_Node*)malloc(sizeof(struct LL_Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}

int8_t LinkedList_InsertFirstNode(LinkedList_t* handle, LL_DATA_TYPE data)
{
	int8_t success = -1;
	struct LL_Node* newNode = LinkedList_CreateNode(data);
	if (newNode != NULL)
	{
		handle->head = newNode;
		handle->length = 1;
		success = 0;
	}
	return success;
}

int8_t LinkedList_DeleteLastNode(LinkedList_t* handle)
{
	int8_t success = -1;
	if (handle != NULL)
	{
		free(handle->head);
		handle->head = NULL;
		handle->length = 0;
		success = 0;
	}
	return success;
}

int8_t LinkedList_InsertAtHead(LinkedList_t* handle, LL_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle->length == 0)
	{
		success = LinkedList_InsertFirstNode(handle, data);
	}
	else
	{
		struct LL_Node* newHead = LinkedList_CreateNode(data);
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

int8_t LinkedList_InsertAtTail(LinkedList_t* handle, LL_DATA_TYPE data)
{
	int8_t success = -1;
	if (handle->length == 0)
	{
		success = LinkedList_InsertFirstNode(handle, data);
	}
	else
	{
		struct LL_Node* newNode = LinkedList_CreateNode(data);
		struct LL_Node* iterator = handle->head;
		if (newNode != NULL)
		{
			while (1)
			{
				if (iterator->next == NULL)
				{
					break;
				}
				iterator = iterator->next;
			}
			iterator->next = newNode;
			handle->length++;
			success = 0;
		}
	}
	return success;
}

int8_t LinkedList_InsertAtIndex(LinkedList_t* handle, LL_DATA_TYPE data, uint32_t index)
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
			struct LL_Node* newNode = LinkedList_CreateNode(data);
			if (newNode != NULL)
			{
				struct LL_Node* iterator = handle->head;
				for (uint32_t i = 0; i < handle->length; i++)
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

int8_t LinkedList_DeleteAtHead(LinkedList_t* handle)
{
	int8_t success = -1;
	if (handle->length > 0)
	{
		if (handle->length == 1)
		{
			success = LinkedList_DeleteLastNode(handle);
		}
		else
		{
			struct LL_Node* newHead = handle->head->next;
			free(handle->head);
			handle->head = newHead;
			handle->length--;
			success = 0;
		}
	}

	return success;
}

int8_t LinkedList_DeleteAtTail(LinkedList_t* handle)
{
	int8_t success = -1;
	if (handle->length > 0)
	{
		if (handle->length == 1)
		{
			success = LinkedList_DeleteLastNode(handle);
		}
		else
		{
			struct LL_Node* iterator = handle->head;
			while (1)
			{
				if(iterator->next->next == NULL)
				{
					break;
				}
				iterator = iterator->next;
			}
			free(iterator->next);
			iterator->next = NULL;
			handle->length--;
			success = 0;
		}
	}
	return success;
}

int8_t LinkedList_DeleteAtIndex(LinkedList_t* handle, uint32_t index)
{
	int8_t success = -1;
	if (handle->length > 0)
	{
		if (index <= handle->length)
		{
			if (index == 0)
			{
				success = LinkedList_DeleteAtHead(handle);
			}
			else if (index == handle->length)
			{
				success = LinkedList_DeleteAtTail(handle);
			}
			else
			{
				struct LL_Node* iterator = handle->head;
				for (uint32_t i = 0; i < index - 1; i++)
				{
					iterator = iterator->next;
				}
				struct LL_Node* linkNode = iterator->next->next;
				free(iterator->next);
				iterator->next = linkNode;
				handle->length--;
				success = 0;
			}
		}
	}
	return success;
}

LinkedList_t* LinkedList_Reverse(LinkedList_t* handle)
{
	LinkedList_t* reversed = LinkedList_Create();
	if (reversed != NULL)
	{
		struct LL_Node* iterator = handle->head;
		LinkedList_InsertAtHead(reversed, iterator->data);
		for (uint32_t i = 0; i < handle->length - 1; i++)
		{
			iterator = iterator->next;
			LinkedList_InsertAtHead(reversed, iterator->data);
		}
		LinkedList_Destroy(handle);
	}
	return reversed;
}

void LinkedList_Reverse_SlidingPointers(LinkedList_t* handle)
{
	struct LL_Node* previousNode = NULL;
	struct LL_Node* currentNode = handle->head;
	struct LL_Node* nextNode = NULL;

	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}
	handle->head = previousNode;
}

LinkedList_t* LinkedList_Concat(LinkedList_t* first, LinkedList_t* second) 
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
		struct LL_Node* iterator = first->head;
		while (1)
		{
			if (iterator->next == NULL)
			{
				break;
			}
			iterator = iterator->next;
		}
		iterator->next = second->head;
		first->length += second->length;
		free(second); /* Delete the handle of second list */
		return first;
	}
}

int8_t LinkedList_DetectLoop(LinkedList_t* handle)
{
	struct LL_Node* slow = handle->head;
	struct LL_Node* fast = handle->head;
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

struct LL_Node* LinkedList_Search(LinkedList_t* handle, LL_DATA_TYPE data)
{
	struct LL_Node* returnNode = NULL;
	struct LL_Node* node = handle->head;
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
