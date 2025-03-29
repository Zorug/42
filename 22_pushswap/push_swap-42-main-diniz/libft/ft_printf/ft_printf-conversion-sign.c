/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-conversion-sign.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 07:31:14 by abessa-m          #+#    #+#             */
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

static void	ft_slide_sign_into_digit(char **str);
static char	ft_determine_sign(char *conv_str);
static char	*ft_replaces_minus_sign(char **str);

// char	*ft_strchr(const char *s, int c)
// char	*ft_strtrim(char const *s1, char const *set)
char	ft_format_place_sign(char *conv_str, char **str)
{
	char	sign[2];

	sign[0] = 'W';
	sign[1] = '\0';
	if (!ft_replaces_minus_sign(str))
		return ('W');
	if (!*str)
		return (sign[0]);
	sign[0] = ft_determine_sign(conv_str);
	if (sign[0] == 'W')
		return (ft_slide_sign_into_digit(str), sign[0]);
	if (str[0][0] == '0')
		*str = ad_malloc_cat_prefix_and_free_string(&sign[0], *str);
	else if (str[0][0] == '-')
		ft_slide_sign_into_digit(str);
	else if (sign[0] == '+')
	{
		if (ft_isdigit(str[0][0]))
			*str = ad_malloc_cat_prefix_and_free_string(&sign[0], *str);
		str[0][0] = '+';
		ft_slide_sign_into_digit(str);
	}
	else
		*str = ad_malloc_cat_prefix_and_free_string(&sign[0], *str);
	return (sign[0]);
}

static char	*ft_replaces_minus_sign(char **str)
{
	char	*ptr;
	char	*new_str;
	char	*sign_str;

	ptr = ft_strchr(*str, (int) '-');
	if (ptr != NULL)
	{
		sign_str = "-";
		new_str = ad_rm_chr(*str, sign_str);
		if (!new_str)
			return (NULL);
		free(*str);
		*str = ad_malloc_cat_prefix_and_free_string(sign_str, new_str);
	}
	return (*str);
}

static char	ft_determine_sign(char *conv_str)
{
	char	sign;
	int		j;

	sign = 'W';
	j = 0;
	while (conv_str[j] != '\0' && conv_str[j] != '.'
		&& (conv_str[j] < '1' || conv_str[j] > '9'))
	{
		if (conv_str[j] == ' ' && sign != '+')
			sign = 'W';
		if (conv_str[j] == '+')
			sign = '+';
		j++;
	}
	return (sign);
}

static void	ft_slide_sign_into_digit(char **str)
{
	int		j;
	char	temp;

	if (!str)
		return ;
	if (str[0][0] == '\0')
		return ;
	if (ft_isalnum(str[0][0]) != 0)
		return ;
	j = 0;
	while (str[0][j + 1] == ' ')
	{
		temp = str[0][j];
		str[0][j] = str[0][j + 1];
		str[0][j + 1] = temp;
		j++;
	}
}

// the maximum number of characters to be printed
// char	*ft_strchr(const char *s, int c)
// size_t strlcpy(char *dst, const char *src, size_t size);
// int ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_format_precision_string(char *conv_str, char **str)
{
	char	*ptr_dot;
	char	*new_str;
	long	precision;

	if (*str[0] == '\0')
		return ;
	ptr_dot = ft_strchr(conv_str, '.');
	if (ptr_dot == NULL)
		return ;
	ptr_dot++;
	precision = ft_atoi(ptr_dot);
	if (ft_memcmp("(null)", *str, 7) == 0)
	{
		if (precision < 6)
			precision = 0;
	}
	if (precision < 0)
		precision = 0;
	new_str = (char *)calloc(sizeof(char), (precision + 1));
	if (!new_str)
		return ;
	ft_strlcpy(new_str, *str, precision + 1);
	free(*str);
	*str = new_str;
}
