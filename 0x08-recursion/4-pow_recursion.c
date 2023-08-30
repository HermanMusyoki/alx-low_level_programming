#include "main.h"

/**
 * _pow_recursion - function to find power of a number
 *
 * @x: the given number
 * @y: raised power to a given number
 *
 * Return: result of the number raised to given power
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));

}
