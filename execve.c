#include "simple.h"
/**
 * exe_cve - executes the argument passed
 * @av: a pointer to the argument to execute
 * Return: Doesn't return success else -1 (error)
 */

int exe_cve(char **av)
{
	int state;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("ERROR");
	}
	else if (pid == 0)
	{
		if (execve(av[0], av, environ) == -1)
		{
			perror(av[0]);
			return (-1);
		}
	}
	else
	{
		wait(&state);
	}
	return (0);
}
