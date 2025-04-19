#include "pipex.h"

void	setup_infile(t_pipex *pipex, char **argv)
{
	// Aqui o código está verificando se o arquivo de entrada 
	// (argv[INFILE]) é /dev/urandom — um gerador de bytes aleatórios 
	// do Linux.
	if (ft_strncmp(argv[INFILE], "/dev/urandom", 12) == 0)
	{
		// função que deve criar/gerar um arquivo .pipex_urandom com 
		// dados aleatórios.
		handle_urandom();
		//pipex->fd_infile = open(URANDOM_PATH, O_RDONLY)
		//Depois abre esse arquivo gerado no modo somente leitura 
		// (O_RDONLY), e armazena o descritor em pipex->fd_infile.
		pipex->fd_infile = open(".pipex_urandom", O_RDONLY)
	}
	/*
	Abre o arquivo indicado normalmente no modo somente leitura.
	O 0444 aqui define permissões de leitura para todos (embora 
	open com O_RDONLY geralmente nem precise disso).
	*/
	else
		pipex->fd_infile = open(argv[INFILE], O_RDONLY, 0444);
	if (pipex->fd_infile == -1)
	{
		perror(argv[INFILE]);
		ft_cleanup(pipex);
		exit(1);
	}
}