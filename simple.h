#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUF_SIZE 1024

void print_prompt();
int put_char(char c);
void tokenize(char *str, char *delim, char **array, int *count);
void use_execve(char **array);
void use_pid(pid_t child_pid);



#endif
