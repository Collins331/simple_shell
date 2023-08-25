#include "simple.h"
/**
 * put_char - outputs the char c
 * @c: the char type
 * Return: 1 (success) 
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}
