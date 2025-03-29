/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:48:01 by abessa-m          #+#    #+#             */
/*   Updated: 2024/10/24 18:52:10 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Emulates tolower()
// If c is an uppercase letter, tolower() returns its lowercase equivalent.
//	Otherwise, it returns  c.
// The value returned is that of the converted letter,
//	or c if the conversion was not possible.

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
