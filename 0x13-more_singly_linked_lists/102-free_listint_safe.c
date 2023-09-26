#include "lists.h"

/**
 * free_listint_safe - a function that frees a lsistint_t list
 *
 * @h: double pointer to the linked list to be freed
 *
 * Return: the size of the freed list and set head to NULL
 */
size_t free_listint_safe(listint_t **h)
{
	size_t length = 0;
	int m;
	listint_t *new;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		m = *h - (*h)->next;
		if (m > 0)
		{
			new = (*h)->next;
			free(*h);
			*h = new;
			length++;
		}
		else
		{
			free(*h);
			*h = NULL;
			length++;
			break;
		}
	}
	*h = NULL;

	return (length);
}
