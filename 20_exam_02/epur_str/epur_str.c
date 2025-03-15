#include <unistd.h>
#include <stdio.h>
//#include <stdbool>

void work_it(char *str)
{
	int i = 0, j = 0;
	//printf("testex\n");
	while (str[j])
	{
		//printf("%c-%d|",str[j],j);
		j++;
	}
	j--;
	//printf("\nteste0\n");
	while (str[j] == '\t' || str[j] == ' ')
	{
		//printf("%c-%d|",str[j],j);
		j--;
	}
	//j++;
	//printf("%c-%d|",str[j],j);
	//printf("teste1\n");
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	//printf("teste2\n");
	while (str[i] && i<=j)
	{
		//printf("%d", i);
		if (str[i] != '\t' && str[i] != ' ')
			write(1, &str[i], 1);
		else if (str[i+1] != '\t' && str[i+1] != ' ')
			write(1, " ", 1);
		i++;
	}
	//printf("teste3\n");
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		work_it(argv[1]);
	}
	write(1, "\n", 1);
}