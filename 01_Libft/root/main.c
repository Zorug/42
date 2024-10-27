#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	const char *s;
	char c;

	s = "fernanda martins de oliveira correa";
	c = 'r';

	printf("first = %s\n", ft_strchr(s, c));
	printf("first = %s\n", strchr(s, c));
	printf("last = %s\n", ft_strrchr(s, c));
	printf("last = %s\n", strrchr(s, c));
}