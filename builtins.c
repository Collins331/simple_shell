#include "shell.h"

/**
 * my_cd - changes the working directory of the shell
 * @shell: shell data struct
 *
 * Return: an exit value
 */
int my_cd(sh_data *shell)
{
	int m, n = 0;
	char *new_pwd, *old_pwd = _getenv(shell, "PWD");

	if (shell->arr[1] == NULL)
	{
		free_arr2(shell->arr);
		shell->arr = malloc(sizeof(char *) * 3);
		shell->arr[0] = my_strdup("cd");
		shell->arr[1] = _getenv(shell, "HOME");
		shell->arr[2] = NULL;
	}
	else if (my_strcmp(shell->arr[1], "-") == 0)
	{
		free(shell->arr[1]);
		shell->arr[1] = _getenv(shell, "OLDPWD");
		n++;
	}
	m = chdir(shell->arr[1]);
	if (m == -1)
	{
		cd_err(shell, 1);
		free(old_pwd);
		return (2);
	}
	if (n == 1)
	{
		write(STDOUT_FILENO, shell->arr[1], my_strlen(shell->arr[1]));
		write(STDOUT_FILENO, "\n", 1);
	}
	new_pwd = getcwd(NULL, 1024);
	mod_dir(shell, "new", new_pwd);
	mod_dir(shell, "old", old_pwd);
	free(new_pwd);
	free(old_pwd);
	return (0);
}

/**
 * my_exit - exits the shell
 * @shell: shell data
 *
 * Return: exits with the status of shell, or 0 if none is specified
 */
int my_exit(sh_data *shell)
{
	int ex_it = shell->status;

	if (shell->arr[1])
	{
		shell->status = my_atoi(shell->arr[1]);
		ex_it = shell->status;
	}

	free_list(shell->path);
	if (shell->alias)
		free_aliases(shell->alias);
	free_arr2(shell->av);
	free_arr2(shell->_environ);
	free_arr2(shell->arr);
	free(shell->line);

	exit(ex_it);
}

/**
 * my_env - prints the environment variables
 * @shell: shell data
 *
 * Return: 0
 */
int my_env(sh_data *shell)
{
	int i, len;

	for (i = 0; shell->_environ[i]; i++)
	{
		len = my_strlen(shell->_environ[i]);
		write(STDOUT_FILENO, shell->_environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}

/**
 * my_set - adds or modifies an environment variable
 * @shell: shell data
 *
 * Return: 0 on completion or 12 if memory cannot be allocated
 */
int my_set(sh_data *shell)
{
	int i, j, k = 0, check, done = 0;
	char **new_env;

	for (i = 0; shell->_environ[i]; i++)
		;
	if (shell->arr[1] == NULL || shell->arr[2] == NULL)
		return (cd_err(shell, 2));

	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (12);
	for (i = 0; shell->_environ[i]; i++)
	{
		j = 0, check = 0;
		while (shell->_environ[i][j] != '=' && shell->arr[1][j] != '\0')
		{
			if (shell->_environ[i][j] != shell->arr[1][j])
				check = 1;
			j++;
		}
		if (check == 0)
		{
			new_env[k] = mod_env(shell);
			k++, done = 1;
			continue;
		}
		new_env[k] = my_strdup(shell->_environ[i]);
		k++;
	}
	if (done == 0)
	{
		new_env[k] = mod_env(shell);
		new_env[k + 1] = NULL;
	}
	else
		new_env[k] = NULL;
	free_arr2(shell->_environ);
	shell->_environ = new_env;
	return (0);
}

/**
 * my_unset - deletes an environment variable
 * @shell: shell data
 *
 * Return: 0 on completion or -1 otherwise
 */
int my_unset(sh_data *shell)
{
	int i, j, k = 0, check, done = 0;
	char **new_env;

	for (i = 0; shell->_environ[i]; i++)
		;
	if (shell->arr[1] == NULL)
		return (cd_err(shell, 3));

	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (12);
	for (i = 0; shell->_environ[i]; i++)
	{
		j = 0, check = 0;
		while (shell->_environ[i][j] != '=' && shell->arr[1][j] != '\0')
		{
			if (shell->_environ[i][j] != shell->arr[1][j])
				check = 1;
			j++;
		}
		if (check == 0)
		{
			done = 1;
			continue;
		}
		new_env[k] = my_strdup(shell->_environ[i]);
		k++;
	}
	new_env[k] = NULL;
	if (done == 0)
	{
		perror("Environment variable does not exist\n");
		free_arr2(new_env);
		return (6);
	}
	free_arr2(shell->_environ);
	shell->_environ = new_env;
	return (0);
}
