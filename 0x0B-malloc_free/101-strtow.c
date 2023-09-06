#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strtow - a function that splits a string into two
 *
 * @str: the string to split
 *
 * Return: pointer to array of strings and NULL (fail)
 */

int count_words(char *str);

char **strtow(char *str)
{
	int num_words;
	char **words;
	int word_start;
	int word_end;
	int word_length;
	int word_count = 0;
	int i, j;

	if (str == NULL || *str == '\0' || count_words(str) == 0)
		return (NULL);

	num_words = count_words(str);
	words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	word_start = 0;
	word_end = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			word_start = i;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			word_end = i;

			word_length = word_end - word_start;
			words[word_count] = (char *)malloc((word_length + 1) * sizeof(char));

			if (words[word_count] == NULL)
			{
				for (j = 0; j < word_count; j++)
					free(words[j]);
				free(words);
				return (NULL);
			}
			strncpy(words[word_count], &str[word_start], word_length);
			words[word_count][word_length] = '\0';
			word_count++;
		}
	}
	words[word_count] = NULL;
	return (words);
}
/**
 * count_words - function that counts number of words in a string
 *
 * @str: the given string
 *
 * Return: words count
 */

int count_words(char *str)
{
	int count = 0;
	int in_word = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (str[i] == ' ')
		{
			in_word = 0;
		}
	}
	return (count);
}
