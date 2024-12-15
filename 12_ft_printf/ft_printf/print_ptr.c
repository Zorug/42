#include "ft_printf.h"

char	*putnbrptr(uintptr_t n, char *base_to)
{
	int			str_size;
	uintptr_t	temp_n;
	int			sizeofbase;
	char		*str;

	str_size = 0;
	temp_n = n;
	sizeofbase = ft_strlen(base_to);
	while (temp_n > 0)
	{
		temp_n = temp_n / sizeofbase;
		str_size++;
	}
	str = malloc(sizeof(char) * (str_size + 1));
	if (!str)
		return (NULL);
	while (n > 0)
	{
		str[--str_size] = base_to[n % sizeofbase];
		n = n / sizeofbase;
	}
	return (str);
}

int	print_ptr(void *ptr)
{
	int		count;
	char	*hex_str;

	count = 0;
	hex_str = NULL;
	if (ptr == NULL)
		count += print_str("(nil)");
	else
	{
		count += print_str("0x");
		hex_str = putnbrptr((uintptr_t)ptr, "0123456789abcdef");
		if (hex_str)
		{
			count += print_str(hex_str);
			free (hex_str);
		}
	}
	return (count);
}
