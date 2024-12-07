/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:26:03 by cgross-s          #+#    #+#             */
/*   Updated: 2024/10/22 17:26:34 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*is alphabetic a(97) z(122) A(65) Z(90)*/

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*RETURN VALUE
    The  values  returned  are nonzero if the character 
    c falls into the tested class, and zero if not.
*/