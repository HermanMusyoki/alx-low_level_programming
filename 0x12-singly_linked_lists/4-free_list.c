#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees  a linked list
 *
 * @head: the list list_t to be freed from memory
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
