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
		_putchar('-');
		n = n * -1;
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
