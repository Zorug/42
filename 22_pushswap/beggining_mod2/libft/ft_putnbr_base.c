/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:51:29 by cgross-s          #+#    #+#             */
/*   Updated: 2024/12/20 17:51:31 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "libft.h"

int	ft_putnbr_base(unsigned long n, char *base_to)
{
	int				count;
	unsigned int	base_len;

	base_len = ft_strlen(base_to);
	count = 0;
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, base_to);
	count += ft_putchar(base_to[n % base_len]);
	return (count);
}
