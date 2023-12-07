#include "lists.h"

/**
 * delete_dnodeint_at_index - a function that deletes the node
 * at given index in the dlistint_t linked list
 * @head: double pointer to the beggining of the linked list
 * @index: position in the linked list to remove the node
 * Return: 1 (success) or -1 (fail)
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h1;
	dlistint_t *h2;
	unsigned int m;

	 h1 = *head;

	if (h1 != NULL)
		while (h1->prev != NULL)
			h1 = h1->prev;
	m = 0;
	while (h1 != NULL)
	{
		if (m == index)
		{
			if (m == 0)
			{
				*head = h1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				h2->next = h1->next;

				if (h1->next != NULL)
					h1->next->prev = h2;
			}
			free(h1);
			return (1);
		}

		h2 = h1;
		h1 = h1->next;
		m++;

	}

	return (-1);
}
