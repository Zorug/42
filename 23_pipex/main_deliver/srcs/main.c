/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:35:09 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/27 08:57:39 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(t_pipex *pipex, char **argv, char **envp)
{
	if (argv[CMD1][0] == '\0')
		pipex->args_cmd1 = NULL;
	else
	{
		pipex->args_cmd1 = ft_split_mod(argv[CMD1]);
		if (!pipex->args_cmd1)
			pipex->path_cmd1 = NULL;
		else
			pipex->path_cmd1 = get_path(pipex->args_cmd1[0], envp);
	}
	if (argv[CMD2][0] == '\0')
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

void	init_pipex(t_pipex *pipex)
{
	pipex->args_cmd1 = NULL;
	pipex->args_cmd2 = NULL;
	pipex->path_cmd1 = NULL;
	pipex->path_cmd2 = NULL;
	pipex->fd_infile = -1;
	pipex->fd_outfile = -1;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	init_pipex(&pipex);
	check_args(&pipex, argv, envp);
	ft_exec(&pipex, envp, argv);
	ft_cleanup(&pipex);
	return (0);
}

/*
echo -e "banana\nlaranja\nbanana\nuva\nabacaxi\nbanana" > input.txt

valgrind --leak-check=full --show-leak-kinds=all --track-fds=
yes --trace-children=yes ./pipex

./pipex input.txt "grep banana" "wc -l" output.txt
< input.txt grep banana | wc -l > output.txt

./pipex input.txt "cat -e" "wc -l" outfile.txt
./pipex input.txt "cat" "echo" output.txt
./pipex input.txt "tr a-z A-Z" "rev" output.txt

./pipex input.txt "cat -e" "cut -d\$ -f1" output.txt | JP error
./pipex input.txt "grep ^b" "sort -r" output.txt

./pipex input.txt "banana123" "wc -l" output.txt
# Esperado: erro de "command not found" e exit code 127

./pipex nofile.txt "cat" "wc -l" output.txt
# Esperado: erro de "No such file or directory"

touch secret.txt && chmod 000 secret.txt
./pipex secret.txt "cat" "wc -l" output.txt
# Esperado: "Permission denied"

./pipex input.txt "grep nadaencontrado" "wc -l" output.txt
# Esperado: output.txt deve conter 0

SCRIPT .SH
echo -e '#!/bin/bash\necho "olá do script!"' > test.sh
chmod +x test.sh
./pipex input.txt "./test.sh" "wc -l" output.txt

./pipex input.txt "awk '{print $1}'" "sort" output.txt
./pipex input.txt "sed 's/banana/laranja/g'" "tee log.txt" output.txt

URANDOM
./pipex /dev/urandom "head -c 100" "wc -c" output.txt

Comparação automática com shell (bash vs pipex)
< input.txt grep banana | wc -l > expected.txt
./pipex input.txt "grep banana" "wc -l" actual.txt
diff expected.txt actual.txt && echo "✅ OK" || echo "❌ Diferente"

*/