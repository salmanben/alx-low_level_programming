#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read a file and print it to the POSIX stdout
 * @filename: the name of file
 * @letters: size of reading/written letters
 * Return: The actual num of letters it could read and print
 * or 0 if an error occured
 */

ssize_t read_textfile(const char *filename, size_t letters)

{
	int rd;
	int i;
	int reading;
	char *buf;

	if (filename == NULL)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);
	rd = open(filename, O_RDONLY);
	if (rd == -1)
	{
		free(buf);
		return (0);
	}

	reading = read(rd, buf, letters);
	if (reading == -1)
	{
		close(rd);
		free(buf);
		return (0);
	}

	for (i = 0; i < reading; i++)
	{
		if (write(STDOUT_FILENO, &buf[i], 1) == -1)
		{
			close(rd);
			free(buf);
			return (0);
		}

	}
	close(rd);
	free(buf);
	return (reading);
}
