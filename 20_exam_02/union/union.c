#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

bool is_inlist(char c, char *charlist)
{
	int i = 0;

	while (charlist[i])
	{
		if (c == charlist[i])
			return (true);
		i++;
	}
	return (false);
}

void do_it(char *s1, char *s2)
{
	char charlist[100];
	int i = 0, last_pos = 0;

	while (s1[i])
	{
		if (is_inlist(s1[i], charlist) == false)
		{
			write (1, &s1[i], 1);
			charlist[last_pos] = s1[i];
			last_pos++;
		}
		i++;
	}

	i = 0;
	while (s2[i])
	{
		if (is_inlist(s2[i], charlist) == false)
		{
			write (1, &s2[i], 1);
			charlist[last_pos] = s2[i];
			last_pos++;
		}
		i++;
	}
	//write(1, "|", 1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		do_it(argv[1], argv[2]);
	}
	write (1, "\n", 1);
}