#include "pipex.h"

void	ft_free_memory(char **path, char *path_command)
{
	ft_free_array(path);
	free(path_command);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_error(char *error_message)
{
	ft_putstr_fd(error_message, 2); // Escreve a mensagem de erro no stderr
	// 2 é a saída de erro padrão
	exit(EXIT_FAILURE); // Encerra o programa com status de erro 1
}