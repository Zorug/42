/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_urandom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:51:45 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/22 21:53:49 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_read(char **line, int fd, char limiter)
/* 	char **line		Onde será armazenada a string lida
	int fd				Descritor do arquivo a ser lido
	char limiter		Um caractere limitador (ex: '\0', '\n') */
{
	char	*buffer;
	char	c;
	int		i;

	i = 0;
	if (fd < 0)
		return (-1);
	buffer = ft_calloc(sizeof(char), 10000000);
	if (!buffer)
		return (-1);
	while (read(fd, &c, 1) > 0 && c && c != limiter && i < 10000000 - 2)
		buffer[i++] = c;
	buffer[i] = '\n';
	buffer[i + 1] = '\0';
	*line = buffer;
	return (i + 1);
}

/* Essa função serve para criar um arquivo temporário com dados 
aleatórios, para ser usado como infile controlado no lugar de 
/dev/urandom. */
void	handle_urandom(void)
{
	int		tmp_fd;
	int		urandom_fd;
	char	*buffer;

	urandom_fd = open("/dev/random", O_RDONLY);
	if (urandom_fd < 0)
		return ;
	tmp_fd = open(".pipex_urandom", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd < 0)
		return ;
	if (ft_read(&buffer, urandom_fd, '\0') == -1)
		return ;
	write(tmp_fd, buffer, ft_strlen(buffer));
	free(buffer);
	close(tmp_fd);
}
/*	/dev/urandom não tem fim → pode travar o programa
	Então handle_urandom():
		- Gera um trecho finito de dados aleatórios
		- Salva num arquivo .pipex_urandom
		- Esse arquivo é usado como o infile */