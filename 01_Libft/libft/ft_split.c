/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:58:54 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:59:32 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_words(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			words++;
			while (str[i] != c && str[i])
				i++;
			if (str[i] == '\0')
				return (words);
		}
		i++;
	}
	return (words);
}

int	word_length(char const *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	*allocate_word(char const *str, char c, int *pos)
{
	char	*word;
	int		len;
	int		j;

	while (str[*pos] && str[*pos] == c)
		(*pos)++;
	len = word_length(str, c, *pos);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = str[(*pos)++];
		j++;
	}
	word[len] = '\0';
	return (word);
}

void	freeit(int i, char **splitted)
{
	while (i > 0)
		free(splitted[--i]);
	free(splitted);
}

char	**ft_split(char const *str, char c)
{
	char	**splitted;
	int		i;
	int		n_words;
	int		pos;

	if (!str)
		return (NULL);
	i = -1;
	pos = 0;
	n_words = count_words(str, c);
	splitted = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!splitted)
		return (NULL);
	while (++i < n_words)
	{
		splitted[i] = allocate_word(str, c, &pos);
		if (!splitted[i])
		{
			freeit (i, splitted);
			return (NULL);
		}
	}
	splitted[i] = NULL;
	return (splitted);
}

// Free previously allocated strings on failure