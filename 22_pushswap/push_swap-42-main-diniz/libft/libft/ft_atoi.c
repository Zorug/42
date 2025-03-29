/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 05:22:24 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 19:39:27 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Reimplements atoi from libc

//NAME
//	atoi - converts a string to an integer

//	LIBRARY
//		Standard C library (libc, -lc)

//	SYNOPSIS
//		#include <stdlib.h>
//		int atoi(const char *nptr);

//	DESCRIPTION
//		The  atoi() function converts the initial portion of the string pointed
//	to by nptr to int.  The behavior is the same as strtol(nptr, NULL, 10);
//	except that atoi() does not detect errors.
//
//		The string may begin with an arbitrary amount of white space (as
//	determined by isspace(3)) followed by a single optional '+' or '-' sign.
//
//	If there were no digits  at  all, returns 0.

//	RETURN VALUE
//		The converted value or 0 on error.

//	NOTE what isspace() accounts for
//	isspace()
//		checks for white-space characters.  In the "C" and "POSIX" locales,
//	these are: space, form-feed ('\f'), newline ('\n'), carriage return ('\r'),
//	horizontal tab ('\t'),  and vertical tab ('\v').

#include "../libft.h"
//	for the size_t, ft_isdigit

int	ft_atoi(const char *nptr)
{
	int		nbr;
	int		sign;
	size_t	j;

	j = 0;
	while (nptr[j] == 32
		|| (nptr[j] >= 9 && nptr[j] <= 13))
		j++;
	sign = 1;
	if (nptr[j] == '+' || nptr[j] == '-')
	{
		if (nptr[j] == '-')
			sign = -1;
		j++;
	}
	nbr = 0;
	while (ft_isdigit(nptr[j]))
	{
		nbr = (10 * nbr) + (nptr[j] - '0');
		j++;
	}
	nbr *= sign;
	return (nbr);
}

//	NOTE:
//		No NULL check in atoi()
//	if (nptr == NULL)
//		return (0);
