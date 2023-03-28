#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes char c
 * @c: char to be printed
 * Return: 1 (success), -1 otherwise
 */
int _putchar(char c)
{
	static char buf[1024];
	static int m;

	if (m >= 1024 || c == -2)
	{
		write(1, &buf, m);
		m = 0;
	}
	if (c != -2)
	{
		buf[m] = c;
		m++;
	}
	return (1);
}

/**
 * _puts - prints string
 * @c: string to be printed
 * Return: number of characters
 */

int _puts(char *c)
{
	int i = 0;

	for (; c[i]; i++)
		_putchar(c[i]);
	return (i);
}
