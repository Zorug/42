/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:57:40 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Emulates memcmp

// NAME
//	memcmp - compare memory areas

// SYNOPSIS
//	int memcmp(const void *s1, const void *s2, size_t n);

// DESCRIPTION
//	The memcmp() function compares the first n bytes (each interpreted as
//	unsigned char) of the memory areas s1 and s2.

// RETURN VALUE
//		The memcmp() function returns an integer less than, equal to, or
//	greater than zero if the first n bytes of s1 is found, respectively, to be
//	less than, to match, or be greater than the first n bytes of s2.
//		For a nonzero return value, the sign is determined by the sign of the
//	difference between the first pair of bytes (interpreted as unsigned char)
//	that differ in s1 and s2.
//		If n is zero, the return value is zero.	

// For the size_t
#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			j;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	j = 0;
	while (j < n)
	{
		if (ss1[j] != ss2[j])
			return (ss1[j] - ss2[j]);
		j++;
	}
	return (0);
}
