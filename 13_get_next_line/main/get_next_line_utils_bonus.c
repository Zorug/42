/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:58:33 by cgross-s          #+#    #+#             */
/*   Updated: 2025/01/12 20:03:45 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* The  strchr()  function  returns a pointer to the FIRST 
occurrence of the character c in the string s.
Here  "character" means "byte"; these functions do not work 
with wide or multibyte characters.*/
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	c = (unsigned char)c;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/*DESCRIPTION
	   The  strlen() function calculates the length of the string pointed to
	   by s, excluding the terminating null byte ('\0').*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/
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
