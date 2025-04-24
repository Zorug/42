/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:33:18 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/22 23:41:33 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Ela basicamente extrai o conteúdo da variável de ambiente PATH, 
que é algo assim:
PATH=/usr/local/bin:/usr/bin:/bin
E retorna só a parte após o =, ou seja:
"/usr/local/bin:/usr/bin:/bin"

envp: array de strings com todas as variáveis de ambiente (vindo do main)
Retorna: uma cópia da string contendo os diretórios do PATH 
(ou um valor padrão)
*/
char	*ft_get_path_aux(char **envp)
{
	int		i;
	char	*path_aux;

	i = 0;
	path_aux = NULL;
	if (!envp[0])
		path_aux = ft_strdup("/usr/bin:/bin");
	else
	{
		while (envp[i] && (ft_strncmp(envp[i], "PATH=", 5) != 0))
			i++;
		if (envp[i] && envp[i][5] != '\0')
			path_aux = ft_strdup(envp[i] + 5);
	}
	return (path_aux);
}

/*
responsável por montar e testar o caminho completo de um comando
command: nome do comando (ex: "ls", "grep", "meu_script.sh")
path_i: um diretório vindo do PATH (ex: "/bin", "/usr/bin")
🔍 A função monta o caminho "/bin/ls" e verifica com access() 
se esse executável existe.
*/
char	*ft_check_command_location(char *command, char *path_i)
{
	char	*path_aux;
	char	*path_command;

	path_command = NULL;
	path_aux = ft_strjoin(path_i, "/");
	path_command = ft_strjoin(path_aux, command);
	free(path_aux);
	if (command[0] == '/' || (ft_strncmp(command, "./", 2) == 0))
		path_command = ft_strdup(command);
	else if (ft_strnstr(command, ".sh", ft_strlen(command))
		&& ft_strchr(command, '/'))
		path_command = ft_strdup(command);
	if (access(path_command, F_OK) == 0)
		return (path_command);
	free(path_command);
	return (NULL);
}

/*
	path_aux: é a string com os diretórios do PATH 
	(ex: "/usr/bin:/bin:/usr/local/bin")
	command: o nome do comando (ex: "ls", "grep")
🧠 O que ela faz:
	Separa o PATH nos diretórios (/usr/bin, /bin, etc.)
	Para cada um, tenta montar o caminho completo:
	Ex: /usr/bin/ls, /bin/ls, etc.
	Verifica se o comando existe e é executável
	Se encontrar, retorna esse caminho
*/
char	*find_path(char *path_aux, char *command)
{
	char	**path;
	char	*path_command;
	int		i;

	i = 0;
	if (!path_aux)
		return (NULL);
	else
	{
		path = ft_split(path_aux, ':');
		while (path[i])
		{
			path_command = ft_check_command_location(command, path[i]);
			if (path_command != NULL)
			{
				ft_free_array(path);
				return (path_command);
			}
			i++;
		}
		ft_free_memory(path, path_command);
	}
	return (NULL);
}

/*
caminho absoluto de um comando, usando o PATH das variáveis de ambiente.
get_path("ls", envp);     → "/bin/ls"
get_path("/usr/bin/grep", envp); → "/usr/bin/grep"

char *command → o nome do comando (ex: "ls", "grep")
char **envp → as variáveis de ambiente do programa 
(como "PATH=/bin:/usr/bin")
*/
char	*get_path(char *command, char **envp)
{
	char	*path_aux;
	char	*path_command;

	path_command = NULL;
	if (command == NULL)
		return (NULL);
	if ((command[0] == '.' || command[0] == '/'))
		return (ft_strdup(command));
	else
		path_aux = ft_get_path_aux(envp);
	path_command = find_path(path_aux, command);
	free(path_aux);
	return (path_command);
}
