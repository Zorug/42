/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:28:09 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_putstr_fd
//	Prototype
//		void ft_putstr_fd(char *s, int fd);
//	Turn in files
//		-
//	Parameters
//		s: The string to output.
//		fd: The file descriptor on which to write.
//	Return value
//		None
//	External functs.
//		write
//	Description
//		Outputs the string ’s’ to the given file descriptor.

#include "../libft.h"
// for the ft_putchr_fd()

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	pos;

	pos = 0;
	while (s[pos] != '\0')
	{
		ft_putchar_fd(s[pos], fd);
		pos++;
	}
}
