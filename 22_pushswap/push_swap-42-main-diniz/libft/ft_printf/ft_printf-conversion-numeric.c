/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-conversion-numeric.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:42:23 by abessa-m          #+#    #+#             */
/*   Updated: 2024/11/13 13:42:23 by abessa-m         ###   ########.fr       */
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

void		ft_format_precision_numeric_add_digits(char **str, int n_padding);
static void	ft_set_it_empty(char **str);

// minimun number of digits to be printed
void	ft_format_precision_numeric(char *conv_str, char **str)
{
	char	*ptr_dot;
	long	precision;
	int		digits;
	int		j;

	if (*str[0] == '\0')
		return ;
	ptr_dot = ft_strchr(conv_str, '.');
	if (ptr_dot == NULL)
		return ;
	ptr_dot++;
	precision = ft_atoi(ptr_dot);
	if ((precision == 0) && (ft_atoi(*str) == 0))
		ft_set_it_empty(str);
	j = 0;
	digits = 0;
	while ((*str)[j] != '\0')
	{
		if (ft_isdigit(str[0][j]) != 0)
			digits++;
		j++;
	}
	if (precision > digits)
		ft_format_precision_numeric_add_digits(str, (int)(precision - digits));
}

static void	ft_set_it_empty(char **str)
{
	char	*new_str;

	new_str = (char *)calloc(sizeof(char), 1);
	if (!new_str)
		return ;
	free(*str);
	*str = new_str;
}

void	ft_format_precision_hexadecimal(char *conv_str, char **str)
{
	char	*ptr_dot;
	long	precision;
	int		digits;
	int		j;

	if (*str[0] == '\0')
		return ;
	ptr_dot = ft_strchr(conv_str, '.');
	if (ptr_dot == NULL)
		return ;
	ptr_dot++;
	precision = ft_atoi(ptr_dot);
	if ((precision == 0) && (ft_hextoi(*str) == 0))
		ft_set_it_empty(str);
	j = 0;
	digits = 0;
	while ((*str)[j] != '\0')
	{
		if (ft_isalnum(str[0][j]) != 0)
			digits++;
		j++;
	}
	if (precision > digits)
		ft_format_precision_numeric_add_digits(str, (int)(precision - digits));
}

int	ft_hextoi(char *hex_str)
{
	int		result;
	int		len;
	int		index;
	char	chr;

	index = 0;
	result = 0;
	len = ft_strlen(hex_str);
	if (len >= 2 && hex_str[0] == '0' && ft_tolower(hex_str[1]) == 'x')
		index = 2;
	while (index < len)
	{
		chr = ft_tolower(hex_str[index]);
		if (chr >= '0' && chr <= '9')
			result = (result * 16) + (chr - '0');
		else if (chr >= 'a' && chr <= 'f')
			result = (result * 16) + (chr - 'a' + 10);
		index++;
	}
	return (result);
}
