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
	char *p;

	if (!c)
		return (0);

	while (c[i])
		i++;

	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (0);

	j = i - 1;

	for (; j >= 0; j--, s++)
	{
		p[s] = c[j];
	}
	p[i] = '\0';
	_printf("%s", p);
	free(p);
	return (i);
}
