#include <stdio.h>
#include <stdarg.h>
/**
 * printf - handles a specifier
 * @format: first
 * Return: an int
 */
int printf(const char *format, ...)
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
					m += _putchar(va_arg(list, int));
					break;
				default:
					m += _putchar('%');
					m += _putchar(*format);
					break;
			}
		}
		else
		{
			m += _putchar(*format);
		}
		format++;
	}
	va_end(list);
	return (m);	
}
