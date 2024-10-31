/*DESCRIPTION
The memmove() function copies n bytes from memory area 
src to memory area dest. 
The memory areas may overlap: copying takes place  as  
though  the bytes  in src are first copied into a 
temporary array that does not overlap src or dest, and 
the bytes are then copied from the temporary array to 
dest.*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (src < dest)/*evita sobrescrição*/
	{
		i = n;
		while (n > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*RETURN VALUE
	The memmove() function returns a pointer to dest.*/