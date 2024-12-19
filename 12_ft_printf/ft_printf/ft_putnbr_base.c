#include "ft_printf.h"

/*int	ft_putnbr_base(size_t n, char *base_to)
{
	int		count;
	size_t	base_len;*/

//int	ft_putnbr_base(unsigned int n, char *base_to)
int	ft_putnbr_base(unsigned long n, char *base_to)
{
	int				count;
	unsigned int	base_len;

	base_len = ft_strlen(base_to);
	count = 0;
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, base_to);
	count += ft_putchar(base_to[n % base_len]);
	return (count);
}
