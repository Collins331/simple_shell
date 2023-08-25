#include "simple.h"

/**
* main - the entry point of the shell program
* @ac: argument count
* @av: the array of arguments
* @environ: the global variable
* Return:0 when program runs successfully, 1 on error
*/

int main(int ac, char **av, char **environ)
{
	char *input = NULL;
	char **token;
	char *delim = " \t\n";
	char *env;
	(void)ac;

	token = find_path(environ);

	signal(SIGINT, SIG_IGN);

	while (1)
	{
		input = get_line();

		av = tokenize(input, delim);

		env = av_path(av, token);

		if (env == NULL)
		{
			use_execve(av);
		}
		free(av);

		free(input);

		free(env);
	}
	return (0);
}
