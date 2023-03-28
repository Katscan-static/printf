#include "main.h"

/**
 * print_hex - print hex numbers
 * @n: number to be printed
 * Return: num of characteristics
 */
int print_hex(unsigned int n)
{
	int a = 0;

	if (!(n / 0x10))
	{
		_putchar(n % 0x10 + '0');
		return (1);
	}
	a = 1 + print_hex(n / 0x10);
	_putchar(n % 0x10 + '0');
	return (a);
}
