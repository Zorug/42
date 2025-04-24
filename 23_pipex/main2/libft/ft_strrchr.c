/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:56:00 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:56:01 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strrchr() function returns a pointer to the LAST 
occurrence  of the character c in the string s.
Here  "character" means "byte"; these functions do not 
work with wide or multibyte characters.*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	c = (unsigned char)c;
	while (*s)
	{
		if (*s == c)
			ptr = (char *)s;
		s++;
	}
	if (*s == c)
		ptr = (char *)s;
	return (ptr);
}

/* The strchr() and strrchr() functions return a pointer 
to the  matched character  or  NULL  if  the character is 
not found.  The terminating null byte is considered part 
of the string, so that if c is specified as '\0', these 
functions return a pointer to the terminator. */