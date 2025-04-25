/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:59:46 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/24 21:36:01 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  strchr()  function  returns a pointer to the FIRST 
occurrence of the character c in the string s.
Here  "character" means "byte"; these functions do not work 
with wide or multibyte characters.*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	a;

	a = c;
	i = 0;
	while (s[i] != a && s[i])
		i++;
	if (a == s[i])
		return ((char *)(s + i));
	return (NULL);
}

/* The strchr() and strrchr() functions return a pointer 
to the  matched character  or  NULL  if  the character is 
not found.  The terminating null byte is considered part 
of the string, so that if c is specified as '\0', these 
functions return a pointer to the terminator. */