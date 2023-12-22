#include "hash_tables.h"

/**
 * hash_djb2 - a function to implements hash of  djb2 string
 * @str: parameter to the hash string to compute
 *
 * Return:  the hash string value
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

