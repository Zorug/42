#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int i, j=1;
	if (tab[0])
		i = tab[0];
	else
		return(0);
	while (j < len)
	{
		//printf("%d\n", tab[j]);
		if (i < tab[j])
		{
			i = tab[j];
		}
		j++;
	}
	return (i);
}

/*int main()
{
	int tab[] = {7, -42, 0, -5, -64, -2, -68, -1};

	printf("%d\n", max(tab, 8));
}*/