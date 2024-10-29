/* The strncmp() function is similar, except it compares only 
the  first (at most) n bytes of s1 and s2. */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/* The  strcmp()  and  strncmp()  functions return an integer 
less than, equal to, or greater than zero if s1 (or the first 
n  bytes  thereof) is found, respectively, to be less than, 
to match, or be greater than s2.*/