/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:35:11 by cgross-s          #+#    #+#             */
/*   Updated: 2024/10/22 19:35:13 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
isalnum()
checks for an alphanumeric character; it is equivalent to 
(isalpha(c) || isdigit(c)).
*/
int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	else
		return (0);
}

/*
RETURN VALUE:
The  values  returned  are nonzero if the character c 
falls into the tested class, and zero if not.
*/