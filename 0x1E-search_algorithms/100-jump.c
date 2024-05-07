#include "search_algos.h"
/**
  * jump_search - Function that searches for a value in a sorted array
  *               of integers using jump search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array to be searched
  * @value: The value to search for from the array
  *
  * Return: -1 (value is not present or NULL array) or first value index
  */

int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);

	for (i = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);

		i = jump;

		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jump);

	jump = jump < size - 1 ? jump : size - 1;

	for (; i < jump && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
