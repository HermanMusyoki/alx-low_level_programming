#include "hash_tables.h"
/**
 * hash_table_get - a function to get value associeted with key in
 * hash table
 * @ht: address to the hash table
 * @key: pointer to key to get value
 *
 * Return: value or Null (fail)
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t  *bucket;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	bucket = ht->array[index];

	while (bucket)
	{
		if (!strcmp(key, bucket->key))
			return (bucket->value);
		bucket = bucket->next;
	}
	return (NULL);
}
