#include "main.h"
#include <stdio.h>
int _printf_h(const char *format, va_list args, int *i);

/**
 * _printf - prints a string to stdout
 * @format: format of the string
 * Return: the numb of chars printed to the stdout
 */

int _printf(const char *format, ...)
{
int i = 0, c = 0;
va_list args;
va_start(args, format);
if (format == NULL)
return (-1);
for (i = 0; *(format + 1) != '\0'; i++)
{
if ((*format + 1) ==  '%')
{
if (format[i + 1] == '\0')
return (-1);
c += _printf_h(format, args, &i);
}
else
{
_putchar(*(format + i));
c++;
}
}
va_end(args);
return (c);
}
/**
 * _printf_h - produce output according to a format
 * @format: format of the string
 * @args: char string
 * @i: char string
 * Return: the numb of chars printed without null 40
 */
int _printf_h(const char *format, va_list args, int *i)
{
int ress = 0, j, m;
char *tmp, *nu = "(null)";
switch (*(format + *i + 1))
{
case 's':
tmp = va_arg(args, char *);
if (tmp == NULL)
{
for (m = 0; *(nu + m); m++)
{
_putchar(*(nu + m));
ress++;
}
}
else
{
for (j = 0; tmp[j] != '\0'; j++)
{
_putchar(tmp[j]);
ress++;
}
}
break;
case 'c':
_putchar(va_arg(args, int));
ress++;
break;
case '%':
_putchar((format[*i]));
ress++;
break;
default:
_putchar(format[*i]);
ress++;
*i -= 1;
break;
}
*i += 1;
return (ress);
}
