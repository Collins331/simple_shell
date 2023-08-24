#include "simple.h"
/**
* use_pid - checks processes in a program
* Return : -1 for error,0 for child process and 1 for parent process
**/

int use_pid()
{
pid_t child_pid = fork();

if (child_pid == -1)
{
perror("fork");
return (-1);
}
else if
(child_pid == 0)
{
return (0);
}
else
{
wait(NULL);
return (1);
}
}
