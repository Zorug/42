#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		ft_putchar((int)*str);
		++count;
		++str;
	}
	return (count);
}
