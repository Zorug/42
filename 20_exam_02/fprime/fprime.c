#include <stdlib.h>
#include <stdio.h>

void primatizator(int num)
{
	int i = 2;

	if (num == 1)
		printf("%d", num);

	while (num > 1 && i <= num)
	{
		while(!(num % i))
		{
			if(i == num)
			{
				printf("%d", i);
				num = num/i;
			}
			else
			{
				printf("%d*", i);
				num = num/i;
			}
		}
		//printf("%d\t", num);
		i++;
	}
}

int main(int argc, char **argv)
{
	int num;

	if (argc == 2)
	{
		num = atoi(argv[1]);
		//printf("---%d---\n", num);
		primatizator(num);
	}
	printf("\n");
}