/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:42:31 by abessa-m          #+#    #+#             */
/*   Updated: 2024/10/25 13:50:01 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Emulates toupper()
// If c is a lowercase letter, toupper() returns its uppercase equivalent
// The value returned is that of the converted letter,
//	or c if the conversion was not possible.

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
