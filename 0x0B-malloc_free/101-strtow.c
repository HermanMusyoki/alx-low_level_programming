#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strtow - function that splits a string into words.
 *
 * @str: The input string to be split.
 *
 * Return: A pointer to argv and NULL (fail).
 */
char **strtow(char *str)
{
	int m, n, p = 0;
	int word_count = 0;
	char **words = NULL;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (m = 0; str[m] != '\0'; m++)
	{
		if (str[m] != ' ' && (m == 0 || str[m - 1] == ' '))
			word_count++;
	}
	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);
	for (m = 0; m <= word_count; m++)
		words[m] = NULL;
	for (m = 0; str[m] != '\0'; m++)
	{
		if (str[m] != ' ' && (m == 0 || str[m - 1] == ' '))
		{
			int word_length = 0;

			for (n = m; str[n] != ' ' && str[n] != '\0'; n++)
				word_length++;
			words[p] = malloc(sizeof(char) * (word_length + 1));
			if (words[p] == NULL)
			{
				for (n = 0; n < p; n++)
					free(words[n]);
				free(words);
				return (NULL);
			}
			for (n = 0; n < word_length; n++)
				words[p][n] = str[m + n];
			words[p][word_length] = '\0';
			p++;
		}
	}

	return (words);
}
