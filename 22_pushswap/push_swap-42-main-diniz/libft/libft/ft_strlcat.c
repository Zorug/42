/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:07:59 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NAME
//	strlcat — size-bounded string concatenation

// LIBRARY
//	Utility functions from BSD systems (libbsd, -lbsd)

// SYNOPSIS
//	size_t	strlcat(char *dst, const char *src, size_t size);

// DESCRIPTION
//		The strlcat() function copies and concatenates strings. It is designed
//	to be safer, more consistent, and less error prone replacement for strncat.
//	Unlike that, strlcat() takes the full size of the buffer (not just the
//	length) and guarantees to NUL-terminate the result (as long as there is at
//	least one byte free in dst). Note that a byte for the NUL should be
//	included in size. Also note that strlcat() only operates on true “C”
//	strings. This means that for strlcat() both src and dst must be NUL-
//	-terminated.
//		The strlcat() function appends the NUL-terminated string src to the end
//	of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-
//	-terminating the result.

// RETURN VALUES
//		The strlcat() function returns the total length of the string it tried
//	to create. That means the initial length of dst plus the length of src.
//	While this may seem somewhat confusing, it was done to make truncation
//	detection simple.

//		Note, however, that if strlcat() traverses size characters without
//	finding a NUL, the length of the string is considered to be size and the
//	destination string will not be NUL-terminated (since there was no space for
//	the NUL). This keeps strlcat() from running off the end of a string. In
//	practice this should not happen (as it means that either size is incorrect
//	or that dst is not a proper “C” string). The check exists to prevent
//	potential security problems in incorrect code.

// For the inclusion of size_t
#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	pos;

	len_dst = 0;
	len_src = 0;
	while (len_dst < size && dst[len_dst] != '\0')
		len_dst++;
	while (src[len_src] != '\0')
		len_src++;
	if (len_dst == size)
		return (size + len_src);
	pos = 0;
	while (len_dst + pos + 1 < size
		&& src[pos] != '\0')
	{
		dst[len_dst + pos] = src[pos];
		pos++;
	}
	dst[len_dst + pos] = '\0';
	return (len_dst + len_src);
}
