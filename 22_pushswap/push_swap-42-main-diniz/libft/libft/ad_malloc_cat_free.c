/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_malloc_cat_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:59:20 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
//	stdlib.h

static void	add_single_chr(const char *src, char *dest, int *index);

// WARNING: s1 and s2 have to be dynamicly allocated
// (this means, they need to be allocated with malloc previously)
char	*ad_malloc_cat_and_free(char *s1, char *s2)
{
	char	*result;

	result = ad_malloc_cat((char *)s1, s2);
	free(s1);
	free(s2);
	return (result);
}

// WARNING: s2 has to be dynamicly allocated
// (this means, it needs to be allocated with malloc previously)
char	*ad_malloc_cat_prefix_and_free_string(const char *s1, char *s2)
{
	char	*result;

	result = ad_malloc_cat(s1, s2);
	free(s2);
	return (result);
}

char	*ad_malloc_cat(const char *s1, const char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = ft_calloc(sizeof(char), (len1 + len2 + 1));
	if (!result)
		return (NULL);
	i = 0;
	add_single_chr(s1, result, &i);
	add_single_chr(s2, result, &i);
	return (result);
}

static void	add_single_chr(const char *src, char *dest, int *index)
{
	int	j;

	j = 0;
	while (src[j] != '\0')
	{
		dest[*index] = src[j];
		(*index)++;
		j++;
	}
}
