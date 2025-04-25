/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:58:01 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/24 21:35:05 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The  strdup()  function  returns a pointer to a new string which is a
duplicate of the string s.  Memory for the  new  string  is  obtained
with malloc(3), and can be freed with free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
On success, the strdup() function returns a pointer to the duplicated
string.  It returns NULL if insufficient memory was available,  with
errno set to indicate the cause of the error.
*/