/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:27:08 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Emulates strchr from libc

// DESCRIPTION
//		The strchr() function returns a pointer to the first occurrence of
//	the character c in the string s.
//
//		Here "character" means "byte"; these functions do not work with wide
//	or multibyte characters.

// RETURN VALUE
//		The strchr() functiom returns a pointer to the matched character or
//	NULL if the character is not found. The terminating null byte is
//	considered part of the string, so that if c is specified as '\0', this
//	function returns a pointer to the terminator.

#include "../libft.h"
//	NULL

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

//	NOTE:
//		No NULL check in strchr()
//	if (!s)
//		return (NULL);
