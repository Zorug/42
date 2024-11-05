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

int	count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (words);
		}
		i++;
	}
	return (words);
}

void	create_word(char *word, char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i + j] != c && s[i + j] != '\0')
	{
		word[j] = s[i + j];
		j++;
	}
	word[j] = '\0';
}

char	*allocate(char const *s, char c, int *pos)
{
	char	*word;
	int		i;

	i = *pos;
	while (s[*pos] != '\0')
	{
		if (s[*pos] != c)
		{
			while (s[*pos] != '\0' && s[*pos] != c)
				*pos += 1;
			word = (char *)malloc(sizeof(char) * (*pos + 1));
			if (!word)
				return (NULL);
			break ;
		}
		*pos += 1;
	}
	create_word(word, s, c, i);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**splitted;
	int			i;
	int			n_words;
	int			pos;

	if (!s)
		return (NULL);
	i = 0;
	pos = 0;
	n_words = count_words(s, c);
	splitted = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!splitted)
		return (NULL);
	while (i < n_words)
	{
		splitted[i] = allocate(s, c, &pos);
		if (!splitted[i])
		{
			free(splitted);
			return (NULL);
		}
		i++;
	}
	return (splitted);
}
