#include <stdio.h>

char *ft_itoa(int n)
{
	char	itoanum[11];//maxsize neg int
	int		sign;

	ft_bzero(itoanum, 11);
	if (n < 0)
	return (itoanum);
}

int main()
{
	printf("%s", ft_itoa(42));
}
