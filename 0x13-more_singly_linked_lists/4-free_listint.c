#include "lists.h"

/**
 * free_listint - a function that frees listint_t list
 *
 * @head: pointer to listint_t list to be freed
 *
 */
void free_listint(listint_t *head)
{
	listint_t *tempNode;

	while (head)
	{
		tempNode = head->next;
		free(head);
		head = tempNode;
	}
}
