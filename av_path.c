#include "simple.h"

/**
 * av_path - concatenates the argument passed
 * @av: the argument
 * @token: the added argument
 * Return: a string of char
 */

char *av_path(char **av, char **token)
{
	char *str, **cat;
	int i, j, k;
	struct stat state;

	for (i = 0; token[i]; i++)
	{
		str = malloc(100);
		strcat(str, token[i]);
		strcat(str, "/");
		strcat(str, av[0]);

		if (stat(str, &state) == 0)
		{
			for (k = 0; av[k] != NULL; k++)
				;
			cat = malloc(sizeof(char *) * (k + 1));
			cat[k] = NULL;
			cat[0] = strdup(str);

			for (j = 1; av[j]; j++)
			{
				cat[j] = strdup(av[j]);
			}
			use_execve(cat);

			return (str);
		}
		free(str);
	}
	return (NULL);
}
