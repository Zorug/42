/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:54:02 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	NAME
//		strnstr — locate a substring in a string

//	LIBRARY
//		Utility functions from BSD systems (libbsd, -lbsd)

//	SYNOPSIS
//		#include <string.h>
//		char	*strnstr(const char *big, const char *little, size_t len);

//	DESCRIPTION
//		The strnstr() function locates the first occurrence of the null-
//	-terminated string little in the string big, where not more than len
//	characters are searched. Characters that appear after a ‘\0’ character are
//	not searched. Since the strnstr() function is a FreeBSD specific API, it
//	should only be used when portability is not a concern.

//	RETURN VALUES
//		If little is an empty string, big is returned; if little occurs
//	nowhere in big, NULL is returned; otherwise a pointer to the first
//	character of the first occurrence of little is returned.

//	EXAMPLES
//		The following sets the pointer ptr to NULL, because only the first 4
//	characters of largestring are searched:
//
//			const char *largestring = "Foo Bar Baz";
//			const char *smallstring = "Bar";
//			char *ptr;
//
//			ptr = strnstr(largestring, smallstring, 4);

#include "../libft.h"
// size_t, ft_strlen(), NULL

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	pos;
	size_t	j;
	size_t	len_little;

	if (little[0] == '\0')
		return ((char *) big);
	len_little = ft_strlen(little);
	pos = 0;
	while ((big[pos] != '\0') && (pos + len_little <= len))
	{
		j = 0;
		while (little[j] != '\0')
		{
			if (little[j] != big[pos + j])
				break ;
			j++;
			if (little[j] == '\0')
				return ((char *) &big[pos]);
		}
		pos++;
	}
	return (NULL);
}

//	NOTE:
//		No NULL check in strnstr()
//	if (!big || !little)
//		return (NULL);
