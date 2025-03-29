/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:56:23 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:56:25 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strncmp() function is similar, except it compares only 
the  first (at most) n bytes of s1 and s2. */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* The  strcmp()  and  strncmp()  functions return an integer 
less than, equal to, or greater than zero if s1 (or the first 
n  bytes  thereof) is found, respectively, to be less than, 
to match, or be greater than s2.*/
/*A expressão (unsigned char)s1[i] - (unsigned char)s2[i] 
garante que a comparação entre os caracteres seja 
feita corretamente, mesmo para caracteres fora da faixa ASCII 
(ou valores negativos no caso de signed char)*/