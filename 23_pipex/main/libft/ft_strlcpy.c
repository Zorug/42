/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:53:25 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:53:27 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strlcpy() copy and concatenate  strings respectively. 
Strlcpy() take the full size of the buffer (not just the length) 
and  guarantee to NUL-terminate the result (as long as size is 
larger than 0). 
Note that a byte for the NUL should be included in size. 
For strlcpy() src must be NUL-terminated

The strlcpy() function copies up to size - 1 characters from the 
NUL-terminated string src to dst, NUL-terminating the result.*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)/*
sizeof(dest)*/
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*The strlcpy() function return the total length of the string 
they tried to create. 
For strlcpy() that means the length of src. 
While this may seem somewhat confusing, it was done to make 
truncation detection simple.*/