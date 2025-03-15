/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:58:28 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:58:29 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/
#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_string[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_string[i + j] = s2[j];
	free(s1);
	new_string[i + j] = '\0';
	return (new_string);
}

/*
The new string.
NULL if the allocation fails.
*/