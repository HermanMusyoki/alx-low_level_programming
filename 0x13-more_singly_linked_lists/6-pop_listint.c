#include "lists.h"

/**
 * pop_listint - a function that deletes the head node of a
 * listint_t linked list
 *
 * @head: pointer to pointer of a linked list to be deleted
 *
 * Return: data of the head node and 0 if empty
 *
 */

int pop_listint(listint_t **head)
{
	listint_t *headNode;
	int number;

	if (!head || !*head)
		return (0);


	number = (*head)->n;
	headNode = (*head)->next;
	free(*head);
	*head = headNode;

	return (number);
}
