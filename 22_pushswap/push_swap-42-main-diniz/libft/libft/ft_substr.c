/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:27:48 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_substr
//	Prototype
//		char	*ft_substr(char const *s, unsigned int start, size_t len);
//	Turn in files
//		-
//	Parameters
//		s: The string from which to create the substring.
//		start: The start index of the substring in the
//		string ’s’.
//		len: The maximum length of the substring.
//	Return value
//		The substring.
//		NULL if the allocation fails.
//	External functs.
//		malloc
//	Description
//		Allocates (with malloc(3)) and returns a substring
//		from the string ’s’.
//		The substring begins at index ’start’ and is of
//		maximum size ’len’.

#include "../libft.h"
// NULL, ft_strlcpy, 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	new = (char *) malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s[start], len + 1);
	return (new);
}
