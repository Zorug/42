/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:54:59 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:55:00 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*If c is an uppercase letter, tolower() returns its 
lowercase  equivalent,  if  a  lowercase  representation 
exists in the current locale. Otherwise, it returns c. 
A65 Z90*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

/*The value returned is that of the converted letter, 
or c if the  conversion was not possible.*/