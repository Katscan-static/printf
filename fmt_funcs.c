#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * fmt_str - print
 * @c: string to be printed
 * Return: number of characters
 */

int fmt_str(char *c)
{
	int i = 0;

	if (!c)
		c = "(nil)";

	while (c[i])
	{
		_putchar(c[i]);
		i++;
	}
	return (i);
}

/**
 * print_num - print numbers
 * @n: number to be printed
 * Return: number of characters
 */

int print_num(int n)
{
	int i, t = 0;

	if (n < 0)
	{
		t = 1;
		if (n == INT_MIN)
			n = ~n;
		else
			n = -n;
		_putchar('-');
	}

	if ((n / 10) == 0)
	{
		_putchar(n % 10 + '0');
		return (1);
	}

	i = 1 + print_num(n / 10);
	_putchar(n % 10 + '0');

	if (t)
		i++;
	return (i);
}

/**
 * print_bin - print binary representation
 * @b: number to be printed
 * Return: number of chracters
 */

int print_bin(unsigned int b)
{
	int i;

	if (!(b / 2))
	{
		_putchar(b % 2 + '0');
		return (1);
	}

	i = 1 + print_bin(b / 2);
	_putchar(b % 2 + '0');

	return (i);
}

/**
 * print_oct - print octal number
 * @o: number to be printed
 * Return: num of characters
 */
int print_oct(unsigned int o)
{
	int m;

	if (!(o / 8))
	{
		_putchar(o % 8 + '0');
		return (1);
	}
	m = 1 + print_oct(o / 8);
	_putchar(o % 8 + '0');
	return (m);
}

/**
 * print_dec - print unsigned int
 * @u: number to be printed
 * Return: number of characters
 */
int print_dec(unsigned int u)
{
	int j = 0;

	if (!(u / 10))
	{
		_putchar(u % 10 + '0');
		return (1);
	}
	j = 1 + print_dec(u / 10);
	_putchar(u % 10 + '0');
	return (j);
}
