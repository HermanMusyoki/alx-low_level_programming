#include "main.h"

/**
 * is_palindrome - checks if a string is palindrome
 *
 * @s: string to be checked
 *
 * Return: 1 (if palindrome) and 0 otherwise
 */

int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);
	return (string_is_palindrome(s, 0, strLength(s)));
}
/**
 * strLength - checks for string length
 *
 * @s: string to be checked
 *
 * Return: string length
 */

int strLength(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + strLength(s + 1));
}
/**
 * string_is_palindrome - checks recursively if the characters are palindrome
 *
 * @s: string to be checked
 * @m: loop variable
 * @length: length of the string
 *
 * Return: 1 (if palindrome) and 0 otherwise
 */
int string_is_palindrome(char *s, int m, int length)
{
	if (*(s + m) != *(s + length - 1))
		return (0);
	if (m >= length)
		return (1);
	return (string_is_palindrome(s, m + 1, length - 1));

}

