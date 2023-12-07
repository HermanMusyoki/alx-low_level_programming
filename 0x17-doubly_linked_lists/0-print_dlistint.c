#include "lists.h"

/**
 * print_dlistint - a function that outputs dlistint_t elements
 * @h: a pointer to the beggining of the linked list
 * Return: the numbers of nodes in the dlistint_t list
 */

size_t print_dlistint(const dlistint_t *h)
{
	int counter;

	counter = 0;

	if (h == NULL)
		return (counter);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		counter++;
		h = h->next;
	}


	return (counter);
}
