#include "main.h"
#include <stdarg.h>

/**
 * check_spec - check specifier
 * @c: character check
 * @f1: check flags
 * @list: va_list to be passed
 * Return: character len
 */

int check_spec(char c, va_list list, char f1)
{
	int i = 0, s = 0, ft = 0;

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
	{
		ft = va_arg(list, int);
		if ((f1 == ' ' || f1 == '+') && ft < 0)
			ft *= -1;
		s += print_num(ft);
	}
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
		return (-1);
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
	int i = 0, s = 0, f = 0;
	char f1, f2;
	va_list list;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += 1;
			f1 = *format;
			if (f1 ==  ' ' || f1 == '+' || f1 == '#')
			{
				format += 1;
				f2 = *format;
				f = flags(f1, f2);
				if (f == -1)
					return (-1);
				s += f;
			}

			s += check_spec(*format, list, f1);
			if (s == -1)
				return (-1);
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
