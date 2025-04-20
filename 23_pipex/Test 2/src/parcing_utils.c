#include "pipex.h"

int	is_only_spaces(const char *str)
{
	size_t	k;

	k = 0;
	while (k < ft_strlen(str))
	{
		if (str[k] != ' ' && str[k] != '\t' && str[k] != '\n')
			return (0);
		k++;
	}
	return (1);
}

void	copy_non_space_strings(char **dest, char **src)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (src[i] != NULL)
	{
		if(!is_only_spaces(src[i]))
			dest[j++] = src[i];
		else
			free(src[i]);
		i++;
	}
	dest[j] = NULL;
}

void	remove_spaces(char **array)
{
	if (array == NULL)
		return ;
	copy_non_space_strings(array, array);
}

char	*is_script(char *cmd)
{
	return (ft_strnstr(cmd, ".sh", ft_strlen(cmd)));
}
