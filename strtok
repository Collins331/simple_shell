#include "simple.h"
/**
 * str_tok - extracts tokens from a string
 * @str: the string to tokenize
 * @delim: the deliminator
 * Return: a pointer to array of string
 */
char **str_tok(char *str, char *delim)
{
	int i = 0;
	char **token;

	token = malloc(sizeof(char *) * BUF_SIZE);

	if (token == NULL)
	{
		exit(-1);
	}

	token[i] = strtok(str, delim);
	i++;

	while (1)
	{
		token[i] = strtok(NULL, delim);

		if (token[i] == NULL)
			break;

		i++;
	}

	return (token);
}
