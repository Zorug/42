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
	int		i; //  índice para percorrer envp[]
	char	*path_aux; // onde será guardada a string com os diretórios do PATH

	i = 0;
	path_aux = NULL;
	if (!envp[0]) // Se não há variáveis de ambiente, usa valor padrão
		path_aux = ft_strdup("/usr/bin:/bin");
	else
	{
		// 	Procura pela linha que começa com "PATH="
		while (envp[i] && (ft_strncmp(envp[i], "PATH=", 5) != 0))
			i++;
		if (envp[i] && envp[i][5] != '\0')
			// envp[i] + 5:	Pega apenas a parte útil, após o =
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
	char	*path_aux; // string temporária para construir "/bin/"
	char	*path_command; //  resultado final (/bin/ls, por exemplo)

	path_command = NULL;
	// Se path_i = "/bin", isso vira "/bin/"
	path_aux = strjoin(path_i, "/");
	// Agora temos: "/bin/" + "ls" → "/bin/ls"
	path_command = ft_strjoin(path_aux, command);
	free(path_aux);
	/*
	Um caminho absoluto (/usr/bin/grep)
    Ou um caminho relativo (./script.sh)
👉 A função simplesmente o retorna com ft_strdup() (ignora o PATH)
	*/
	if  (command[0] == '/' || (ft_strncmp(command, "./", 2) == 0))
		path_command = ft_strdup(command);
	/*
	Se o comando:
    Tem extensão .sh
    E tem uma / (ou seja, já é um caminho tipo "./meu_script.sh" ou "scripts/test.sh")
👉 Também duplica o caminho e retorna
	*/
	else if (ft_strnstr(command, ".sh", ft_strlen(command))
				&& ft_strchr(command, '/'))
		path_command = ft_strdup(command);
	/*
	Usa access(path, F_OK) para checar se o arquivo existe
	Se sim → retorna o caminho montado
	*/
	if (access(path_command, F_OK) == 0) // Retorna se existir
		return (path_command);
	free(path_command);
	return (NULL);
}

/*
    path_aux: é a string com os diretórios do PATH (ex: "/usr/bin:/bin:/usr/local/bin")
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
		/*
		path_aux = "/usr/bin:/bin:/usr/local/bin"
		path = { "/usr/bin", "/bin", "/usr/local/bin", NULL }
		*/
		path = ft_split(path_aux, ':');
		while (path[i])
		{
			// monta o caminho + testa com access()
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
char    *get_path(char *command, char **envp)
{
	char    *path_aux; // Vai armazenar a string PATH extraída do envp
	char    *path_command; // Caminho final encontrado (ex: "/bin/ls")

	path_command = NULL;
	if (command == NULL)	// Evita erro caso alguém chame 
		return (NULL);		// get_path(NULL, envp);
/*
Isso cobre casos como:
    ./meu_script
    /usr/bin/ls
Ou seja, se o comando já tem caminho explícito, não precisa procurar 
no PATH. Só duplica a string e retorna.
*/
	if ((command[0] == '.' || command[0] == '/'))
		return (ft_strdup(command));
	else
		path_aux = ft_get_path_aux(envp);
/*
Essa função (ft_get_path_aux) faz algo tipo:
- Percorre envp
- Encontra a variável que começa com "PATH="
- Retorna o valor: "/bin:/usr/bin:/usr/local/bin" (por exemplo)
*/
	path_command = find_path(path_aux, command);
/*
A função find_path provavelmente:
    Divide o path_aux em vários diretórios com ft_split(':')
    Para cada diretório, faz algo como:
/bin/ + / + ls → /bin/ls
/usr/bin/ls
Usa access(full_path, X_OK) pra ver se o comando existe e é executável
*/
	free(path_aux);
	return(path_command);
}