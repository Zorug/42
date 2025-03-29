/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-conversion-precision.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:15:34 by abessa-m          #+#    #+#             */
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

static void	ft_copy_non_numeric(char **str, char *new_str, int *j);
static void	ft_add_padding_and_copy(char **str, char *new_str,
				int n_padding, int *j);

void	ft_format_precision_numeric_add_digits(char **str, int n_padding)
{
	char	*new_str;
	int		j;

	j = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1 + n_padding));
	if (!new_str)
		return ;
	ft_copy_non_numeric(str, new_str, &j);
	ft_add_padding_and_copy(str, new_str, n_padding, &j);
	free(*str);
	*str = new_str;
}

static void	ft_copy_non_numeric(char **str, char *new_str, int *j)
{
	while ((ft_isalnum((*str)[*j]) == 0) && ((*str)[*j] != '\0'))
	{
		new_str[*j] = (*str)[*j];
		(*j)++;
	}
}

static void	ft_add_padding_and_copy(char **str, char *new_str,
				int n_padding, int *j)
{
	int	i;

	i = 0;
	while ((n_padding > 0) && ((*str)[*j] != '\0'))
	{
		new_str[*j + i] = '0';
		n_padding--;
		i++;
	}
	while ((*str)[*j] != '\0')
	{
		new_str[*j + i] = (*str)[*j];
		(*j)++;
	}
	new_str[*j + i] = '\0';
}

void	ft_format_alternate(char *conv_str, char **str)
{
	int		j;
	char	*astr;

	j = 0;
	while (conv_str[j] != '\0'
		&& conv_str[j] != '.'
		&& (conv_str[j] <= '0' || conv_str[j] > '9'))
	{
		if (conv_str[j] == '#')
		{
			astr = (char *)malloc(sizeof(char) * (2 + ft_strlen(*str) + 1));
			if (!astr)
			{
				free(*str);
				return ;
			}
			ft_strlcpy(astr, "0x", (2 + ft_strlen(*str) + 1));
			ft_strlcat(astr, *str, (2 + ft_strlen(*str) + 1));
			free(*str);
			*str = astr;
			return ;
		}
		j++;
	}
	return ;
}
