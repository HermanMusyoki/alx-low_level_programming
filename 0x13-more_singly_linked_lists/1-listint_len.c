#include "lists.h"

/**
 * listint_len - a function that returns the number of
 * elements in a linked listint_t list
 *
 * @h: the linked list to find its length
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t numNodes = 0;

	while (h)
	{
		numNodes++;
		h = h->next;
	}

	return (numNodes);
}
