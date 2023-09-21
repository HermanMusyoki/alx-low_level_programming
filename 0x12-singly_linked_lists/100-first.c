#include <stdio.h>

void allow_beat(void)__attribute__((constructor));

/**
 * allow_beat - a function that prints given statement before
 * the main function is executed
 */

void allow_beat(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
