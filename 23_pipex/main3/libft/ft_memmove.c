/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:53:16 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/24 21:07:17 by cgross-s         ###   ########.fr       */
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
	unsigned char		*dest_aux;
	const unsigned char	*src_aux;

	dest_aux = dest;
	src_aux = src;
	if (!dest && !src)
		return (NULL);
	if (dest_aux == src_aux)
		return (dest);
	if (dest_aux > src_aux)
	{
		src_aux = src_aux + n - 1;
		dest_aux = dest_aux + n - 1;
		while (n--)
			*dest_aux-- = *src_aux--;
	}
	else
	{
		while (n--)
			*dest_aux++ = *src_aux++;
	}
	return (dest);
}

/*RETURN VALUE
	The memmove() function returns a pointer to dest.*/