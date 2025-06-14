#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int count = 0;
	if (!s)
		s = "(null)";
	while(*s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return (count);
}

int ft_putnbr(long nbr)
{
	count = 0;

	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10) /// é maior igual, certo?
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return count;
}

int ft_puthex(unsigned nbr)
{
	int count = 0;
	char *hex = "0123456789abcedef";

	if(nbr >= 16)
		count += ft_puthex(nbr / 16);
	count += ft_putchar(hex[nbr % 16]);
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	count = 0;
	va_start(ap, format);

	while(*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				count += ft_putstr(va_arg(ap, char *));
			else if (*format == 'd')
				count += ft_putnbr(va_arg(ap, int));
			else if (*format == 'x')
				count += ft_puthex(va_arg(ap, unsigned int));
			else if (*format)
				count += ft_putchar(*format);
		}
		else
			count += ft_putchar(*format);
		format++;
	}

	va_end(ap);
	return (count);
}