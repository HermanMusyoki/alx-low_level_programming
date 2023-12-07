#include "lists.h"

/**
 * get_dnodeint_at_index - a function that returns the nth node in
 * the dlistint_t list
 * @head: pointer to the beggining of the linked list
 * @index: the position of the node to be printed
 * Return: nth node in the list or NULL (fail)
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int m;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	m = 0;

	while (head != NULL)
	{
		if (m == index)
			break;
		head = head->next;
		m++;
	}

	return (head);
}
