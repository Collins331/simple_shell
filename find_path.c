#include "simple.h"
/**
 * find_path - finds the path
 * @environ: the global variable
 * Return: the path
 */
char **find_path(char **environ)
{
	char *getpath;
	char **token;
	char *delim = ":";

	getpath = get_env(environ, "PATH");
	token = tokenize(getpath, delim);

	return (token);
}
