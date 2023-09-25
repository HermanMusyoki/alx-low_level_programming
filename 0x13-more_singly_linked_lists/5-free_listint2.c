#include "lists.h"

/**
 * free_listint2 - a function that frees a listint_t list
 *
 * @head: pointer to pointer to the list to be freed
 *
 */
void free_listint2(listint_t **head)
{
	listint_t *tempNode;

	if (head == NULL)
		return;

	while (*head)
	{
		tempNode = (*head)->next;
		free(*head);
		*head = tempNode;
	}

	*head = NULL;
}
