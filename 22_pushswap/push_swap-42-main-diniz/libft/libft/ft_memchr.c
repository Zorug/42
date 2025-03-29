/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:04:35 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reimplements memchr from libc

//NAME
//	memchr - scan memory for a character

//LIBRARY
//	Standard C library (libc, -lc)

//SYNOPSIS
//	void *memchr(const void s[.n], int c, size_t n);

//DESCRIPTION
//		The memchr() function scans the initial n bytes of the memory area
//	pointed to by s for the first instance of c. Both c and the bytes of the
//	memory area pointed to by s are interpreted as unsigned char.

//RETURN VALUE
//		The memchr() function returns a pointer to the matching	byte or NULL
//	if the character does not occur in the given memory area.

// include the definition of size_t
#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*source;
	size_t				j;

	source = (const unsigned char *) s;
	j = 0;
	while (j < n)
	{
		if (source[j] == (unsigned char) c)
			return ((void *) &source[j]);
		j++;
	}
	return ((void *) 0);
}
