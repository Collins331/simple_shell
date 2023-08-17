#include "simple.h"

int main(void)
{   
    char *prompt = "(myshell)$";// the value to prompt user to type a command
    char *buffer = NULL;
    size_t n = 0;
    ssize_t read_char;

    //creates a loop
    while (1){
    printf("%s", prompt);// gives the user go ahead to print command
    read_char = getline(&buffer, &n, stdin);
    //checks if getline has reached EOF or CTRL + D 
    if (read_char == -1)
    {
        printf("Exiting shell......\n");
        return (-1);
    }
    printf("%s\n", buffer);
    
    }
    free(buffer);//frees allocated space
} 
