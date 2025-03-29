/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_trim_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:01:34 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// size_t, ft_strlen(), ft_strchr()

static int	ad_keep_char(char c, char const *set);

// Removes a set of characters from a string
char	*ad_rm_chr(char const *str, char const *set)
{
	size_t	i;
	size_t	j;
	char	*cut;

	if (!str || !set)
		return (NULL);
	cut = (char *) ft_calloc(sizeof(char), (ft_strlen(str) + 1));
	if (!cut)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (ad_keep_char(str[j], set))
		{
			cut[i] = str[j];
			i++;
		}
		j++;
	}
	cut[i] = '\0';
	return (cut);
}

static int	ad_keep_char(char c, char const *set)
{
	size_t	k;

	k = 0;
	while (set[k] != '\0')
	{
		if (c == set[k])
			return (0);
		k++;
	}
	return (1);
}
