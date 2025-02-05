#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void put_char(char c)
{
	write(1, &c, 1);
}

void string_job (char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			put_char('_');
			put_char(*str + 32);
		}
		else
			put_char(*str);
		str++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		string_job (argv[1]);
	put_char('\n');
}