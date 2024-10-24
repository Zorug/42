/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:08:30 by cgross-s          #+#    #+#             */
/*   Updated: 2024/10/22 22:08:32 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isascii(): checks whether c is a 7-bit unsigned 
char value that fits into the ASCII character set.
0 - 127
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*RETURN VALUE
The  values  returned  are nonzero if the character c 
falls into the tested class, and zero if not.*/