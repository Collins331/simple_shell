#include "main.h"

/**
 * _putchar - print char
 * @c: input
 * Return: 0
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
