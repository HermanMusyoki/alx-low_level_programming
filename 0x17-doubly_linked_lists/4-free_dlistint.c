#include "lists.h"
/**
 * free_dlistint - a function that frees the dlistint_t linked list
 * @head: pointer to the beggining of the linked list
 * Return: nothing
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
