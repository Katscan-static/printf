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

int print_num(int n)
{
	int i, t = 0;
	if (n < 0)
	{
		t = 1;
		_putchar('-');
		n = ~n + 1;
	}

	if ((n / 10) == 0)
	{
		_putchar(n % 10 + '0');
		return 1;
	}

	i = 1 + print_num(n / 10);	 
	_putchar(n % 10 + '0');

	if (t)
		i++;
	return (i);
}
