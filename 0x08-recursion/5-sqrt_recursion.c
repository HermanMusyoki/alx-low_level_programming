#include "main.h"

/**
 * _sqrt_recursion - finds the natural square root of a number
 *
 * @n: given number to find sqrt
 *
 * Return: sqrt of the number
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (exact_sqrt(n, 0));

}
/**
 * exact_sqrt - finds the number's natural square root
 * @n: number to find sqrt
 * @m: number to loop through
 *
 * Return: square root of the number
 */

int exact_sqrt(int n, int m)
{
	if (m * m > n)
		return (-1);
	else if (m * m == n)
		return (m);
	return (exact_sqrt(n, m + 1));
}
