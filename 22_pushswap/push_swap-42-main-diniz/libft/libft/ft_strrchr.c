/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:30:02 by abessa-m          #+#    #+#             */
/*   Updated: 2024/10/29 17:59:04 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reimplements strrchr() from the Standard C library

// SYNOPSIS
//	char *strrchr(const char *s, int c);

// DESCRIPTION
//		The strrchr() function returns a pointer to the last occurrence of the
//	character c in the string s.
//
//		Here "character" means "byte"; these functions do not work with wide or
//	multibyte characters.

// RETURN VALUE
//		The strchr() and strrchr() functions return a pointer to the matched
//	character or NULL if the character is not found.  The terminating null byte
//	is considered part of the string, so that if c is specified as '\0', these
//	functions return a pointer to the terminator.

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	j;
	char			*ptr;

	ptr = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == (char) c)
			ptr = (char *) &s[j];
		j++;
	}
	if (s[j] == (char) c)
		ptr = (char *) &s[j];
	return (ptr);
}
// This function was written on mobile using Termux!