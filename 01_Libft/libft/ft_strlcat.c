/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:53:38 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:53:39 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*strlcat() functions copy and concatenate strings respectively. 
strlcat() take the full size of the buffer (not just the length) and 
guarantee to NUL-terminate the result (as long as size is 
larger than 0 or, in the case of strlcat(), as long as there is 
at least one byte free in dst). Note that a byte for the NUL 
should be included in size. 
For strlcat() both src and dst must be NUL-terminated.

The strlcat() function appends the NUL-terminated string src to 
the end of dst. 
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating 
the result. */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j) < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*The strlcat() functions return the total length of the string 
they tried to create. 
For strlcat() that means the initial length of dst plus the 
length of src. 
While this may seem somewhat confusing, it was done to make 
truncation detection simple.

Note, however, that if strlcat() traverses size characters 
without finding a NUL, the length of the string is considered 
to be size and the destination string will not be NUL-terminated 
(since there was no space for the NUL). 
This keeps strlcat() from running off the end of a string. 
In practice this should not happen (as it means that either size 
is incorrect or that dst is not a proper ''C'' string). 
The check exists to prevent potential security problems in 
incorrect code.*/