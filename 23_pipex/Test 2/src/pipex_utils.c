#include "pipex.h"

/*
Objetivo:
Abrir (ou criar) o arquivo de saída (outfile) para escrever 
nele no final do pipeline.
*/
void	setup_outfile(t_pipex *pipex, char **argv) // trata saída
{
	/*
Abre o arquivo com:
    O_WRONLY: apenas escrita
    O_CREAT: cria se não existir
    O_TRUNC: trunca (limpa) o conteúdo anterior
Permissões: 0666 → leitura e escrita para todos (respeita umask)
	*/
	pipex->fd_outfile = open(argv[OUTFILE],
							O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex->fd_outfile = -1) //erro
	{
		perror(argv[OUTFILE]);
		ft_cleanup(pipex);
		//Faz um segundo open() para verificar se o erro 
		// foi por permissão:
		if (open(argv[OUTFILE], O_WRONLY) != 0)
			exit(2);
		exit(1);
	}
}

/*
Objetivo:
Abrir o arquivo de entrada (infile) para ser lido no início 
do pipeline.
*/
void	setup_infile(t_pipex *pipex, char **argv) // trata entrada
{
/*
	Verifica se é /dev/urandom:
	- Se o infile é /dev/urandom, o programa chama uma função 
	especial handle_urandom() (deve criar um arquivo auxiliar 
	com conteúdo aleatório)
	- Depois abre esse arquivo temporário (.pipex_urandom) para 
	leitura
*/
	if (ft_strncmp(argv[INFILE], "/dev/urandom", 12) == 0)
	{
		// // cria arquivo temporário com conteúdo aleatório
		handle_urandom(); 
		//pipex->fd_infile = open(URANDOM_PATH, O_RDONLY)
		pipex->fd_infile = open(".pipex_urandom", O_RDONLY);
	}
/*
	Se não for urandom:
	- Abre normalmente o arquivo passado como infile, apenas para 
	leitura
	- Permissão 0444 garante leitura (mas não afeta open() se o 
	arquivo já existir)
*/
	else
		pipex->fd_infile = open(argv[INFILE], O_RDONLY, 0444);
	if (pipex->fd_infile == -1) // caso de erro
	{
		perror(argv[INFILE]);
		ft_cleanup(pipex);
		exit(1);
	}
}
