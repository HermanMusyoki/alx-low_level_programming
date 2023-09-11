#include <stdio.h>
#include <stdlib.h>

#include "dog.h"

/**
 * free_dog - a function that frees dog_t structure memory
 * @d: Pointer to the dog_t structure
 *
 * Description:the function frees the memory allocated for a dog_t structure
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}

