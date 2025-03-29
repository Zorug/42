/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:54:33 by abessa-m          #+#    #+#             */
/*   Updated: 2024/10/23 16:02:40 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reimplements isalpha()
// `man isalpha`

// 0 is FALSE
// anything else is TRUE
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (c);
	else
		return (0);
}
