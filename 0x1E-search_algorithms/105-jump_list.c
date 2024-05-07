#include "search_algos.h"

/**
 * jump_list - Function that searches for a value in a sorted
 * singly linked list of integers using jump search.
 * @list: Address to the head of the linked list to search.
 * @size: Nodes in the list.
 * @value: The value to search for in the array
 *
 * Return:  Null (value is not present or the head of the list is NULL) or
 *         address to the first node of the value
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, step_size;
	listint_t *node, *jump;

	if (list == NULL || size == 0)
		return (NULL);

	step = 0;

	step_size = sqrt(size);

	for (node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		node = jump;

		for (step += step_size; jump->index < step; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}

		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
