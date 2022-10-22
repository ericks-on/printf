#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints to stdout according to format
 * @format: like a guide to the function on how to print
 *
 * Return: number of characters printed 
 */
int _printf(const char *format, ...)
{
	int i, size;
	char *str;
	char chr;
	va_list ap;

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '\0')
			return (i);
		else if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				chr = va_arg(ap, int);
				write(1, &chr, 1);
				i++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(ap, char *);
				size = 0;
				while (str[size] != '\0')
					size++;
				write(1, str, size);
				i++;
			}
		}
		chr = format[i];
		write(1, &chr, 1);
	}
	va_end(ap);
	return (i);
}
