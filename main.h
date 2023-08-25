#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>

extern char **environ;

#define MCL 100 /*MAX COMMAND LENGTH*/
#define IBS 64 /*INITIAL BUFFER SIZE*/
#define BGF 2 /*BUFFER GROWING FACTOR*/

void _prompt(void);

void _tokenize(char *args[], char *cmd);
void _ext(char *cmd);
void _printenv(char *cmd);
/*int _execve(const char *pathname, char *const argv[], char *const envp[]);*/
/*pid_t _waitpid(pid_t pid, int *wstatus, int options);*/
/*char *check_cmd(char *cmd);*/

/* string function */
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *str);
size_t _strcspn(const char *str, const char *reject);
char *_strtok(char *str, const char *delim);

/* getline */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
