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
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					i = puts(va_arg(args, char *));
					count += i;
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar(*(--format));
					count++;
					putchar(*(++format));
					count++;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	return (count);
}
