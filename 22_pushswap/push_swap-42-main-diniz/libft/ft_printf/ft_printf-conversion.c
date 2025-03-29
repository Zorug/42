/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:58:49 by abessa-m          #+#    #+#             */
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

static size_t	ft_format_width_padding(char *conv_str, char *padding);
static char		*ft_allocate_string(char **str, size_t width, char padding);
static void		ft_space_for_space(char *conv_str, char **str,
					size_t width, size_t len);
static size_t	ft_format_width_space(char *conv_str, char **str,
					size_t width, size_t len);

size_t	ft_format_width(char *conv_str, char **str)
{
	size_t		width;
	char		padding;
	char		*astr;
	size_t		len;

	width = ft_format_width_padding(conv_str, &padding);
	len = ft_strlen(*str);
	if (*str[0] == '\0')
		len += 1;
	width += ft_format_width_space(conv_str, str, width, len);
	if (width >= len)
	{
		astr = ft_allocate_string(str, width, padding);
		if (!astr)
			return (0);
		ft_memset(astr, (char)padding, width);
		if (!(*str[0] == '\0' && (ft_strchr(conv_str, (int) 'c') == NULL))
			&& ft_strchr(conv_str, (int) '-') != NULL)
			ft_memcpy(astr, *str, len);
		else if (!(*str[0] == '\0' && (ft_strchr(conv_str, (int) 'c') == NULL)))
			ft_memcpy(astr + (width - len), *str, len);
		return (free(*str), *str = astr,
			ft_space_for_space(conv_str, str, width, len), width);
	}
	return (ft_space_for_space(conv_str, str, width, len), len);
}

static size_t	ft_format_width_space(char *conv_str, char **str,
	size_t width, size_t len)
{
	size_t	space;

	space = 0;
	if ((ft_strchr(conv_str, (int) '+') != NULL) && (width > len)
		&& (ft_strchr(conv_str, (int) '-') != NULL) && (ft_atoi(*str) > 0))
		space = -1;
	return (space);
}

static void	ft_space_for_space(char *conv_str, char **str,
	size_t width, size_t len)
{
	char	sign[2];

	if ((ft_strchr(conv_str, (int) '+') == NULL)
		&& (ft_strchr(conv_str, (int) ' ') != NULL)
		&& (ft_atoi(*str) >= 0)
		&& ((ft_strchr(conv_str, (int) 'd'))
			|| (ft_strchr(conv_str, (int) 'i')))
		&& (width <= len))
	{
		sign[0] = ' ';
		sign[1] = '\0';
		*str = ad_malloc_cat_prefix_and_free_string(&sign[0], *str);
	}
}

static size_t	ft_format_width_padding(char *conv_str, char *padding)
{
	size_t	j;
	size_t	width;

	*padding = ' ';
	width = 0;
	j = 0;
	while (conv_str[j] != '\0' && conv_str[j] != '.')
	{
		if ((conv_str[j] == '0') && (ft_strchr(conv_str, (int) 's') == NULL)
			&& (ft_strchr(conv_str, (int) '-') == NULL))
			*padding = '0';
		else if (ft_isdigit(conv_str[j]) != 0)
		{
			width = ft_atoi(&conv_str[j]);
			break ;
		}
		j++;
	}
	while (conv_str[j] != '\0')
	{
		if (conv_str[j] == '.')
			*padding = ' ';
		j++;
	}
	return (width);
}

static char	*ft_allocate_string(char **str, size_t width, char padding)
{
	char	*astr;

	astr = (char *)calloc(sizeof(char), (width + 1));
	if (!astr)
	{
		free(*str);
		return (NULL);
	}
	ft_memset(astr, (char)padding, width);
	return (astr);
}
