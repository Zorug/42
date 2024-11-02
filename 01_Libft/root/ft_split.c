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
	int		count;

	i = 0;
	count = 0;/*número de palavras*/
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i]) /*caso haja mais de um seguido*/
				i++;
			if (s[i] == '\0')
				break;
			else
				count++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	//size_t	words; /*conta palavras*/
	//size_t	slen;
	int		n_words;

	i = 0;
	n_words = count_words(s, c);

	splitted = (char **)malloc(sizeof(char *) * n_words);
	while (splitted[i])
	{
		splitted[i] = malloc(sizeof(char) * (n + 1))
		i++;
	}
	return (splitted);
}