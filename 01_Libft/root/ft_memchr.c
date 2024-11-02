/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:56:53 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:56:54 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  memchr()  function  scans the initial n bytes of 
the memory area pointed to by s for the first instance 
of c.  Both c and the bytes of the memory area pointed 
to by s are interpreted as unsigned char.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/* The memchr() and memrchr() functions return a pointer to 
the matching byte or NULL if the character does not  occur  
in  the  given  memory area.*/