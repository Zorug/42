#include <unistd.h>

void rotone(char *str)
{
	int i = 0;
	char c;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'y')
			c = str[i] + 1;
			//write(1, &(str[i]+1), 1);
		else if (str[i] == 'z')
			c = str[i] = 'a';
			//write(1, "a", 1);
		else if (str[i] >= 'A' && str[i] <= 'Y')
			c = str[i] + 1;
			//write(1, &(str[i]+1), 1);
		else if (str[i] == 'Z')
			c = str[i] = 'A';
			//write(1, "A", 1);
		else
			c = str[i];
		write(1, &c, 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		rotone(argv[1]);
	}
	write(1, "\n", 1);
}