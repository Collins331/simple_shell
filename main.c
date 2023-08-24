#include "simple.h"

/*
* main - function that runs the shell program
*@i: counter variable
*@lineptr: pointer to arguments run
*@array: array that stores parsed arguments
*@buf_size: size of the buffer
* Return : 0 when program runs successfully
**/

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
