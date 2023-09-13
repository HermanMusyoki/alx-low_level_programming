#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - a function to add two integers
 * @a: first number
 * @b: second number
 *
 * Return: sum of a + b
 */
int op_add(int a, int b)
{
	int sum;

	sum = a + b;
	return (sum);
}
/**
 * op_sub - a function that subtructs two numbers
 *
 * @a: first number
 * @b: second number
 * Return: difference a - b
 */
int op_sub(int a, int b)
{
	int difference;

	difference = a - b;
	return (difference);
}
/**
 * op_mul - a function that find product of two numbers
 * @a: first number
 * @b: second number
 * Return: product a * b
 */
int op_mul(int a, int b)
{
	int product;

	product = a * b;
	return (product);
}
/**
 * op_div - a function that divides two numbers
 * @a: fisrt number
 * @b: second number
 * Return: division of a and b
 */
int op_div(int a, int b)
{
	int quotient;

	quotient = a / b;
	return (quotient);
}
/**
 * op_mod - a function that finds modulo of two numbers
 * @a: first number
 * @b: second number
 * Return: modulo of a and b
 */
int op_mod(int a, int b)
{
	int modulo;

	modulo = a % b;
	return (modulo);
}
