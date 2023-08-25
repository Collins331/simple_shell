#include "simple.h"

/**
 * len - checks for '=' character
 * @str: char type
 * Return: always string
 */
char *len(char *str)
{
	int i;

	for (i = 0; str[i] != '='; i++)
		;
	return (str + i + 1);
}

/**
 * comp - compare two strings
 * @var: the first string of char
 * @dir: the string of char
 * Return: 1 or 0
 */
int comp(char *var, char *dir)
{
	int i;

	for (i = 0; dir[i] != '\0'; i++)
	{
		if (dir[i] != var[i])
		{
			return (0);
		}
	}
	return (1);
}
/**
 * get_env - gets the global environ path
 * @environ: the global variable
 * @dir: the directory name
 * Return: a string of chars or NULL
 */
char *get_env(char **environ, char *dir)
{
	int k, j;
	char *var, *dest;

	for (j = 0; environ[j]; j++)
	{
		var = malloc(1024);

		for (k = 0; environ[j][k] != '='; k++)
		{
			var[k] = environ[j][k];
		}
		if (comp(var, dir))
		{
			dest = len(environ[j]);
			free(var);
			return (dest);
		}
		free(var);
	}
	return (NULL);
}
