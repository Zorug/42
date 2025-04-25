/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:55:04 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:55:05 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
These functions convert lowercase letters to uppercase,
and vice versa.

If  c  is a lowercase letter, toupper() returns its
uppercase equivalent, if an uppercase representation
exists in the current locale.   Otherwise, it  returns c.

a97-A65 = 32
z122
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

/*RETURN VALUE
The value returned is that of the converted letter,
or c if  the  conversion was not possible.*/