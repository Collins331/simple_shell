#include "simple.h"
/**
 * main - entry point to simple shell
 * @ac: the argument count
 * @av: the arguments
 * @environ: the specified environment
 * Return: 0(success)
 */

int main(int ac, char **av, char **environ)
{
	char *str = NULL;
	char *delim = " \t\n";

	while (1)
	{
		prompt();
		str = get_line();

		av = str_tok(str, delim);

		exe_cve(av);
		free(av);
		free(str);

	}
	return (0);
}
