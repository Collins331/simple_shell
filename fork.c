#include "main.h"

/**
 * _fork_and_exe - fork and execute
 * @args: input
 * @argv: input
 * @cmd: input
 * Return: 0 or -1 even fork Failed
 */

int _fork_and_exe(char *args[], char *argv[], char *cmd)
{
	pid_t pid = fork();
	int status;

	if (pid < 0)
	{
		printf("Fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		args[0] = cmd;
		args[1] = NULL;
		execve(cmd, args, NULL);
		printf("%s: No such file or directory\n", argv[0]);
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
	return (0);
}
