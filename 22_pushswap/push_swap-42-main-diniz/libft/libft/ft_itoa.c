/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:14:26 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_itoa
//	Prototype
//		char *ft_itoa(int n);
//	Turn in files
//		-
//	Parameters
//		n: the integer to convert.
//	Return value
//		The string representing the integer.
//		NULL if the allocation fails.
//	External functs.
//		malloc
//	Description
//		Allocates (with malloc(3)) and returns a string representing the
//	integer received as an argument.
//		Negative numbers must be handled.

#include "../libft.h"
//	malloc(), 

static int	len_of_int(int n);

char	*ft_itoa(int n)
{
	long int		nbr;
	int				len;
	char			*str;
	int				j;

	len = len_of_int(n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	j = 0;
	nbr = n;
	if (n < 0)
		nbr = -nbr;
	while (j < len)
	{
		str[len - j - 1] = '0' + nbr % 10;
		nbr /= 10;
		j++;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

static int	len_of_int(int n)
{
	int			len;
	long int	nbr;

	nbr = n;
	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
