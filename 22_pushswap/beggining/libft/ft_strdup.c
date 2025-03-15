/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:58:01 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:58:02 by cgross-s         ###   ########.fr       */
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
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
On success, the strdup() function returns a pointer to the duplicated
string.  It returns NULL if insufficient memory was available,  with
errno set to indicate the cause of the error.
*/