#include "lists.h"

/**
 * add_nodeint - a function that adds a new node at the beginning
 * os a listint_t list.
 *
 * @head: the pointer to the first node in the linked list
 * @n: node to be added at the start of the list
 *
 * Return: the address of the new node and NULL otherwise
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *firstNode;

	firstNode = malloc(sizeof(listint_t));

	if (!firstNode)
		return (NULL);

	firstNode->n = n;
	firstNode->next = *head;
	*head = firstNode;

	return (firstNode);
}

