#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	char *dest;

	while (src[i])
		i++;
	dest = (char*)malloc(sizeof(char)*(i+1));
	if (!dest)
		return NULL;
	i=0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);

}

/*int main ()
{
	printf("%s\n", ft_strdup("!string!"));
}*/