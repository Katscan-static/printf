#include "main.h"
#include <stdlib.h>

/**
 * rev - prints the reverse of null terminated string
 * @c: null terminated string to be printed
 *
 * Return: string length or -1 if @c is NULL
 */

int rev(char *c)
{
	int i = 0, j = 0, s = 0;

	if (!c)
		return (0);

	while (c[i])
		i++;

	j = i - 1;

	for (; j >= 0; j--, s++)
	{
		_putchar(c[j]);
	}
	_putchar(-2);
	return (i);
}
