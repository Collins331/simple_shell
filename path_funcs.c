#include "shell.h"

/**
 * expand_var - expands a variable to its corresponding value
 * @shell: pointer to shell structure
 *
 * Return: void
 */
void expand_var(sh_data *shell)
{
	int i, j, k;
	char *str, *value;

	for (i = 0; shell->arr[i]; i++)
	{
		if (my_strcmp(shell->arr[i], "$$") == 0)
		{
			free(shell->arr[i]);
			str = my_itoa(shell->pid);
			shell->arr[i] = my_strdup(str);
			free(str);
		}
		else if (my_strcmp(shell->arr[i], "$?") == 0)
		{
			free(shell->arr[i]);
			str = my_itoa(shell->status);
			shell->arr[i] = my_strdup(str);
			free(str);
		}
		else if (shell->arr[i][0] == '$')
		{
			str = malloc(sizeof(char) * my_strlen(shell->arr[i]));
			for (j = 1, k = 0; shell->arr[i][j]; j++, k++)
				str[k] = shell->arr[i][j];
			str[k] = '\0';
			value = _getenv(shell, str);
			if (value == NULL)
			{
				free(value);
				free(str);
			}
			else
			{
				free(shell->arr[i]);
				free(str);
				shell->arr[i] = my_strdup(value);
				free(value);
			}
		}
	}
}

/**
 * add_node_end - adds a new node at the end of the path_l linked list
 * @head: pointer to the list
 * @str: string to add to the end of the list
 *
 * Return: address of new list
 */
path_l *add_node_end(path_l **head, char *str)
{
	path_l *list, *temp;

	temp = *head;
	list = malloc(sizeof(path_l));

	if (!list)
		return (NULL);

	list->str = my_strdup(str);
	list->next = NULL;

	if (!temp)
	{
		*head = list;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = list;
	}

	return (*head);
}

/**
 * path_to_list - creates a linked list of each directory contained in the PATH
 * environment variable
 * @shell: the shell environment's struct
 *
 * Return: a linked list containing the PATH's paths
 */
path_l *path_to_list(sh_data *shell)
{
	char path[5] = "PATH";
	int i, j, k, check;
	path_l *head = NULL;
	char *str;

	for (i = 0; shell->_environ[i]; i++)
	{
		j = 0, check = 0;
		while (shell->_environ[i][j] != '=' && path[j] != '\0')
		{
			if (shell->_environ[i][j] != path[j])
				check = 1;
			j++;
		} k = 0;
		if (check == 0)
		{
			j++;
			while (shell->_environ[i][j])
			{
				if (shell->_environ[i][j] == ':')
				{
					str[k] = '\0', k = 0;
					add_node_end(&head, str);
					free(str);
				}
				else
				{
					if (k == 0)
						str = malloc(sizeof(char) * 150);
					str[k] = shell->_environ[i][j], k++;
				} j++;
			} str[k] = '\0';
			add_node_end(&head, str);
			free(str);
			break;
		}
	} str = _getenv(shell, "PWD");
	add_node_end(&head, str);
	free(str);
	return (head);
}

/**
 * search_path - searches a path linked list to find a particular file
 * @list: pointer to a path list
 * @file: file to search for
 *
 * Return: pointer to full path name of NULL if not found
 */
char *search_path(path_l *list, char *file)
{
	path_l *temp = list;
	char *path;
	struct stat s;

	while (temp)
	{
		path = malloc(sizeof(char) * (my_strlen(temp->str) + my_strlen(file) + 2));

		if (file[0] == '/')
		{
			free(path);
			if (stat(file, &s) == 0)
			{
				path = my_strdup(file);
				return (path);
			}
			else
				return (NULL);
		}

		my_strcpy(path, temp->str);
		my_strcat(path, "/");
		my_strcat(path, file);
		if (stat(path, &s) == 0)
			return (path);

		free(path);
		temp = temp->next;
	}

	return (NULL);
}
