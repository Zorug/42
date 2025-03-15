/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:51:16 by cgross-s          #+#    #+#             */
/*   Updated: 2024/12/20 17:51:17 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include <unistd.h>
# include <stdarg.h>
//# include <stdio.h>
# include "libft/libft.h"
//# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *format, ...);

int		ft_putchar(int c);
int		ft_putstr(char *str);

int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);

int		ft_putnbr_base(unsigned long n, char *base_to);

#endif