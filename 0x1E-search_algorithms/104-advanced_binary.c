#include "search_algos.h"

/**
 * advanced_binary_recursive - Function that searches recursively
 * for a value in a sorted array of integers using binary search.
 * @array: Address to the first element of the [sub]array to search.
 * @left: The first index to search in the [sub]array
 * @right: The ending index of the [sub]array to search to be searched
 * @value: The value to search for in the array
 *
 * Return: -1 (value is not present) or the array value index
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");

	for (i = left; i < right; i++)

		printf("%d, ", array[i]);

	printf("%d\n", array[i]);

	i = left + (right - left) / 2;

	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);

	if (array[i] >= value)
		return (advanced_binary_recursive(array, left, i, value));

	return (advanced_binary_recursive(array, i + 1, right, value));
}

/**
 * advanced_binary - Function that searches for a value in a sorted array
 *                   of integers using advanced binary search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array to be searched
 * @value: The value to search for in the array
 *
 * Return: -1 (value is not present or NULL array) or
 * the first value index where the value
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}