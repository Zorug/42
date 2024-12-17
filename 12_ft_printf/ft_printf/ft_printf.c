#include "ft_printf.h"

int print_format(char specifier, va_list ap)
{
	int count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		//count += print_str(va_arg(ap, char *));
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_ptr(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, int));
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