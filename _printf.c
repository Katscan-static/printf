#include "main.h"
#include <stdarg.h>

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
			if (*format == 'c')
			{
				_putchar(va_arg(list, int));
				i++;
			}
			else if (*format == 's')
			{
				s += fmt_str(va_arg(list, char *));
			}
			else if (*format == '%')
			{
				_putchar('%');
				i++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				s += print_num(va_arg(list, int));
			}
			else
			{
				return (-1);
			}
			format += 1;
		}
		else
		{
			_putchar(*format);
			format += 1;
			i++;
		}
	}
	return (i + s);
}
