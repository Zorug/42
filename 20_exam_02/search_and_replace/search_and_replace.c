#include <unistd.h>
#include <stdbool.h>

bool search_it(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return true;
		str++;
	}
	return false;
}

int ft_strcnt(char *str)
{
	int i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void repalce_it(char *str, char arg2, char arg3)
{
	char c;

	while(*str)
	{
		if (*str == arg2)
			c = arg3;
		else
			c = *str;
		write(1, &c, 1);
		str++;
	}
}

int main(int argc, char** argv)
{
	if (argc == 4)
	{
		if (ft_strcnt(argv[2]) > 1 || ft_strcnt(argv[3]) > 1)
		{
			write (1, "\n", 1);
			return (0);
		}
		else if (search_it(argv[1], argv[2][0]) == true)
		{
			repalce_it(argv[1], argv[2][0], argv[3][0]);
			write (1, "\n", 1);
		}
		else
		{
			write(1, argv[1], ft_strcnt(argv[1]));
			write (1, "\n", 1);
		}
	}
	else
		write (1, "\n", 1);
}