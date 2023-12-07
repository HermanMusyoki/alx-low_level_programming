 #include "lists.h"
/**
 * insert_dnodeint_at_index - a function that inserts a new node at given point
 * @h: double pointer to the beggining of the linked list
 * @idx: the index position to insert the new node in the list
 * @n: number of nodes to be added
 * Return: pointer to the new node or NULL (fail)
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *head;
	unsigned int m;

	new = NULL;
	if (idx == 0)
		new = add_dnodeint(h, n);
	else
	{
		head = *h;
		m = 1;

		if (head != NULL)
			while (head->prev != NULL)
				head = head->prev;
		while (head != NULL)
		{
			if (m == idx)
			{
				if (head->next == NULL)
					new = add_dnodeint_end(h, n);
				else
				{
					new = malloc(sizeof(dlistint_t));
					if (new != NULL)
					{
						new->n = n;
						new->next = head->next;
						new->prev = head;
						head->next->prev = new;
						head->next = new;
					}
				}
				break;
			}
			head = head->next;
			m++;
		}
	}
	return (new);
}
