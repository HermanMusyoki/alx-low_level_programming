#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - a function that adds a new node at the
 * beginning os a list_t list
 *
 * @head: pointer to a pointer to the list
 * @str: dublicate new string in the node
 *
 * Return: address of the new element and NULL (fail)
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_element;
	unsigned int len = 0;

	while (str[len])
		len++;

	new_element = malloc(sizeof(list_t));

	if (!new_element)
		return (NULL);
	new_element->str = strdup(str);
	new_element->len = len;
	new_element->next = (*head);
	(*head) = new_element;

	return (*head);
}

