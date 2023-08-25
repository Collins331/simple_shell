#include "main.h"
/**
 * check_cmd - check if the command exists in the PATH
 * @cmd: input
 * Return: Full path of the cmd if found, otherwise NULL
 */
char *check_cmd(char *cmd)
{
	char *path = getenv("PATH");
	char *dr, *ful_path;
	struct stat st;

	dr = strtok(path, ":");
	while (dr != NULL)
	{
		ful_path = malloc(strlen(dr) + strlen(cmd) + 2);
		if (ful_path == NULL)
		{
			perror("malloc error");
			exit(1);
		}
		sprintf(ful_path, "%s/%s", dr, cmd);
		if (stat(ful_path, &st) == 0)
			return (ful_path);
		free(ful_path);
		dr = strtok(NULL, ":");
	}
	return (NULL);
}
