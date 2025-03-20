#include <unistd.h>
#include <stdio.h>

void do_stuff(char *str)
{
	//int i = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	while (*str != ' ' && *str != '\t' && *str)
	{
		write(1, str, 1);
		str++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		do_stuff(argv[1]);
	}
	write (1, "\n", 1);
}