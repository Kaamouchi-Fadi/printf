#include "main.h"

/**
 * get_precision - this function Extracts the precision
 * value from a format string.
 * @s: The format string to parse.
 * @params: A struct containing formatting parameters for the string.
 * @ap: A pointer to a variable argument list containing arguments to format.
 * Return: A pointer to the next character in the
 * format string after the precision specifier.
*/

char *get_precision(char *s, prm_t *params, va_list ap)
{
	int precision = 0;

	/* Check if the format string contains a precision specifier */
	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		precision  = va_arg(ap, int);
		s++;
	}
	/**
	 * If the next character is not '*', loop through the following
	 * characters in the format string and convert them into an integer value.
	 */
	else
	{
		for (; _isdigit(*s); s++)
		{
			precision = precision * 10 + (*s - '0');
		}
	}
	(*params).precisions = precision;
	return (s);
}
