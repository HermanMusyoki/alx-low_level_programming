#include "lists.h"

/**
 * reverse_listint - a function that reverses a listint_t
 * linked list
 *
 * @head: double pointer to the linked list to be reversed
 *
 * Return: an address to the fisrt node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prevNode = NULL;
	listint_t *nextNode = NULL;

	while (*head)
	{
		nextNode = (*head)->next;
		(*head)->next = prevNode;
		prevNode = *head;
		*head = nextNode;
	}

	*head = prevNode;

	return (*head);
}
