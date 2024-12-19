#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str) ///teste
		return ft_putstr("(null)"); /// teste
	/*while (*str != '\0')
	{
		ft_putchar((int)*str);
		++count;
		++str;
	}*/
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}
