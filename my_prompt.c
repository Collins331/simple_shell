#include"simple.h"

int main(void)
{
    size_t buf_size = 0;
    char *lineptr = NULL;
    char *token;
    int status, i = 0;
    char **array;
    pid_t child_pid;
    
    while(1)
    {
        putchar('M');
        putchar('y');
        putchar('s');
        putchar('h');
        putchar('e');
        putchar('l');
        putchar('l');
        putchar('$');
        putchar(' ');
        int read_char = getline(&lineptr, &buf_size, stdin);
        token = strtok(lineptr, "\n\t");
        array = malloc(sizeof(char *) *1024);

        while (token)
        {
            array[i] = token;
            token = strtok(NULL, "\n\t");
            i++;
        }
        if (read_char == -1)
    {
        putchar('\n');
        return (-1);
    }
            array[i] = NULL;
            child_pid = fork();

        if (child_pid == 0)
        {
            if (execve(array[0], array, NULL) == -1)
                perror("Error");
        } 
        else
        {
                wait(&status);
        }
	i = 0;
        free(array);
    }
}
