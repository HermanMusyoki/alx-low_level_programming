#include "lists.h"

/**
 * add_dnodeint - a function that adds a new node at the start of
 * dlistint_t list
 * @head: a double pointer to the beggining of the linked list
 * @n: number of nodes to add to the dlistint_t list
 * Return: pointer to the new element or NULL (fail)
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *h;

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}

	new->next = h;

	if (h != NULL)
		h->prev = new;

	*head = new;

	return (new);
}
