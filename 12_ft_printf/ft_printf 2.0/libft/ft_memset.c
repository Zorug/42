/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:51:53 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:51:54 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
    The  memset()  function  fills  the  first  n  bytes 
    of the memory area
    pointed to by s with the constant byte c.*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*us;

	i = 0;
	us = (unsigned char *)s;
	while (i < n)
	{
		us[i] = c;
		i++;
	}
	s = us;
	return (s);
}

/*RETURN VALUE
The memset() function returns a pointer to the memory area s.
*/