#include "main.h"

/**
 * fmt_str - print
 * @c: string to be printed
 * Return: number of characters
 */

int fmt_str(char *c)
{
	int i = 0;

	if (!c)
		return (-1);

	while (c[i])
	{
		_putchar(c[i]);
		i++;
	}
	return (i);
}
