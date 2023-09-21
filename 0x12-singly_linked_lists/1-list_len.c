#include <stdlib.h>
#include "lists.h"

/**
 * list_len - a function to return the number of elements
 * in a linked list_t list
 *
 * @h: pointer to the list
 *
 * Return: numbers of elements in list
 */

size_t list_len(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}
	return (num);
}

