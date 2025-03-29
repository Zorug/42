/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:52:58 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//		Function name
//	ft_strmapi
//		Prototype
//	char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
//		Turn in files
//	-
//		Parameters
//	s: The string on which to iterate.
//	f: The function to apply to each character.
//		Return value
//	The string created from the successive applications of ’f’.
//	Returns NULL if the allocation fails.
//		External functs.
//	malloc
//		Description
//	Applies the function f to each character of the string s, passing its index
//	as the first argument and the character itself as the second. A new string
//	is created (using malloc(3)) to collect the results from the successive
//	applications of f.

#include "../libft.h"
// ft_strlen(), malloc(), size_t

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	pos;
	char			*new;

	if (!s || !f)
		return (NULL);
	new = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	pos = 0;
	while (s[pos] != '\0')
	{
		new[pos] = f(pos, s[pos]);
		pos++;
	}
	new[pos] = '\0';
	return (new);
}
