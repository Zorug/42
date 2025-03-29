/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:32:34 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_putendl_fd
//	Prototype
//		void ft_putendl_fd(char *s, int fd);
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
//		Outputs the string ’s’ to the given file descriptor followed by a
//	newline.

#include "../libft.h"
// for the write()

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
