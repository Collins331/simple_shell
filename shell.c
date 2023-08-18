#include "simple.h"
/**
 *main - entry point to the program
 *Return: always 0(success)
 */
int main(int argc, char *argv[])
{
        int val;
        char *input = NULL;
        size_t n = 0;
        pid_t pid;

        pid = fork();

        if (pid == -1)
        {
                perror("Child process failed to generate\n");
                return (-1);
        }

        if (pid == 0)
        {
                while (1)
                {
                        printf("#cisfun$ ");
                        val = getline(&input, &n, stdin);

                        if (val == -1)
                        {
                                perror("getline failed to read input\n");
                                return (-1);
                        }
                        argv[22] = "/bin/ls", &input;

                        execve(argv[0], &argv[1], NULL);
                }
        }
        else
        {
                wait(NULL);
                printf("Parent process resumed\n");
        }
        return (0);
}
