#include <unistd.h>

void change_case(char *str)
{
	char c;
	while(*str)
	{
		if (*str >= 'a' && *str <= 'z')
			c = *str -32;
		else if (*str >= 'A' && *str <= 'Z')
			c = *str +32;
		else
			c = *str;
		write(1, &c, 1);
		str++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		change_case(argv[1]);
	}
	write(1, "\n", 1);
}