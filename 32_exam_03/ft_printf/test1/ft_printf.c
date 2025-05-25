#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int count = 0;
	
	if (!s)
	s = "(null)";
	// faltou implementar o s!!
	while (*s)
		count += ft_putchar(*s);
		// s++;
	return count;
}

int ft_putnbr(long n)
{
	int count = 0;
	
	if (n < 0)
	{
		n = -n;
		count += ft_putchar('-');
	}
	
	if (n >= 10)
	{
		count += ft_putnbr(n/10);
	}
	count += ft_putchar(n % 10 + '0');
	return count;
}

int ft_puthex(unsigned int n)
{
	int count = 0;
	char *hex = "0123456789abcdef";
	
	if (n >= 16)
	{
		count += ft_puthex(n/16);
	}
	count += ft_putchar(hex[n % 16]);
	return count;
}

int ft_printf(const char *format, ...)
{
	int count = 0;
	va_list ap;
	va_start (ap, format)
	
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				// aqui está como va_arg(ap, char *)
				count += ft_putstr(va_arg(ap, *char));
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
	
	va_end (ap)
	return count;
}
