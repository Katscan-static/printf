#include "main.h"
#include <stdarg.h>

/**
 * check_spec - check specifier
 * @c: character check
 * @list: va_list to be passed
 * Return: character len
 */

int check_spec(char c, va_list list)
{
	int i = 0, s = 0;

	if (c == 'c')
	{
		_putchar(va_arg(list, int));
		i++;
	}
	else if (c == 's')
		s += fmt_str(va_arg(list, char *));
	else if (c == '%')
	{
		_putchar('%');
		i++;
	}
	else if (c == 'd' || c == 'i')
		s += print_num(va_arg(list, int));
	else if (c == 'b')
		s += print_bin(va_arg(list, unsigned int));
	else if (c == 'o')
		s += print_oct(va_arg(list, unsigned int));
	else if (c == 'u')
		s += print_dec(va_arg(list, unsigned int));
	else if (c == 'x' || c == 'X')
		s += print_hex(va_arg(list, unsigned int), c);
	else if (c == 'p')
		s += print_pointhexa((void *)va_arg(list, unsigned long int));
	else if (c == 'S')
		s += print_s(va_arg(list, char *));
	else
	{
		return (-1);
	}

	return (s + i);
}

/**
 * _printf - prints char and returns number of chars
 * @format: fisrt string argument
 * @...: additional arguments
 * Return: str length
 */

int _printf(const char *format, ...)
{
	int i = 0, s = 0;
	va_list list;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += 1;
			s += check_spec(*format, list);
			format += 1;
		}
		else
		{
			_putchar(*format);
			format += 1;
			i++;
		}
	}
	_putchar(-2);
	return (i + s);
}
