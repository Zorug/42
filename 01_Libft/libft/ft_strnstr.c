/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:57:17 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:57:18 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strnstr() function locates the first occurrence of 
the null-terminated string s2 in the string s1, where not 
more than n characters are searched.  Characters that appear 
after a `\0' character are not searched.  Since the strnstr() 
function is a FreeBSD specific API, it should only be used when 
portability is not a concern.*/
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && i + j < n)
			{
				if (s2[j + 1] == '\0')
					return ((char *)s1 + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

/* If s2 is an empty string, s1 is returned; 
if s2 occurs nowhere in s1, NULL is returned; 
otherwise a pointer to the first character of 
the first occurrence of s2 is returned. */