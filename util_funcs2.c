#include "shell.h"

/**
 * my_memchr - searches the memory for a character
 * @src_void: string to search
 * @c: the character to find
 * @length: of the string
 *
 * Return: nil
 */
void *my_memchr(const void *src_void, int c, size_t length)
{
	const unsigned char *src = (const unsigned char *)src_void;

	while (length-- > 0)
	{
		if (*src == c)
			return ((void *)src);
		src++;
	}
	return (NULL);
}

/**
 * my_strtok - tokenizes a string
 * @str: strings to tokenize
 * @delim: iters to use
 * Return: a token
 */
char *my_strtok(char *str, const char *delim)
{
	static char *s;
	char *ret = NULL;

	if (str != NULL)
	{
		s = str;
	}
	if (s != NULL && my_strlen(s))
	{
		const size_t dlen = my_strlen((char *)delim);
		/* Skip consecutive delimiters */
		while (*s && my_memchr(delim, *s, dlen) != NULL)
		{
			++s;
		}
		/* If the beginning of the token is not at the end of the string... */
		if (*s)
		{
			/* Set our retval to the first non-delim char */
			ret = s;
			/* Search for the next non-delim character, if any */
			while (*s)
			{
				if (my_memchr(delim, *s, dlen) != NULL)
				{
					break;
				}
				else
					++s;
			}
			if (*s)
			{
				/* Null-terminate the token and march the stored pointer forward */
				s[0] = 0;
				++s;
			}
		}
	}
	return (ret);
}

/**
 * my_memcpy - copies data to another pointer with casts
 * @dest: dest to paste data
 * @src: source to copy data from
 * @size: length of data to copy
 * Return: nothing
 */
void my_memcpy(void *dest, const void *src, unsigned int size)
{
	char *ptr = (char *)src;
	char *new = (char *)dest;
	unsigned int i;

	for (i = 0; i < size; i++)
		new[i] = ptr[i];
}

/**
 * my_realloc - reallocates memory
 * @ptr: pointer previously allocated with malloc
 * @old_size: the previous poniter size
 * @new_size: new size to allocate
 *
 * Return: pointer to new memory
 */
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	nptr = malloc(new_size);
	if (nptr == NULL)
		return (NULL);

	for (i = 0; i < new_size && i < old_size; i++)
		;

	memcpy(nptr, ptr, i);
	free(ptr);

	return (nptr);
}

/**
 * my_isdigit - check if a string contains digits only
 * @nstr: string to be checked
 * Return: 1 if digit, 0 if not digit
 */
int my_isdigit(char *nstr)
{
	int i;

	for (i = 0; nstr[i] != '\0' ; i++)
	{
		if (nstr[i] < 48 || nstr[i] > 57)
			return (0);
	}

	return (1);
}
