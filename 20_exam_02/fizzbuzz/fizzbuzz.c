#include <unistd.h>
#include <stdio.h>

void search_size (int i)
{
	char c;
	int j;

	if (i > 9)
	{
		search_size (i/10);
	}
	j = i % 10;
	c = j + '0';
	write (1, &c, 1);

}

int main()
{
	int i;

	i = 0;
	while (++i < 101)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "fizzbuzz", 8);
			//printf("fizzbuzz");
		else if (i % 3 == 0)
			write (1, "fizz", 4);
			//printf("fizz");
		else if (i % 5 == 0)
			write (1, "buzz", 4);
			//printf("buzz");
		else
			search_size (i);
			//printf("%d", i);
		write (1, "\n", 1);
		//printf("\n");
	}
}