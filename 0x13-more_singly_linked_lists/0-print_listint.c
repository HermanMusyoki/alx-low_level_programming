#include "lists.h"

/**
 * print_listint - a fuction that prints all the elements of a
 * listint_t list
 *
 * @h: the linked list to be printed
 *
 * Return: number of nodes.
 */

size_t print_listint(const listint_t *h)
{
	size_t numNodes = 0;

	while (h)
	{
		printf("%d\n", h->n);
		numNodes++;
		h = h->next;
	}
	return (numNodes);
}
