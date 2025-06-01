#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int ft_putstr(char * s) // tá certo isso?
{
	int count = 0;
	if (!s)
		s = "(null)"; // confere?
	while (*s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return count;
}

int ft_putnbr(long n)
{
	int count = 0;
	if (count < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return count;
}

int ft_puthex(unsigned int n)
{
	int count = 0;
	char *hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16);
	count += ft_putchar(hex[n % 16]);
	return count;
}

int ft_printf(const char *format, ...) // const char?
{
	count = 0;
	va_list ap;
	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				count += ft_putchar(va_arg(ap, char *));
			else if (*format == 'i')
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
	return count;
}