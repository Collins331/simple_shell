#include "shell.h"

/**
 * my_alias - handles the alias builtin, sets and prints
 * @shell: pointer to the shell structure
 *
 * Return: 0 on success or appropriate err
 */
int my_alias(sh_data *shell)
{
	int i, j, check, ret = 0;

	if (!shell->arr[1])
	{
		ret = print_all_alias(shell);
	}
	else
	{
		for (i = 1; shell->arr[i]; i++)
		{
			check = 0;
			for (j = 0; shell->arr[i][j]; j++)
			{
				if (shell->arr[i][j] == '=')
				{
					check = 1;
					ret = set_alias(shell, shell->arr[i]);
					break;
				}
			}
			if (check == 0)
				ret = print_alias(shell, shell->arr[i]);
		}
	}

	return (ret);
}

/**
 * set_alias - creates an alias
 * @shell: pointer to shell structure
 * @arg: of the format: name=value
 *
 * Return: 0 on success
 */
int set_alias(sh_data *shell, char *arg)
{
	char *name, *value, *str;

	str = my_strdup(arg);
	name = my_strtok(str, "=");
	value = my_strtok(NULL, "");

	add_alias(&shell->alias, name, value);
	if (shell->alias == NULL)
	{
		write(STDERR_FILENO, shell->av[0], my_strlen(shell->av[0]));
		write(STDERR_FILENO, ": Unable to add alias\n", 22);
		free(str);
		return (12);
	}

	free(str);
	return (0);
}

/**
 * print_all_alias - print all aliases set in the current session
 * @shell: pointer to shell structure
 *
 * Return: 0 on success or 61 if no data is found
 */
int print_all_alias(sh_data *shell)
{
	alias_l *temp = shell->alias;
	char *alias;
	int len1, len2;

	if (!temp)
	{
		write(STDERR_FILENO, shell->av[0], my_strlen(shell->av[0]));
		write(STDERR_FILENO, ": No aliases found\n", 19);
		return (61);
	}
	while (temp)
	{
		len1 = my_strlen(temp->name);
		len2 = my_strlen(temp->value);
		alias = malloc(sizeof(char) * (len1 + len2 + 2));
		if (!alias)
			return (12);

		my_strcpy(alias, temp->name);
		my_strcat(alias, "=");
		my_strcat(alias, temp->value);

		write(STDOUT_FILENO, alias, len1 + len2 + 1);
		write(STDOUT_FILENO, "\n", 1);

		free(alias);
		temp = temp->next;
	}

	return (0);
}

/**
 * print_alias - prints a specific alias
 * @shell: pointer to shell structure
 * @arg: name of alias to print in the form: name
 *
 * Return: 0 on success
 */
int print_alias(sh_data *shell, char *arg)
{
	alias_l *temp = shell->alias;
	char *alias = NULL;
	int len1, len2;

	if (!temp)
	{
		write(STDERR_FILENO, shell->av[0], my_strlen(shell->av[0]));
		write(STDERR_FILENO, ": No aliases found\n", 19);
		return (61);
	}
	while (temp)
	{
		if (my_strcmp(arg, temp->name) == 0)
		{
			len1 = my_strlen(temp->name);
			len2 = my_strlen(temp->value);
			alias = malloc(sizeof(char) * (len1 + len2 + 2));
			if (!alias)
				return (12);

			my_strcpy(alias, temp->name);
			my_strcat(alias, "=");
			my_strcat(alias, temp->value);

			write(STDOUT_FILENO, alias, len1 + len2 + 1);
			write(STDOUT_FILENO, "\n", 1);
			free(alias);
		}
		temp = temp->next;
	}

	return (0);
}

/**
 * add_alias - adds a new node at the end of the alias_l list
 * @head: pointer to alias list
 * @name: name of the alias
 * @value: value of the alias
 *
 * Return: address of resulting list
 */
alias_l *add_alias(alias_l **head, char *name, char *value)
{
	alias_l *list, *temp = *head;
	char *v;

	if (value[0] == 39)
		v = my_strdup(value);
	else
	{
		v = malloc(sizeof(char) * (my_strlen(value) + 3));
		my_strcpy(v, "'");
		my_strcat(v, value);
		my_strcat(v, "'");
	}
	while (temp)
	{
		if (my_strcmp(temp->name, name) == 0)
		{
			free(temp->value);
			temp->value = my_strdup(v);
			free(v);
			return (temp);
		}
		temp = temp->next;
	}
	temp = *head;
	list = malloc(sizeof(alias_l));
	if (!list)
		return (NULL);
	list->name = my_strdup(name);
	list->value = my_strdup(v);
	list->next = NULL;
	if (!temp)
		*head = list;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = list;
	}
	free(v);
	return (*head);
}
