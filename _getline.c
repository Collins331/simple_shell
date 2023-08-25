#include "main.h"

/**
 * _getline - my own getline
 * @lineptr: input
 * @n: input
 * @stream: input
 * Return: pos
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0, n_size;
	int c;
	char *n_buff;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = IBS; /*INITIAL_BUFFER_SIZE*/
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	c = fgetc(stream);
	while (c)
	{
		if (pos >= *n - 1)
		{
			n_size = *n * BGF; /*BUFFER_GROWING_FACTORY*/
			n_buff = (char *)realloc(*lineptr, n_size);
			if (n_buff == NULL)
				return (-1);
			*lineptr = n_buff;
			*n = n_size;
		}
		(*lineptr)[pos++] = c;
		if (c == '\n')
			break;
	}
	if (pos == 0 && c == EOF)
		return (-1);
	(*lineptr)[pos] = '\0';
	return (pos);
}
