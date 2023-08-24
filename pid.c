#include "simple.h"
/**
* use_pid - checks processes in a program
*@child_pid : stores process ID of the child process
* Return:returns integer value -1 for error when the fork system call fails
* 0 for child process and 1 for parent  process as it waits for the child
**/

int use_pid(pid_t child_pid)
{
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
