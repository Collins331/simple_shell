#include "simple.h"

/**
* main - the entry point of the shell program
* Return:0 when program runs successfully, 1 on error
*/

int main(void)
{
size_t buf_size = 0;
char *lineptr = NULL;
char *token;
int i = 0;
char **array;
pid_t child_pid;

while (1)
{
print_prompt();
getline(&lineptr, &buf_size, stdin);
token = strtok(lineptr, "\n\t");
array = malloc(sizeof(char *) * 1024);
while (token)
{
array[i] = token;
token = strtok(NULL, "\n\t");
i++;
}
if (lineptr[0] == '\0')
{
free(array);
continue;
}
array[i] = NULL;
child_pid = fork();
if (child_pid == 0)
{
use_execve(array);
}
else
{
use_pid(child_pid);
}
i = 0;
free(array);
}
free(lineptr);
return (0);
}
