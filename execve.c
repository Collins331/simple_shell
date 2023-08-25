#include "simple.h"

/**
 * use_execve- function that executes a command
 * @array : pointer to an array to be executed
 **/

int use_execve(char **array)
{
	int state;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Error: ");
	}
	else if (pid == 0)
	{
		if (execve(array[0], array, NULL) == -1)
		{
			perror(array[0]);
			return (1);
		}
	}
	else
	{
		wait(&state);
	}
	return (0);
}
