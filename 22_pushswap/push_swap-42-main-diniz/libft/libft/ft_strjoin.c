/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:56:33 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_strjoin
//	Prototype
//		char *ft_strjoin(char const *s1, char const *s2);
//	Turn in files
//	-
//	Parameters
//		s1: The prefix string.
//		s2: The suffix string.
//	Return value
//		The new string.
//		NULL if the allocation fails.
//	External functs.
//		malloc
//	Description
//		Allocates (with malloc) and returns a new string, which is the result
//	of the concatenation of ’s1’ and ’s2’.

#include "../libft.h"
// for malloc(), ft_strlen() and size_t
// size_t	ft_strlen(const char *s)

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;
	size_t	pos;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len_s1 + 1);
	pos = 0;
	while (s2[pos] != '\0')
	{
		new[len_s1 + pos] = s2[pos];
		pos++;
	}
	new[len_s1 + pos] = '\0';
	return (new);
}
