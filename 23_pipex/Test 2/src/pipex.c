#include "pipex.h"

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