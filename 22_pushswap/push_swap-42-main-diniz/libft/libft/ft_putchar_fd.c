/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:19:46 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_putchar_fd
//	Prototype
//		void ft_putchar_fd(char c, int fd);
//	Turn in files
//		-
//	Parameters
//		c: The character to output.
//		fd: The file descriptor on which to write.
//	Return value
//		None
//	External functs.
//		write
//	Description
//		Outputs the character ’c’ to the given file descriptor.

#include "../libft.h"
// for the stdlib.h

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
