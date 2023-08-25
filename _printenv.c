#include "main.h"

/**
 * _printenv - print env
 * @cmd: input
 */

void _printenv(char *cmd)
{
	char **env = environ;

	if (strcmp(cmd, "env") == 0)
	{
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}
