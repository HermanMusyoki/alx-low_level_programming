#include "lists.h"

/**
 * dlistint_len - a function that returns the length of dlidtint_t list
 * @h: pointer to the beggining of the linked list
 *
 * Return: numbers of elements in dlistint_t list
 */

size_t dlistint_len(const dlistint_t *h)
{
	int counter;

	counter = 0;

	if (h == NULL)
		return (counter);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		counter++;
		h = h->next;
	}


	return (counter);
}
