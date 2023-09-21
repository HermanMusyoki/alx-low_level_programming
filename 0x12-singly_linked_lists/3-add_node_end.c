#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - a function that adds a new node at
 * the end of a list_t list
 *
 * @head: pointer to pointer to the list
 * @str: string to be added to the new node
 *
 * Return: address to new node element and NULL (fail)
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *endNode;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;
	endNode = malloc(sizeof(list_t));
	if (!endNode)
		return (NULL);

	endNode->str = strdup(str);
	endNode->len = len;
	endNode->next = NULL;

	if (*head == NULL)
	{
		*head = endNode;
		return (endNode);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = endNode;

	return (endNode);
}
