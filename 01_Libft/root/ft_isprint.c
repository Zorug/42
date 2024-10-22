/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:17:52 by cgross-s          #+#    #+#             */
/*   Updated: 2024/10/22 22:17:54 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isprint()
checks for any printable character including space.
32-126
*/
int	isprint(int c)
{
	if (c >= 31 && c <= 126)
		return (c);
	else
		return (0);
}
/*
RETURN VALUE
    The  values  returned  are nonzero if the character 
c falls into the tested class, and zero if not.
*/