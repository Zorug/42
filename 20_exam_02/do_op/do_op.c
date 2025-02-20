#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	if (argc == 4)
	{
		int i, j;
		i = atoi(argv[1]);
			//printf("%d",i);
		j = atoi(argv[3]);
			//printf("%d",j);
		if (argv[2][0] == '+')
			printf("%d",i+j);
		else if (argv[2][0] == '-')
			printf("%d",i-j);
		else if (argv[2][0] == '*')
			printf("%d",i*j);
		else if (argv[2][0] == '/')
			printf("%d",i/j);
		else if (argv[2][0] == '%')
			printf("%d",i%j);
	}
	printf("\n");
}