#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>

#define BUF_SIZE 1024

void print_prompt(void);
int put_char(char c);
char *get_line(void);
int put_char(char c);
char **find_path(char **environ);
char *get_env(char **environ, char *dir);
char *av_path(char **av, char **token);
char **tokenize(char *str, char *delim);
int use_execve(char **array);
int use_pid(pid_t child_pid);
extern char **environ;

#endif
