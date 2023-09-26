#include "lists.h"

/**
 * delete_nodeint_at_index - a function that deletes the node at index
 * of a listint_t linked list
 *
 * @head: pointer to the linked list to delete a node from
 * @index: is the index of the node to be deleted
 *
 * Return: 1 (success) or -1 (fail)
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int m = 0;
	listint_t *tempNode = *head;
	listint_t *indexedNode = NULL;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(tempNode);
		return (1);
	}

	while (m < index - 1)
	{
		if (!tempNode || !(tempNode->next))
			return (-1);
		tempNode = tempNode->next;
		m++;
	}

	indexedNode = tempNode->next;
	tempNode->next = indexedNode->next;
	free(indexedNode);

	return (1);
}

