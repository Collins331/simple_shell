#include "main.h"
/**
 * _tokenize - get tokens from strings
 * @args: input
 * @cmd: input
 */

void _tokenize(char *args[], char *cmd)
{
	char *token = strtok(cmd, " ");
	int i = 0;

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
}
