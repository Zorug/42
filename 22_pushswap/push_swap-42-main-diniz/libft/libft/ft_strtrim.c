/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:55:15 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function NAME
//		ft_strtrim
//	Prototype
//		char *ft_strtrim(char const *s1, char const *set);
//	Turn in files
//		-
//	Parameters
//		s1: The string to be trimmed.
//		set: The reference set of characters to trim.
//	Return value
//		The trimmed string.
//		NULL if the allocation fails.
//	External functions
//		malloc
//	Description
//		Allocates (with malloc(3)) and returns a copy of ’s1’ with the
//	characters specified in ’set’ removed from the beginning and the end of the
//	string.

#include "../libft.h"
// size_t, ft_strlen()

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, len + 1);
	return (result);
}
