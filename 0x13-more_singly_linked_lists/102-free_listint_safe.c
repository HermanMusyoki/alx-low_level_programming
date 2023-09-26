#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

size_t looplists_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looplists_listint_len - the function counts unique nodes number in the
 * loop lists listint_t linked list
 *
 * @head: a pointer to the linked list to be counted
 *
 * Return: number of unique nodes or 0 otherwise
 */
size_t looplists_listint_len(const listint_t *head)
{
	const listint_t *firstNode, *secondNode;
	size_t number = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	firstNode = head->next;
	secondNode = (head->next)->next;

	while (secondNode)
	{
		if (firstNode == secondNode)
		{
			firstNode = head;
			while (firstNode != secondNode)
			{
				number++;
				firstNode = firstNode->next;
				secondNode = secondNode->next;
			}
			firstNode = firstNode->next;

			while (firstNode != secondNode)
			{
				number++;
				firstNode = firstNode->next;
			}
			return (number);
		}
		firstNode = firstNode->next;
		secondNode = (secondNode->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - a function that prints a listint_t linked list
 *
 * @head: pointer to the linked list to be printed
 *
 * Return: the number of nodes in the list or 98 (fail)
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t number, position = 0;

	number = looplists_listint_len(head);

	if (number == 0)
	{
		for (; head != NULL ; number++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (position = 0 ; position < number ; position++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("->[%p] %d\n", (void *)head, head->n);
	}
	return (number);
}
