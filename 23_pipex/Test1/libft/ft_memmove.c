/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:53:16 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:53:17 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
The memmove() function copies n bytes from memory area 
src to memory area dest. 
The memory areas may overlap: copying takes place  as  
though  the bytes  in src are first copied into a 
temporary array that does not overlap src or dest, and 
the bytes are then copied from the temporary array to 
dest.*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s < d)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			d[i] = s[i];
	}
	return (dest);
}

/*RETURN VALUE
	The memmove() function returns a pointer to dest.*/