/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:31:46 by abessa-m          #+#    #+#             */
/*   Updated: 2024/10/24 18:38:35 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Emulates ft_isprint
// checks for any printable character including space.
int	ft_isprint(int chr)
{
	if (chr >= 32 && chr <= 126)
		return (1);
	return (0);
}
