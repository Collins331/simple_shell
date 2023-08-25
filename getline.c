#include "simple.h"
/**
 * get_line - reads user input from stdin
 * Return: array of characters
 */

char *get_line(void)
{
	size_t n = 0;
	char *input = NULL;
	int val = 0;


	put_char('$');
	putchar(' ');
	if (getline(&input, &n, stdin) == -1)
	{
		free(input);
		exit(-1);
	}

	val = strlen(input);

	input[val - 1] = '\0';

	return (input);
}
