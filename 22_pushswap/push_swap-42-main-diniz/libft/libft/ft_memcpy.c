/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:24:41 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Emulates memcpy(3)

// DESCRIPTION
//	Copies n bytes from memory area src to memory area dest.
//	The memory areas must not overlap.
// RETURN VALUE
//	The memcpy() function returns a pointer to dest.

#include "../libft.h"
// for size_t, NULL

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				j;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	j = 0;
	while (j < n)
	{
		d[j] = s[j];
		j++;
	}
	return (dest);
}
