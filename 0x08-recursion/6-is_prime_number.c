#include "main.h"

/**
 * is_prime_number - checks if a number is a prime number
 *
 * @n: number to be checked
 *
 * Return: 1 (n is prime) and 0 otherwise
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_num(n, n - 1));
}
/**
 * prime_num - checks recursively if number is prime
 *
 * @n: number to be checked
 * @m: loop variable
 *
 * Return: 1 (prime number) and 0 otherwise
 *
 */
int prime_num(int n, int m)
{

	if (m == 1)
		return (1);
	else if (n % m == 0 && m > 0)
		return (0);
	return (prime_num(n, m - 1));
}
