#include "lists.h"

/**
 * add_nodeint_end - a function that adds  new node at the
 * end of a listint_t list
 *
 * @head: pointer to pointer to the last node in the list
 * @n: node to add at the end of the list
 *
 * Return: the address of the new node and NULL (fail)
 *
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *endNode;
	listint_t *tempNode = *head;

	endNode = malloc(sizeof(listint_t));

	if (!endNode)
		return (NULL);

	endNode->n = n;
	endNode->next = NULL;

	if (*head == NULL)
	{
		*head = endNode;
		return (endNode);
	}

	while (tempNode->next)
		tempNode = tempNode->next;

	tempNode->next = endNode;

	return (endNode);
}
