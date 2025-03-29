/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:54:33 by abessa-m          #+#    #+#             */
/*   Updated: 2024/10/23 19:15:59 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reimplements isdigit()
// `man isdigit`

// 0 is FALSE
// anything else is TRUE
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}
