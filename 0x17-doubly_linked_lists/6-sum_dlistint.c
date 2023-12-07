#include "lists.h"

/**
 * sum_dlistint - a function that sums all the data of a
 * dlistint_t linked list
 * @head: pointer to the beggining of the linked list
 * Return: sum or 0 (empty list)
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			sum += head->n;
			head = head->next;
		}
	}


	return (sum);
}
