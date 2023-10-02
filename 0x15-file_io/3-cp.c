#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *readable_buffer(char *filename);
void close_textfile(int fd);

/**
 * readable_buffer - sets 1024 bytes at a time from file_from
 * for a buffer
 *
 * @filename: the file to store the buffer
 *
 * Return: pointer to the created filename
 */

char *readable_buffer(char *filename)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buffer);
}

/**
 * close_textfile - close the text file
 *
 * @fd: the file description to close
 */

void close_textfile(int fd)
{
	int close_file;

	close_file = close(fd);

	if (close_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - a function that copies the content of a file to another file
 *
 * @argc: the numbers of arguments passed to the function
 * @argv: array of pointers to the arguments passed
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int src, dest, read_file, wr;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = readable_buffer(argv[2]);
	src = open(argv[1], O_RDONLY);
	read_file = read(src, buffer, 1024);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (src == -1 || read_file == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wr = write(dest, buffer, read_file);
		if (dest == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_file = read(src, buffer, 1024);
		dest = open(argv[2], O_WRONLY | O_APPEND);
	} while (read_file > 0);

	free(buffer);
	close_textfile(src);
	close_textfile(dest);

	return (0);

}

