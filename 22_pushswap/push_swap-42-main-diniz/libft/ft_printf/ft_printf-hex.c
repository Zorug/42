/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:31:29 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:51:32 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//SYNTAX
//%[flags][width][.precision]conversion
// [flags] - (minus)                    | left-align if padded
// [flags] 0 (zero)                     | uses '0' to pad the width
// [flags] + (plus) (overrides space)   | prints '+' for positive numbers
// [flags]' '(space)                    | prints ' ' for positive numbers
// [flags] # (hash)                     | alternate form (includes prefix)
//        [width] digit (decimal int)   | padding
//               [.precision] . (point) | minimum number of digits

#include "../libft.h"

static void	printf_pointer_nil(char *conv_str, int *count);

// Converts to hexadecimal from decimal
void	printf_hex_lower(char *conv_str, int *count, va_list ptr_args)
{
	char			*str;
	unsigned int	dec_nbr;

	if (!conv_str)
		return ;
	dec_nbr = va_arg(ptr_args, unsigned int);
	str = ft_ultoa(dec_nbr, 16);
	ft_format_precision_hexadecimal(conv_str, &str);
	if (dec_nbr != 0)
		ft_format_alternate(conv_str, &str);
	ft_format_width(conv_str, &str);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}

void	printf_hex_upper(char *conv_str, int *count, va_list ptr_args)
{
	char			*str;
	unsigned int	dec_nbr;
	int				j;

	if (!conv_str)
		return ;
	dec_nbr = (unsigned int) va_arg(ptr_args, unsigned int);
	str = ft_ultoa(dec_nbr, 16);
	ft_format_precision_hexadecimal(conv_str, &str);
	if (dec_nbr != 0)
		ft_format_alternate(conv_str, &str);
	j = 0;
	while (str[j] != '\0')
	{
		str[j] = ft_toupper(str[j]);
		j++;
	}
	ft_format_width(conv_str, &str);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}

char	*ft_ultoa(unsigned long nbr, unsigned int radix)
{
	size_t			len;
	char			*str;
	unsigned long	n;

	len = 1;
	n = nbr;
	while (n >= radix)
	{
		len++;
		n /= radix;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		if ((nbr % radix) >= 10)
			str[len] = 'a' + (nbr % radix) - 10;
		else
			str[len] = '0' + (nbr % radix);
		nbr /= radix;
	}
	return (str);
}

void	printf_pointer(char *conv_str, int *count, va_list ptr_args)
{
	char			*str;
	char			*astr;
	unsigned long	dec_nbr;

	if (!conv_str)
		return ;
	dec_nbr = va_arg(ptr_args, unsigned long);
	if (dec_nbr == 0)
	{
		printf_pointer_nil(conv_str, count);
		return ;
	}
	str = ft_ultoa(dec_nbr, 16);
	astr = (char *)malloc(sizeof(char) * (2 + ft_strlen(str) + 1));
	if (astr)
	{
		ft_strlcpy(astr, "0x", (2 + ft_strlen(str) + 1));
		ft_strlcat(astr, str, (2 + ft_strlen(str) + 1));
		free(str);
		str = astr;
		ft_format_width(conv_str, &str);
		ft_putstr_fd(str, 1);
		*count += ft_strlen(str);
	}
	free(str);
}

static void	printf_pointer_nil(char *conv_str, int *count)
{
	char	*str;

	str = ft_strdup("(nil)");
	ft_format_width(conv_str, &str);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
