/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:58:12 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:58:13 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’
*/
#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	size_t	actual_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	actual_len = str_len - start;
	if (actual_len > len)
		actual_len = len;
	substr = malloc((actual_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, str + start, actual_len + 1);
	return (substr);
}

/*
The substring.
NULL if the allocation fails.
*/
/*
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.
*/