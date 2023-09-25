#include "lists.h"

/**
 * get_nodeint_at_index - a function that returns the nth node of a
 * listint_t linked list
 *
 * @head: pointer to the linked list to find nth node
 * @index: the index of the node from 0
 *
 * Return: nth node of listint_t and NULL (fail)
 *
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int m = 0;
	listint_t *newNode = head;

	while (newNode && m < index)
	{
		newNode = newNode->next;
		m++;
	}

	return (newNode ? newNode : NULL);
}
