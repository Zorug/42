/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:07:23 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/24 20:33:13 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Objetivo:
Abrir (ou criar) o arquivo de saída (outfile) para escrever 
nele no final do pipeline.
*/
void	setup_outfile(t_pipex *pipex, char **argv) // trata saída
/*	Abre o arquivo com:
	O_WRONLY: apenas escrita
	O_CREAT: cria se não existir
	O_TRUNC: trunca (limpa) o conteúdo anterior
	Permissões: 0666 → leitura e escrita para todos (respeita umask) */
{
	pipex->fd_outfile = open(argv[OUTFILE],
			O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex->fd_outfile == -1)
	{
		perror(argv[OUTFILE]);
		ft_cleanup(pipex);
		if (open(argv[OUTFILE], O_WRONLY) != 0)
		{
			close(pipex->fd_outfile);
			exit(2);	
		}
		close(pipex->fd_outfile);
		exit(1);
	}
}

/*
Objetivo:
Abrir o arquivo de entrada (infile) para ser lido no início 
do pipeline.
*/
void	setup_infile(t_pipex *pipex, char **argv)
/*
	Verifica se é /dev/urandom:
	- Se o infile é /dev/urandom, o programa chama uma função 
	especial handle_urandom() (deve criar um arquivo auxiliar 
	com conteúdo aleatório)
	- Depois abre esse arquivo temporário (.pipex_urandom) para 
	leitura
*/
{
	if (ft_strncmp(argv[INFILE], "/dev/urandom", 12) == 0)
	{
		handle_urandom();
		pipex->fd_infile = open(".pipex_urandom", O_RDONLY);
		//close()
	}
	else
	{
		pipex->fd_infile = open(argv[INFILE], O_RDONLY, 0444);
	}
	if (pipex->fd_infile == -1)
	{
		perror(argv[INFILE]);
		ft_cleanup(pipex);
		exit(1);
	}
}
