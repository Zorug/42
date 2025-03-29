/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 07:45:38 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Replicates memmove from libc

//NAME
//	memmove - copy memory area
//
//LIBRARY
//	Standard C library (libc, -lc)
//
//SYNOPSIS
//	void *memmove(void dest[.n], const void src[.n], size_t n);
//
//DESCRIPTION
//		The memmove() function copies n bytes from memory area src to memory
//	area dest. The memory areas may overlap: copying takes place as though the
//	bytes in src are first copied into a temporary array that does not overlap
//	src or dest, and the bytes are then copied from the temporary array to
//	dest.

//RETURN VALUE
//	The memmove() function returns a pointer to dest.

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				j;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	j = 0;
	if (src < dest)
	{
		while (j < n)
		{
			j++;
			d[n - j] = s[n - j];
		}
	}
	else if (src > dest)
	{
		while (j < n)
		{
			d[j] = s[j];
			j++;
		}
	}
	return (dest);
}
