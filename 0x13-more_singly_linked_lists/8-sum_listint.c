#include "lists.h"

/**
 * sum_listint - a function that calculates the sum of all the
 * data(n) of a listint_t linked list
 *
 * @head: pointer to the linked list to find sum
 *
 * Return: sum of data or 0 otherwise
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *newNode = head;

	while (newNode)
	{
		sum += newNode->n;
		newNode = newNode->next;
	}

	return (sum);
}
