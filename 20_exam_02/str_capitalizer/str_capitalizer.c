#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

bool is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (true);
	else
		return (false);
}

bool is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (true);
	else
		return (false);
}

void do_something(char *str)
{
	int i = 0;
	if (is_upper(str[0]) || is_lower(str[0]))
	{
		if (is_lower(str[0]))
		{
			str[0] = str[0] - 32;
			//write (1, &str[0], 1);
		}
		write (1, &str[0], 1);
		i++;
	}
	while (str[i])
	{
		if (is_upper(str[i-1]) && is_upper(str[i]))
			str[i] = str[i] + 32;
		else if (is_lower(str[i-1]) && is_upper(str[i]))
			str[i] = str[i] + 32;
		else if (is_lower(str[i]) && (str[i-1] == ' ' || str[i-1] == '\t'))
			str[i] = str[i] - 32;
		else if (is_upper(str[i]) && (str[i-1] != ' ' && str[i-1] != '\t'))
			str[i] = str[i] + 32;
		//if (str[i] != ' ' && str[i] != '\t' )
		//	write(1, &str[i], 1);
		//else //spaces and tabs
		write(1, &str[i], 1);
		i++;
	}
}

int main (int argc, char **argv)
{
	int i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			do_something(argv[i]);
			write (1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
}