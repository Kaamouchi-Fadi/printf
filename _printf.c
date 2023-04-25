#include "main.h"
#include <stdarg.h>

/**
  * _printf - It prints output to stdout
  * @format: The format of chars to print
  *
  * Return: On success, the number of characters printed
  */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					i = _puts(va_arg(args, char *));
					count += i;
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar(*(--format));
					count++;
					_putchar(*(++format));
					count++;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	return (count);
}
