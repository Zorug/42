#include "pipex.h"

/* Executar um comando
cmd: caminho completo do comando (ex: /bin/ls)
args: vetor de argumentos (ex: { "ls", "-l", NULL })
pipex: struct com os recursos alocados (pra liberar em caso de erro)
envp: variáveis de ambiente, necessárias para o execve() */
void	ft_execve(char *cmd, char **args, t_pipex *pipex, char **envp)
{
	/* executes the program referred to by pathname
	em caso de erro, -1 */
	if (execve(cmd, args, envp) == -1)
	{
	/* checks whether the calling process can access the file pathname.
	Verifica se o comando não é executável:
	- Verifica se o arquivo existe e é executável
	- Se não for, continua tratando o erro */
		if (access(cmd, X_OK) == -1) //erro
		{
		/* Verifica se o comando existe (mas não pode ser executado)
		- F_OK: testa se o arquivo existe
		- Se nem existe, vai imprimir erros específicos: */
			if (access(cmd, F_OK) == -1)
			{
		/* Se o comando começa com / ou é um script, mostra erro padrão do shell:
		"bash: ./naoexiste: No such file or directory" */
				if (args[0][0] == '/' || is_script(args[0]))
					custom_error(args[0],
						"No such file or directory", pipex, 127);
		/* Comando comum (sem /):
		Se for algo como "lsaaa" → comando inexistente */
				custom_error(args[0],
						"command not found", pipex, 127);
			}
		/* Se o comando existe mas não pode ser executado (sem permissão) 
		- Mostra erro de sistema com perror()
    	- Libera recursos
    	- Encerra com:
			- 🟥 exit(126) → comando encontrado, mas sem permissão para executar*/
			perror(args[0]);
			ft_cleanup(pipex);
			exit(126);
		}
	}
}

void    child_process(int *fd, t_pipex *pipex, char **envp)
// executar o primeiro comando (cmd1) 
{
	if (pipex->path_cmd1 == NULL) // get_path() falhou
	{
		// Se args_cmd1 está presente, tenta tratar como script ou caminho direto
		if (pipex->args_cmd1 != NULL)
		{
			// provavelmente verifica se é um arquivo .sh
			if (!is_script(pipex->args_cmd1[0]))
			/*
Se não for script, assume que o usuário passou um caminho já válido, e copia direto
    Ex: ./meu_programa → não está no PATH, mas é executável local
			*/
				pipex->path_cmd1 = ft_strdup(pipex->args_cmd1[0]);
		}
		else
		{
			ft_cleanup(pipex);
			ft_putstr_fd("command not found\n", 2);
			exit(127); // "comando não encontrado"
		}
	}
	// Redireciona entrada padrão (stdin) para o arquivo de entrada
	// Agora tudo que o processo ler de stdin, virá do arquivo infile
	dup2(pipex->fd_infile, STDIN_FILENO);
	/*  Redireciona saída padrão (stdout) para o pipe
	Agora tudo que o processo escrever, vai para o fd[1] → o pipe */
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	/* Substitui o processo atual pelo executável de cmd1
	Usa os argumentos corretos e as variáveis de ambiente */
	ft_execve(pipex->path_cmd1, pipex->args_cmd1, pipex, envp);
}

/* executar o segundo comando (cmd2) do pipex
 - Ler do pipe (saída de cmd1)
 - Escrever no arquivo de saída
 - Executar o comando cmd2 */
void	parent_process(int *fd, t_pipex *pipex, char **envp, int process)
// process	PID do processo do cmd1, usado com waitpid()
{
	/* Espera pelo processo cmd1, mas não bloqueia
		- Espera sem travar (WNOHANG) pelo término do processo anterior
		- Isso evita zombies, e ajuda a manter o controle da execução */
	waitpid(process, NULL, WNOHANG);
	if (pipex->path_cmd2 == NULL)
	{
		/* Se há argumentos, trata como script ou caminho direto
			- Se for um caminho relativo ou absoluto, ou não for .sh, tenta 
			copiar o nome direto */
		if (pipex->args_cmd2 != NULL)
		{  
			if (!is_script(pipex->args_cmd2[0]))
				pipex->path_cmd2 = ft_strdup(pipex->args_cmd2[0]);
		}
		/* Se não tiver comando, encerra com erro */
		else
		{
			ft_cleanup(pipex);
			ft_putstr_fd("command not found\n", 2);
			exit(127); // comando inválido/não encontrado
		}
	}
	/* Redireciona o stdin para o leitor do pipe 
	Tudo que cmd2 ler virá do que foi escrito pelo cmd1 (através do pipe) */
	dup2(fd[0], STDIN_FILENO);
	/* Redireciona o stdout para o arquivo de saída 
	A saída do cmd2 será escrita em outfile, como no shell */
	dup2(pipex->fd_outfile, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	/* Executa o comando 2
		- Substitui o processo atual pelo comando cmd2
		- Usa o caminho absoluto e os argumentos preparados antes */
	ft_execve(pipex->path_cmd2, pipex->args_cmd2, pipex, envp);
}

void    ft_exec(t_pipex *pipex, char **envp, char **argv)
{
	int fd[2];
	int process;

	if((pipe(fd)) == -1) // se falhar, imprime erro
		perror("pipe");

	process = fork();
	if (process == -1)
		perror("fork");
	
	if (process == 0) // filho
	{
		// provavelmente redireciona o stdin para o arquivo de entrada.
		setup_infile(pipex, argv);
		// executa o primeiro comando (cmd1) e escreve a saída no pipe (fd[1]).
		child_process(fd, pipex, envp);
	}
	else // pai
	{
		// redireciona o stdout para o arquivo de saída.
		setup_outfile(pipex, argv);
		// lê do pipe (fd[0]) e executa o segundo comando (cmd2) 
		// com execve (provavelmente), escrevendo no outfile.
		parent_process(fd, pipex, envp, process);
	}
}
