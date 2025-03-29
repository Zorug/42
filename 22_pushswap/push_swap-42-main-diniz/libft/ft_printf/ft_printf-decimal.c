/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:44:57 by abessa-m          #+#    #+#             */
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

void	printf_integer(char *conv_str, int *count, va_list ptr_args)
{
	char	*str;

	if (!conv_str)
		return ;
	str = ft_itoa((int)va_arg(ptr_args, int));
	ft_format_precision_numeric(conv_str, &str);
	ft_format_width(conv_str, &str);
	ft_format_place_sign(conv_str, &str);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}

void	printf_character(char *conv_str, int *count, va_list ptr_args)
{
	char	*ptr_chr;
	size_t	len;
	size_t	j;

	if (!conv_str)
		return ;
	ptr_chr = (char *)malloc(sizeof(char) * (1 + 1));
	if (!ptr_chr)
		return ;
	ptr_chr[0] = (int) va_arg(ptr_args, int);
	ptr_chr[1] = '\0';
	len = ft_format_width(conv_str, &ptr_chr);
	j = 0;
	while (j < len)
	{
		ft_putchar_fd(ptr_chr[j], 1);
		*count += 1;
		j++;
	}
	free(ptr_chr);
}

void	printf_string(char *conv_str, int *count, va_list ptr_args)
{
	char	*str;

	if (!conv_str)
		return ;
	str = va_arg(ptr_args, char *);
	if (!str)
		str = "(null)";
	str = ft_strdup(str);
	ft_format_precision_string(conv_str, &str);
	ft_format_width(conv_str, &str);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}

void	printf_unsigned_integer(char *conv_str, int *count, va_list ptr_args)
{
	char	*str;

	if (!conv_str)
		return ;
	str = ft_itoa((unsigned int)va_arg(ptr_args, unsigned int));
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}

void	printf_unsigned_d(char *conv_str, int *count, va_list ptr_args)
{
	char	*str;

	if (!conv_str)
		return ;
	str = ft_ultoa((unsigned long)va_arg(ptr_args, unsigned int), 10);
	if (!str)
		return ;
	ft_format_precision_numeric(conv_str, &str);
	ft_format_width(conv_str, &str);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
