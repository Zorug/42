#include <unistd.h>

void rot_it(char *str)
{
	char c;
	while(*str)
	{
		//c = *str +1;
		//write(1, &c, 1);
		if (*str >= 'a' && *str <= 'm')
			c = *str + 13;
		else if (*str >= 'n' && *str <= 'z')
			c = *str - 13;
		else if (*str >= 'A' && *str <= 'M')
			c = *str + 13;
		else if (*str >= 'N' && *str <= 'Z')
			c = *str - 13;
		else
			c = *str;
		write(1, &c, 1);
		str++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		rot_it(argv[1]);
	}
	write(1, "\n", 1);
}