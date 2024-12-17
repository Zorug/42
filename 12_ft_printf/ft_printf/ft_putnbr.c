#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count;
	//char	c;

	count = 0;
	if (n == -2147483648)
		//return(print_str("-2147483648"));
		return(ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	//c = (n % 10) + '0';
	//count += ft_putchar(c);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}