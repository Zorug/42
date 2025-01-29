//97=a, 122=z
#include <unistd.h>
#include <stdio.h>

void write_upper(char c)
{
	int pos = 0;
	while (pos<=(c-'A'))
	{
		write(1, &c, 1);
		pos++;
	}
}

void write_lower(char c)
{
	int pos = 0;
	while (pos<=(c-'a'))
	{
		write(1, &c, 1);
		pos++;
	}
}

int main(int argc, char **argv)
{
	/*if (argc == 2 && argv[1][0] == '\0')
		write(1, "\n", 1);*/
	if (argc == 2)
	{
		int i = -1;
		while(argv[1][++i])
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				write_lower(argv[1][i]);
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				write_upper(argv[1][i]);
			else
				write(1, &argv[1][i], 1);

	}
	//else
	write(1, "\n", 1);

}