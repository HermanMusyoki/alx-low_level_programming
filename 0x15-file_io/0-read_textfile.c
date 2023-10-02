#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads a text file and prints
 * it to the POSIX standard output
 *
 * @filename: the text file to read and print
 * @letters: number of letters from text file to read and print
 *
 * Return: actual numbers of letters or 0 (fail, filanme == NULL)
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fd;
	ssize_t wr;
	ssize_t text;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	text = read(fd, buffer, letters);
	wr = write(STDOUT_FILENO, buffer, text);

	free(buffer);
	close(fd);
	return (wr);
}
