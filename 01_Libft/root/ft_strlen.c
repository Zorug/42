/*DESCRIPTION
	   The  strlen() function calculates the length of the string pointed to
	   by s, excluding the terminating null byte ('\0').*/
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*RETURN VALUE
	   The strlen() function returns the  number  of  bytes  in  the  string
	   pointed to by s.*/