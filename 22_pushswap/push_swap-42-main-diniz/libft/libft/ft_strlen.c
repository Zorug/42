/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:52:51 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
//ypedef typeof(sizeof(0)) size_t;

#include "../libft.h"
// for the definition of size_t as
// typedef typeof(sizeof(0)) size_t;

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
		j++;
	return (j);
}
