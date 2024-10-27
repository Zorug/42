/* The  strchr()  function  returns a pointer to the FIRST 
occurrence of the character c in the string s.
Here  "character" means "byte"; these functions do not work 
with wide or multibyte characters.*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/* The strchr() and strrchr() functions return a pointer 
to the  matched character  or  NULL  if  the character is 
not found.  The terminating null byte is considered part 
of the string, so that if c is specified as '\0', these 
functions return a pointer to the terminator. */