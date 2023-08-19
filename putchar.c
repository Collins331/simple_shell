#include "simple.h"
/**
 * put_char - prints a char
 * @c: the char to output
 * *Return: 1 (success) else -1(error)
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}
