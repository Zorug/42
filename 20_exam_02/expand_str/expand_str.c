#include <unistd.h>

void do_it_now(char *str)
{
	int i = 0, j = 0;

	while (str[j])
		j++;
	j--;
	while (str[j] == ' ' || str[j] == '\t')
		j--;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] && i <= j)
	{
		if (str[i] != ' ' && str[i] != '\t')
			write(1, &str[i], 1);
		else
			if (str[i+1] != ' ' && str[i+1] != '\t')
				write (1, "   ", 3);
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		do_it_now(argv[1]);
	}
	write (1, "\n", 1);
}