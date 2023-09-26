#include "lists.h"

/**
 * find_listint_loop - a function that finds the loop in a linked list
 *
 * @head: pointer to the linked list to find the loop
 *
 * Return: the address of the node where the loop starts or
 * NULL otherwise(no loop)
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *firstNode = head;
	listint_t *secondNode = head;

	if (!head)
		return (NULL);

	while (firstNode && secondNode && secondNode->next)
	{
		secondNode = secondNode->next->next;
		firstNode = firstNode->next;
		if (secondNode == firstNode)
		{
			firstNode = head;
			while (firstNode != secondNode)
			{
				firstNode = firstNode->next;
				secondNode = secondNode->next;
			}
			return (secondNode);
		}
	}

	return (NULL);
}
