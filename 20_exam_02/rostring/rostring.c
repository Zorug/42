#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool more_word(char *str, int mark)
{
	while(str[mark])
	{
		if (str[mark] != ' ' && str[mark] != '\t')
			return true;
		mark++;
	}
	return (false);
}

void do_it(char *str)
{
	int mark = 0;
	while(str[mark] == ' ' || str[mark] == '\t')
		mark++;
	while(str[mark] != ' ' && str[mark] != '\t' &&str[mark])
		mark++;
	int len = 0;
	while (str[len])
		len++;

	//int b = mark;
	bool more_words = more_word(str, mark);

	while (str[len-1] == ' ' || str[len-1] == '\t')
	{
		len--;
	}

	int i;
	if (more_words == true)
	{
		for (i = mark; i < len; i++)
		{
			if (str[i] != ' ' && str[i] != '\t')
				write (1, &str[i], 1);
			else if (str[i+1] != ' ' && str[i+1] != '\t' && i != mark)
				write (1, " ", 1);
		}
		write (1, " ", 1);
	}
	for (i = 0; i < mark; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			write (1, &str[i], 1);
	}
}

int main (int argc, char **argv)
{
	if (argc >= 2)
	{
		do_it(argv[1]);
	}
	write(1, "\n", 1);
}