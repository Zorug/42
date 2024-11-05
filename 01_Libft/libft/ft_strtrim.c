/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:58:45 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:58:46 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.*/
#include "libft.h"

int	find_in_set(char needle, char const *haystack)
{
	int	i;

	i = 0;
	while (haystack[i])
	{
		if (needle == haystack[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	pos_start;
	size_t	pos_end;
	size_t	i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	pos_start = 0;
	pos_end = ft_strlen(s1);
	while (s1[pos_start] && find_in_set(s1[pos_start], set) != 0)
		pos_start++;
	while (pos_end > pos_start && find_in_set(s1[pos_end - 1], set) != 0)
		pos_end--;
	ptr = malloc((pos_end - pos_start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] && i < pos_end)
		if (i >= pos_start)
			ptr[++j] = s1[i];
	ptr[++j] = '\0';
	return (ptr);
}

/*The trimmed string.
NULL if the allocation fails.*/