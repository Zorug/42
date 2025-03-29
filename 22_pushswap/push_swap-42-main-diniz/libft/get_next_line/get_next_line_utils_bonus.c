/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:31:26 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 17:44:22 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		j;

	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == (char) c)
			return ((char *) &s[j]);
		j++;
	}
	if ((s[j] == '\0') && ((char) c == '\0'))
		return ((char *) &s[j]);
	else
		return (NULL);
}

// s1 freed
char	*gnl_strjoin(char *s1, char const *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;
	size_t	pos;
	size_t	len;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new)
		return (NULL);
	len = -1;
	while (++len < len_s1)
		new[len] = s1[len];
	pos = -1;
	while (s2[++pos] != '\0')
		new[len_s1 + pos] = s2[pos];
	new[len_s1 + pos] = '\0';
	free(s1);
	return (new);
}

/*
size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
		j++;
	return (j);
}
*/

/*
char	*ft_strdup(const char *s)
{
	size_t		len_str;
	size_t		j;
	char		*dup;

	len_str = ft_strlen(s);
	j = 0;
	dup = (char *) malloc(sizeof(char) * (len_str + 1));
	if (!dup)
		return (NULL);
	while (j < len_str + 1)
	{
		dup[j] = s[j];
		j++;
	}
	return (dup);
}
*/