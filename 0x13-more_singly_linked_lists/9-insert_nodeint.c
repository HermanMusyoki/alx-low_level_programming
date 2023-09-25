#include "lists.h"

/**
 * insert_nodeint_at_index - a function that inserts a new node
 * at a given position
 *
 * @head: pointer to the linked list to insert the new node
 * @idx: index of the list where to add the new node
 * @n: data to be inserted in the new node
 *
 * Return: the address to the new node or NULL (fail)
 *
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newNode;
	listint_t *tempNode = *head;
	unsigned int m;

	newNode = malloc(sizeof(listint_t));

	if (!newNode || !head)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	for (m = 0 ; tempNode && m < idx ; m++)
	{
		if (m == idx - 1)
		{
			newNode->next = tempNode->next;
			tempNode->next = newNode;
			return (newNode);
		}
		else
			tempNode = tempNode->next;
	}

	return (NULL);
}
