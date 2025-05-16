/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:58:54 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/27 08:50:00 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countword(char const *str, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

/*static char	*ft_strndup(const char *s, size_t len)
{
	char		*dup;
	size_t		i;

	i = 0;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}*/

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	words;
	size_t	j;
	size_t	wordlen;
	char	**array;

	index = 0;
	j = 0;
	words = ft_countword(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (!s || !(array))
		return (NULL);
	while (index < words)
	{
		while (s[j] == c)
			j++;
		wordlen = 0;
		while (s[j + wordlen] != '\0' && s[j + wordlen] != c)
			wordlen++;
		array[index] = ft_strndup(&s[j], wordlen);
		j = j + wordlen;
		index++;
	}
	array[index] = NULL;
	return (array);
}
