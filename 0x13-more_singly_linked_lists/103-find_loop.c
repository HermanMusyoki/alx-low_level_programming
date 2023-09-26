#include "lists.h"

/**
 * find_listint_loop - a function that finds the loop in a linked list
 *
 * @head: pointer to the linked list to find the loop
 *
 * Return: the address of the node where the loop starts or
 * NULL otherwise(no loop)
 */
listint_t *find_listint_loop(listint_t *head)
{
	size_t length = 0;
	int m;
	listint_t *new;

	if (!h || *h)
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
