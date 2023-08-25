#ifndef SHELL_H_
#define SHELL_H_

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFSIZE 1024
#define NEWLINE '\n'
#define DELIM_T " \t\n\a\r"

extern char **environ;

/**
 * struct path - A linked list containing each path in PATH variable
 * @str: A single variable (i.e /usr/bin )
 * @next: next path in the list
 */
typedef struct path
{
	char *str;
	struct path *next;
} path_l;

/**
 * struct alias - linked list of all set aliases in the shell
 * @name: the name of the alias
 * @value: the value of the alias corresponding to name
 * @next: next alias in aliases
 */
typedef struct alias
{
	char *name;
	char *value;
	struct alias *next;
} alias_l;

/**
 * struct data - structure containing shell data
 * @_environ: the shell environment, copied from the default shell environment
 * @alias: linked list of aliases created in the current shell session
 * @arr: an array containing each argument entered into the shell
 * @av: arguments vector
 * @length: length of the line
 * @line: the entire line of commands
 * @path: linked list containing the PATH variable
 * @pid: process id of the current shell
 * @status: shell status, updated on success/failure of a command
 */
typedef struct data
{
	alias_l *alias;
	char **_environ;
	char **arr;
	char **av;
	char *line;
	int status;
	path_l *path;
	pid_t pid;
	size_t length;
} sh_data;

/**
 * struct built_in - structure containg builtin functions and their functions
 * @str: the command name
 * @func: pointer to the function for the specific command
 */
typedef struct built_in
{
	char *str;
	int (*func)(sh_data *);
} built_in;

/* Major stakeholders */
char **get_commands(char *, size_t);
char *check_shell(sh_data *);
char *_getenv(sh_data *, char *);
char *search_path(path_l *, char *);
int (*get_func(char **))(sh_data *);
void loop_shell(sh_data *);
void non_interact(sh_data *);
int rm_comments(char **);
void expand_var(sh_data *);
int cd_err(sh_data *, int);

/* Aliases */
alias_l *add_alias(alias_l **, char *, char *);
int my_alias(sh_data *);
int print_alias(sh_data *, char *);
int print_all_alias(sh_data *);
int set_alias(sh_data *, char *);
void check_alias(sh_data *);
void free_aliases(alias_l *);

/* Other builtins */
int my_cd(sh_data *);
void mod_dir(sh_data *, char *, char *);
int my_env(sh_data *);
char *mod_env(sh_data *);
int my_exit(sh_data *);
int my_set(sh_data *);
int my_unset(sh_data *);

/* Replacement functions */
char *my_strcat(char *, char *);
char *my_strcpy(char *, char *);
char *my_strdup(char *);
char *my_itoa(int);
char *my_strtok(char *, const char *);
int my_atoi(char *);
int my_isdigit(char *);
int my_strcmp(char *, char *);
int my_strlen(char *);
void *my_memchr(register const void *, int, size_t);
void *my_realloc(void *, unsigned int, unsigned int);
void my_memcpy(void *, const void *, unsigned int);
ssize_t my_getline(char **, size_t *, FILE *);
void insert_line(char **, size_t *n, char *, size_t);
void reverse_str(char *);

/* Custom functions */
void free_arr2(char **);
void free_list(path_l *);
int get_len(int);
path_l *add_node_end(path_l **, char *);
path_l *path_to_list(sh_data *);
size_t print_list(const path_l *);
void print_path_dir(void);

#endif
