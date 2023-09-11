#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dog.h"

/**
 * new_dog - A function that creates a new dog and
 * copies name and owner
 *
 * @name: Pointer to the dog's name
 * @age: Age of the dog
 * @owner: Pointer to the owner's name
 *
 * Return: Pointer to the newly created dog_t and NULL (fail)
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog;
	char *nameCopy, *ownerCopy;

	newDog = malloc(sizeof(dog_t));
	if (newDog == NULL)
	{
		return (NULL);
	}

	nameCopy = strdup(name);
	ownerCopy = strdup(owner);

	if (nameCopy == NULL || ownerCopy == NULL)
	{
		free(newDog);
		free(nameCopy);
		free(ownerCopy);
		return (NULL);
	}
	newDog->name = nameCopy;
	newDog->age = age;
	newDog->owner = ownerCopy;

	return (newDog);
}

