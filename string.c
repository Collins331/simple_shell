#include "main.h"

/**
 * _strlen - funct that return the lenght of str
 * @s: input
 * Return: n
 */

size_t _strlen(const char *s)
{
	size_t n;

	n = strlen(s);
	return (n);
}

/**
 * _strcmp - funct that compares two str
 * @s1: input 1
 * @s2: input 2
 * Return: out
 */
int _strcmp(const char *s1, const char *s2)
{
	int out;

	out = strcmp(s1, s2);
	return (out);
}

/**
 * _strcspn - funct that get lenght of prefix substr
 * @str: input 1
 * @reject: input 2
 * Return: count
 */
size_t _strcspn(const char *str, const char *reject)
{
	size_t ct = 0;

	ct = strcspn(str, reject);
	return (ct);
}

/**
 * _strtok - funct that extract token from string
 * @str: input 1
 * @delim: input 2
 * Return: token
 */
char *_strtok(char *str, const char *delim)
{
	char *token;

	token = strtok(str, delim);
	return (token);
}
