#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a structure for  a dog
 *
 * @name: name of the dog
 * @age: the number of years of the dog
 * @owner: the current owner of the dog
 *
 * Description: the structure stores information about a dog
 * which consists of its name, age, and owner
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};
/**
 * dog_t -typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);


#endif /* DOG_H */

