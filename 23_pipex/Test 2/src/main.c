# include "pipex.h"


//#include <stdio.h>

void	init_pipex(t_pipex *pipex)
{
	pipex->args_cmd1 = NULL;
	pipex->args_cmd2 = NULL;
	pipex->path_cmd1 = NULL;
	pipex->path_cmd2 = NULL;
	pipex->fd_infile = -1;
	pipex->fd_outfile = -1;
}

void	check_args(t_pipex *pipex, char **argv, char **envp)
{
	if (argv[CMD1][0] == '\0')		// Se o usuário passar "" (comando vazio),
		pipex->args_cmd1 = NULL;	// marca como NULL (sem comando)
	else
	{
		// Se cmd1 = "grep banana", vira: { "grep", "banana", NULL }
		pipex->args_cmd1 = ft_split_mod(argv[CMD1]);
		if (!pipex->args_cmd1)
		//Se ft_split_mod retornou NULL, o programa evita erro posterior
			pipex->args_cmd1 = NULL;
		else
			pipex->path_cmd1 = get_path(pipex->args_cmd1[0], envp);
	}
	if (argv[CMD2][0] == '\0') // repete o mesmo para cmd2
		pipex->args_cmd2 = NULL;
	else
	{
		pipex->args_cmd2 = ft_split_mod(argv[CMD2]);
		if (!pipex->args_cmd2)
			pipex->path_cmd2 = NULL;
		else
			pipex->path_cmd2 = get_path(pipex->args_cmd2[0], envp);
	}
}

int main(int argc, char **argv, char **envp)
{ //envp: array com as variáveis de ambiente (usado para achar os comandos)
	
	t_pipex	pipex;
	
	if (argc < 5) // Verificação de argumentos (5)
		ft_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	
	init_pipex(&pipex); //zera os campos da estrutura t_pipex

	check_args(&pipex, argv, envp); // quebra e localiza os comandos

	ft_exec(&pipex, envp, argv); // pipe e fork
}

