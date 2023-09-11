#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dog.h"

/**
 * _strlength -  finds the string length
 * @str: string str to be checked
 *
 * Return: string length
 */

int _strlength(char *str)
{
	int length;

	length = 0;

	while (str[length] != '\0')
		length++;
	return (length);
}
/**
 * _strcpy - copies string from src to dest pointer
 *
 * @src: pointer to source string
 * @dest: pointer to destination buffer string to be copied
 *
 * Return: dest pointer
 */
char *_strcpy(char *dest, char *src)
{
	int m, strlen;

	strlen = 0;

	while (src[strlen] != '\0')
	{
		strlen++;
	}

	m = 0;

	while (m < strlen)
	{
		dest[m] = src[m];
		m++;
	}
	dest[m] = '\0';
	return (dest);
}

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
	int name_len, owner_len;

	name_len = _strlength(name);
	owner_len = _strlength(owner);

	newDog = malloc(sizeof(dog_t));
	if (newDog == NULL)
	{
		return (NULL);
	}

	newDog->name = malloc(sizeof(char) * (name_len + 1));
	if (newDog->name == NULL)
	{
		free(newDog);
		return (NULL);
	}
	newDog->owner = malloc(sizeof(char) * (owner_len + 1));
	if (newDog->owner == NULL)
	{
		free(newDog);
		free(newDog->name);
		return (NULL);
	}

	newDog->age = age;
	_strcpy(newDog->name, name);
	_strcpy(newDog->owner, owner);


	return (newDog);
}

