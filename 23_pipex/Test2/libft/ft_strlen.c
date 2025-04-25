/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:50:58 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:50:59 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
	   The  strlen() function calculates the length of the string pointed to
	   by s, excluding the terminating null byte ('\0').*/
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*RETURN VALUE
	   The strlen() function returns the  number  of  bytes  in  the  string
	   pointed to by s.*/