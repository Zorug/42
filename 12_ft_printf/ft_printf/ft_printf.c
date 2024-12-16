#include "ft_printf.h"

int print_format(char specifier, va_list ap)
{
	int count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_ptr(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_nbr(va_arg(ap, int), 0);
	else if (specifier == 'u')
		count += print_nbr(va_arg(ap, int), 1);
	return count;
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	count = 0;
	while(*format != 0)
	{
		if(*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return count;
}