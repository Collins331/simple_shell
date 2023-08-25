#include "main.h"
/**
 * main - the main prog
 * @argc: input
 * @argv: input
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *cmd = NULL, *args[MCL];
	size_t cmd_size = 0;
	ssize_t cmd_len;
	pid_t pid;

	(void) argc;
	while (1)
	{
		_prompt();
		cmd_len = getline(&cmd, &cmd_size, stdin);
		if (cmd_len == -1)
		{
			printf("\n");
			break;
		}
		cmd[cmd_len - 1] = '\0';
		_ext(cmd);
		_printenv(cmd);
		_tokenize(args, cmd);
		pid = fork();
		if (pid < 0)
		{
			perror("Fork faild");
			exit(1);
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
		{
			wait(NULL);
		}
	}
	free(cmd);
	return (0);
}
