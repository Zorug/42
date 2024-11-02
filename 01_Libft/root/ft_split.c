#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	i;
	size_t	j; /*conta palavras*/

	i = 0;
	j = 0; /*nenhuma palavra encontrada*/
	while (s[i] == c)/*pula os primeros*/
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i]) /*caso haja mais de um seguido*/
				i++;
			if (s[i + 1] == '\0')
				break;
			else
				j++;/*palavra nova*/
		}
		else
			i++;
	}
	splitted = (char **)malloc(sizeof(char *) * j)
	return (splitted);
}