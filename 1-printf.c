#include <stdio.h>
#include <stdarg.h>
/**
 * _1printf - handles a specifier
 * @format: first
 * Return: an int
 */
int _1printf(const char *format, ...)
{
	int m = 0;
	va_list list;

	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					m += fprintf(stdout, "%d", va_arg(list, int));
					break;
				case 'c':
					m += putchar(va_arg(list, int));
					break;
				default:
					m += putchar('%');
					m += putchar(*format);
					break;
			}
		}
		else
		{
			m += putchar(*format);
		}
		format++;
	}
	va_end(list);
	return (m);
}
