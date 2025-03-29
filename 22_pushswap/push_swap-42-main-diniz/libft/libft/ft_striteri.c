/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:26:06 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_striteri
//	Prototype
//		void ft_striteri(char *s, void (*f)(unsigned int, char*));
//	Turn in files
//		-
//	Parameters
//		s: The string on which to iterate.
//		f: The function to apply to each character.
//	External functs.
//		None
//	Return value
//		None
//	Description
//		Applies the function ’f’ on each character of the string passed as
//	argument, passing its index as first argument. Each character is passed by
//	address to ’f’ to be modified if necessary.

#include "../libft.h"
// NULL

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	if (s == NULL || f == NULL)
		return ;
	index = 0;
	while (s[index] != '\0')
	{
		f(index, &s[index]);
		index++;
	}
}
