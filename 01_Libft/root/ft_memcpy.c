/*DESCRIPTION
The  memcpy() function copies n bytes from memory  area 
src to memory area dest.  The memory areas must not 
overlap.  Use memmove(3) if  the  memory areas do overlap.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = -1;
	if (dest == NULL || src == NULL)
		return (NULL);
	if (n == 0 || dest == src)
		return (dest);
	d = (char *)dest;
	s = (const char *)src;
	while (++i < n)
		d[i] = s[i];
	return (dest);
}

/*RETURN VALUE
   The memcpy() function returns a pointer to dest.
*/