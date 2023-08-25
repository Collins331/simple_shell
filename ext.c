#include "main.h"
/**
 * _ext - exiting shell programme
 * @cmd: input
 */

void _ext(char *cmd)
{
	if (strcmp(cmd, "exit") == 0)
	{
		printf("Exiting shell programm\n");
		exit(0);
	}
}
