#include "hash_tables.h"

/**
 * key_index - a function that finds index for key given
 * @key: parameter for hash key
 * @size: the array size of the hash table
 *
 * Return: index key with key/value pair 
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
