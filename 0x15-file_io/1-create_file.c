#include "main.h"

/**
 * create_file - a function that creates a text file
 *
 * @filename: the text file to be created
 * @text_content: pointer to the content to write in the text file
 *
 * Return: 1 (success) or -1 (fail)
 */

int create_file(const char *filename, char *text_content)
{
	int fd, wr, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0 ; text_content[length];)
			length++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(fd, text_content, length);

	if (fd == -1 || wr == -1)
		return (-1);

	close(fd);

	return (1);
}
