#include <unistd.h>
#include <stdio.h>

int ft_strcnt(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

int ft_atoi (char *str)
{
	int dec = ft_strcnt(str), i = 0, num = 0;
	if (str[0] == '0')
		return (0);
	while(i < dec)
	{
		num = num*10 + str[i] - '0';
		i++;
	}
	return (num);
}

void ft_itoa(int num)
{
	int resto, i=0;
	char c;
	char str[50];

	if (num == 0)
	{
		c = '0';
		write (1, &c, 1);
	}
	else {
		while(num)
		{
			resto = num % 10;
			//num = num / 10;
			num = num / 10;
			c = resto + '0';
			str[i] = c;
			//printf("%d\n", resto);
			//write(1, &c, 1);
			i++;
		}
		i--;
		while(i >= 0)
		{
			write(1, &str[i], 1);
			i--;
		}
	//return (num);
	}
}

void do_the_work(char *str)
{
	int n = ft_atoi(str), test = 81, i = 1;
	//printf("!%d!", n);
	while (i < 10)
	{
		ft_itoa(i);
		write(1, " x ", 3);
		ft_itoa(n);
		write(1, " = ", 3);
		ft_itoa(n*i);
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		do_the_work(argv[1]);
	}
	else
		write (1, "\n", 1);
}