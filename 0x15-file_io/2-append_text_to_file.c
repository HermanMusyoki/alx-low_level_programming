#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end
 * of a file
 *
 * @filename: pointer to the text file to append text
 * @text_content: a pointer to string to write in the file
 *
 * Return: 1 (success) or -1 (fail)
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int textfile, wr, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
		for (length = 0; text_content[length];)
			length++;

	textfile = open(filename, O_WRONLY | O_APPEND);
	wr = write(textfile, text_content, length);

	if (textfile == -1 || wr == -1)
		return (-1);

	close(textfile);

	return (1);
}
