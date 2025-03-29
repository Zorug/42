/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:09:15 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reimplementation of strncmp from libc

//	NAME
//		strncmp - compare two strings

//	LIBRARY
//		Standard C library (libc, -lc)

//	SYNOPSIS
//		#include <string.h>
//		int strncmp(const char s1[.n], const char s2[.n], size_t n);

//	DESCRIPTION
//		The strcmp() function compares the two strings s1 and s2. The
//	comparison is done using unsigned characters.
//
//		strcmp() returns an integer indicating the result of the comparison,
//	as follows:
//		• 0, if the s1 and s2 are equal;
//		• a negative value if s1 is less than s2;
//		• a positive value if s1 is greater than s2.
//		The strncmp() function is similar, except it compares only the first
//	(at most) n bytes of s1 and s2.

//	RETURN VALUE
//		The strcmp() and strncmp() functions return an integer less than,
//	equal to, or greater than zero if s1 (or the first n bytes thereof) is
//	found, respectively, to be less than, to match, or be greater than s2.

#include "../libft.h"
// for the size_t definition

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if ((s1[pos] != s2[pos]) || (s1[pos] == '\0'))
			return ((unsigned char) s1[pos] - (unsigned char) s2[pos]);
		pos++;
	}
	return (0);
}
