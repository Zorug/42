/* The strrchr() function returns a pointer to the LAST 
occurrence  of the character c in the string s.
Here  "character" means "byte"; these functions do not 
work with wide or multibyte characters.*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (*s)
	{
		if (*s == c)
			ptr = (char *)s;
		s++;
	}
	if (*s == c)
		ptr = (char *)s;
	return (ptr);
}

/* The strchr() and strrchr() functions return a pointer 
to the  matched character  or  NULL  if  the character is 
not found.  The terminating null byte is considered part 
of the string, so that if c is specified as '\0', these 
functions return a pointer to the terminator. */