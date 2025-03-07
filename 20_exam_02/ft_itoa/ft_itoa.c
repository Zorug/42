#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char	*ft_itoa(int nbr)
{
	char *str;
	bool negative = false;
	int i=0, onbr;
	int rest = 0;
	if (nbr == 0)
	{
		str = (char*)malloc(sizeof(char)*2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	else if (nbr < 0)
	{
		//printf("negativa");
		negative = true;
		i++;
		nbr = -nbr;
	}
	onbr = nbr;
	while(nbr)
	{
		rest = nbr%10;
		nbr = nbr/10;
		//printf("%d\n", rest);
		i++;
	}
	//i--;
	str = (char*)malloc(sizeof(char)*(i));
	//printf("!!%d!!", i);
	int j = 0;
	if (negative == true)
	{
		//printf("negativa\n");
		str[0] = '-';
		//printf("%d!%d\n", str[0],j);
		//j++;
	}
	j = i-1;
	//printf("!%d!\n",j);
	char c;
	//printf("5.<%d>\n",onbr);
	while(onbr)
	{
		rest = onbr%10;
		onbr = onbr/10;
		//printf("!%d!%d\n",j,rest);
		c = rest + '0';
		str[j] = c;
		j--;
	}
	str[i] = '\0';

	return(str);
}

/*int main()
{
	int nbr;
	nbr = 33698;
	printf("A%s\n",ft_itoa(nbr));
	nbr = 0;
	printf("B%s\n",ft_itoa(nbr));
	nbr = -765;
	printf("C%s\n",ft_itoa(nbr));
}*/