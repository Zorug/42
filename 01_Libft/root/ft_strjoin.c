/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		lens1;
	int		lens2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return NULL;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (ptr == NULL)
		return NULL;
	i = -1;
	while (++i < lens1)
		ptr[i] = s1[i];
	j = -1;
	while (++j < lens2)
		ptr[i+j] = s2[j];
	ptr[i+j] = '\0';
	return ptr;
}

/*
The new string.
NULL if the allocation fails.
*/