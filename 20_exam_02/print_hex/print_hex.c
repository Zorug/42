#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int num = 0, i = 0;
	while (str[i])
		num = num*10 + (str[i++] - '0');
	return (num);
}

void print_base(int num)
{
	char base[16] = "0123456789abcdef";
	int bsize = 16, res;
	//while (num)
	/*if (num == 0 && !(num%bsize))
	{
		write (1, "0", 1);
		return ;
	}*/
	if (num && num%bsize)
	{
		res = num % bsize;
		//printf ("%d, %d\n", num, res);
		//num = num / bsize;
		print_base(num/bsize);
		write (1, &base[res], 1);
		//num = num / bsize;
	}
}

void work_it(char *str)
{
	int num = ft_atoi(str);
	//char base[16] = "0123456789abcdef";
	//printf ("%d\n", num);
	if (num == 0)
		write (1, "0", 1);
	else
		print_base(num);
/*	while (num)
	{
		res = num % bsize;
		//printf ("%d, %d\n", num, res);
		write (1, &base[res], 1);
		num = num / bsize;
	}*/
	//converter para hex
}

int main (int argc, char **argv)
{
	if (argc == 2)
		work_it(argv[1]);
	write (1, "\n", 1);
}