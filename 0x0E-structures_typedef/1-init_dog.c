#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - Initializes a struct dog with the provided values
 * @d: Pointer to the struct dog to be initialized
 * @name: Pointer to the dog's name
 * @age: Age of the dog
 * @owner: Pointer to the owner's name
 *
 * Description:The init_dog function initializes the members of
 * a struct dog with the provided values.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

