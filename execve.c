#include "simple.h"

/**
* use_execve- function that executes a command
* array : array to be executed
**/

void use_execve(char **array)
{
if (execve(array[0], array, NULL) == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}
}
