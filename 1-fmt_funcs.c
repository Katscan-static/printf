#include "main.h"
#define HEXADEC_S "0123456789abcdef"
#define HEXADEC_B "0123456789ABCDEF"

/**
 * print_hex - print hex numbers
 * @n: number to be printed
 * @c: character to be tested
 * Return: num of characteristics
 */
int print_hex(unsigned int n, char c)
{
	int a;
	char *str = HEXADEC_S;

	if (c == 'X')
		str = HEXADEC_B;
	if (!(n / 0x10))
	{
		_putchar(str[n % 0x10]);
		return (1);
	}
	a = 1 + print_hex(n / 0x10, c);
	_putchar(str[n % 0x10]);
	return (a);
}
/**
 * print_pointhexa - print hex numbers
 * @i: number to be printed
 * @s: char to be printed
 * Return: number of characteristics
 */
int print_pointhexa(int i, char *s)
{
	int m;
	char *str = HEXADEC_S;

	if (i < 0)
	{
		_putchar('-');
		i = i * -1;
	}
	if (!(i / 0x10))
	{
		_putchar(str[i % 0x10]);
		return (1);
	}
	m = 1 + print_pointhexa(i / 0x10, *s);
	_putchar(str[i % 0x10]);
	return (m);

/**
 * print_s - print string and non printable char
 * @c: string to be printed
 * Return: number of chars
 */

int print_s(char *c)
{
	int i = 0, s = 0;

	if (!c)
		return (1);

	for (; c[i]; i++)
	{
		if (c[i] < 32 || c[i] >= 127)
		{
			s += _printf("\\x");
			if (c[i] < 0x10)
			{
				_putchar('0');
			}
			s += _printf("%X", c[i]);
		}
		else
		{
			_putchar(c[i]);
		}
	}
	return (s + i);
}
