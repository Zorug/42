/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:01:53 by cgross-s          #+#    #+#             */
/*   Updated: 2024/10/22 18:01:54 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
isdigit(): checks for a digit (0(48) through 9(57)).
*/
int	isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	else
		return (0);
}

/*
RETURN VALUE
    The  values  returned  are nonzero if the character 
    c falls into the tested class, and zero ifnot.
*/