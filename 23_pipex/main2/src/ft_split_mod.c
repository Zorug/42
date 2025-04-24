/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:05:05 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/22 23:26:23 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

/* Extrair a próxima palavra da string s, que pode ser:
- uma palavra simples (ls)
- uma sequência entre aspas ("hello world")
- ou contendo escapes (a\ b) */

char	*get_string(const char *s)
{
	int	k;
	int	wordlen;

	wordlen = 0;
	while (s[wordlen] != '\0' && s[wordlen] != ' ' && s[wordlen] != '\n')
	{
		if (s[wordlen] == '\"' || s[wordlen] == '\'')
		{
			k = 1;
			while (s[wordlen + k] != '\0' && s[wordlen + k] != s[wordlen])
			{
				if (s[wordlen + k] == '\\' && s[wordlen + k + 1] != '\0')
					k++;
				k++;
			}
			wordlen += k + 1;
		}
		else
			wordlen++;
	}
	return (ft_strndup(s, wordlen));
}

/*	"'banana'"      → "banana" → Remove aspas simples (')
	"\"hello world\"" → "hello world" → Remove aspas duplas (")
	" teste "        → "teste" → Remove espaços no início/fim 
	(quando combinam) */

void	clean_words(int words, char **array)
/*
words: número de palavras no array
array: vetor de strings (ex: { "\"banana\"", "'abc'", "normal", NULL })
*/
{
	int	i;
	int	len;

	i = 0;
	while (i < words)
	{
		len = ft_strlen(array[i]);
		if (len >= 2 && (array[i][0] == '\"' || array[i][0] == '\''
			|| array[i][0] == ' ') && ((array[i][len - 1] == array[i][0])
			|| array[i][0] == '\0'))
		{
			ft_memmove(array[i], array[i] + 1, len - 2);
			array[i][len - 2] = '\0';
		}
		i++;
	}
}

/* Diferente da ft_split() normal, ela:
    - Respeita aspas (" " ou ' ')
    - Lida com espaços dentro das aspas
    - Remove símbolos de escape (\)
    - Remove as aspas externas */

char	**ft_split_mod(char *s)
{
	size_t	index;
	size_t	words;
	char	**array;
	char	**new_array;

	index = 0;
	words = ft_countword(s);
	array = malloc((words + 1) * sizeof(char *));
	if (!s || !array)
		return (NULL);
	while (index < words)
	{
		while (*s == ' ' || *s == '\n')
			s++;
		array[index] = get_string(s);
		s += ft_strlen(array[index]);
		index++;
	}
	array[index] = NULL;
	clean_words(words, array);
	new_array = remove_scape_symbol(array);
	ft_free_array(array);
	return (new_array);
}
