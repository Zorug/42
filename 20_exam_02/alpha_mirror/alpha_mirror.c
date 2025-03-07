#include <unistd.h>

char rotete_lower(char c)
{
	return ('z' - (c - 'a'));
}

char rotete_upper(char c)
{
	return ('Z' - (c - 'A'));
}

void mirror_it(char *str)
{
	char c;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			c = rotete_lower(*str);
		}
		else if (*str >= 'A' && *str <= 'Z')
		{
			c = rotete_upper(*str);
		}
		else
			c = *str;
		write (1, &c, 1);
		str++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		mirror_it(argv[1]);
	}
	write (1, "\n", 1);
}