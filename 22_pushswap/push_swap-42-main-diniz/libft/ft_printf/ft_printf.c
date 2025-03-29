/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:02:14 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:51:32 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Program name
//		libftprintf.a
//	Prototype
//		int	ft_printf(const char *, ...);
//	Turn in files
//		Makefile, *.h, */*.h, *.c, */*.c
//	Makefile
//		NAME, all, clean, fclean, re
//	External functs.
//		malloc, free, write, va_start, va_arg, va_copy, va_end
//	Libft authorized
//		Yes
//	Description
//		Write a library that contains ft_printf(), a function that will mimic
//	the original printf()

#include "../libft.h"

//	variatic function toolbox
//	Has the macros:
//		va_start - initialize the pointer
//		va_arg   - fetches the next arguments
//		va_end   - resets the pointer and releases variatic pointer resources

static int	is_flag(char chr);
static void	format_converted(
				va_list ptr_args, char *str, int *index, int *count);
static void	format_arg(char *conv_str, int *count, va_list ptr_args);

int	ft_printf(const char *initial_str, ...)
{
	va_list	ptr_args;
	int		i;
	int		count;

	if (!initial_str)
		return (-1);
	i = 0;
	count = 0;
	va_start(ptr_args, initial_str);
	while (initial_str[i] != '\0')
	{
		if (initial_str[i] == '%')
		{
			format_converted(ptr_args, (char *) initial_str, &i, &count);
			if (i == -1)
				return (-1);
			continue ;
		}
		write(1, &initial_str[i], 1);
		i++;
		count++;
	}
	va_end(ptr_args);
	return (count);
}

static void	format_converted(
			va_list ptr_args, char *str, int *index, int *count)
{
	int		j;
	char	*conversion_str;

	j = *index;
	conversion_str = NULL;
	while (str[j] != '\0')
	{
		j++;
		if (is_flag(str[j]) == 1)
		{
			conversion_str = ft_substr(str, *index, (j - *index + 1));
			if (conversion_str == NULL)
			{
				*index = -1;
				return ;
			}
			format_arg(conversion_str, count, ptr_args);
			*index = j + 1;
			break ;
		}
	}
	if (str[j] == '\0')
		*index = -1;
	free(conversion_str);
	return ;
}

static void	format_arg(char *conv_str, int *count, va_list ptr_args)
{
	char	conversion_format;

	conversion_format = conv_str[ft_strlen(conv_str) - 1];
	if (conversion_format == '%')
	{
		ft_putchar_fd('%', 1);
		*count += 1;
	}
	else if (conversion_format == 'c')
		printf_character(conv_str, count, ptr_args);
	else if (conversion_format == 's')
		printf_string(conv_str, count, ptr_args);
	else if (conversion_format == 'i' || conversion_format == 'd')
		printf_integer(conv_str, count, ptr_args);
	else if (conversion_format == 'u')
		printf_unsigned_d(conv_str, count, ptr_args);
	else if (conversion_format == 'x')
		printf_hex_lower(conv_str, count, ptr_args);
	else if (conversion_format == 'X')
		printf_hex_upper(conv_str, count, ptr_args);
	else if (conversion_format == 'p')
		printf_pointer(conv_str, count, ptr_args);
}

static int	is_flag(char chr)
{
	if (ft_strchr("cspdiuxX%", chr) == NULL)
		return (0);
	return (1);
}
