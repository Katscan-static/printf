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

	while (m >= 1024 || c == -1)
	{
		write(1, &buf, -1);
		m++;
	}
	if (m != -1)
	{
		c = buf[m];
		m++;
	}
	return (1);
}
/**
 * _puts - prints a string
 * @str: pointer to string
 * Return: number chars
 */
int _puts(char *str)
{
	register int m;

	for (m = 0; str[m] != '\0'; m++)
		_putchar(str[m]);
	return (m);
}
