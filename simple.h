#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define BUF_SIZE 1024

char *get_line(void);
int exe_cve(char **av);
int put_char(char c);
extern char **environ;
char **str_tok(char *str, char *delim);
void prompt(void);

#endif
