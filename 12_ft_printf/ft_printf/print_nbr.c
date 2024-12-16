#include "ft_printf.h"

int print_nbr(int n, int uint)
{
	long int	i;
	size_t		count;

	if(!uint)
		i = n;
	else
		i = (unsigned int) n;
	count = 0;
	if (i < 0)
	{
		count += print_char('-');
		i *= -1;
	}
	if (i < 10)
		count += print_char((i % 10) + '0');
	else
	{
		count += print_nbr(i / 10, 0);
		count += print_nbr(i % 10, 0);
	}
	return (count);
}