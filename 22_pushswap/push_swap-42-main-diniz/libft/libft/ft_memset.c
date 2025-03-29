/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:55:39 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Emulates memset

/*
 DESCRIPTION
	The  memset() function fills the first n bytes
	of the memory area pointed to by s with the constant byte c.

 RETURN VALUE
	The memset() function returns a pointer to the memory area s.
*/

#include "../libft.h"
// for size_t

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			j;
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	j = 0;
	while (j < n)
	{
		ptr[j] = (unsigned char) c;
		j++;
	}
	return (s);
}
/* NOTE:
	unsigned int *ptr
changed to
	unsigned char	*ptr;
in order to avoid the overflow from writing 4 bytes intead of one!
*/