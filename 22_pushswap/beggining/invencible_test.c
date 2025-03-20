#include <stdio.h>
#include <stdbool.h>

bool is_number(char *str)
{
	if (!(*str == '+'
		|| *str == '-'
		|| (*str >= '0' && *str <= '9')))
			{
				printf("%s\terro1\t", str);
				return (false);
			}
	if ((*str == '+'
			|| *str == '-')
			&& !(str[1] >= '0' && str[1] <= '9'))
			{
				printf("%s\terro2\t", str);
				return (false);
			}
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			printf("%s\terro3\t", str);
			return (false);
		}
	}
	return (true);
}

int main(int argc, char **argv)
{
	int i=1;

	if (argc > 1)
	{
		while(argv[i])
		{
			printf("%s\t%d\n\n", argv[i], is_number(argv[i]));
			i++;
		}
	}
	else
		printf("estão a faltar argumentos.\n");
}