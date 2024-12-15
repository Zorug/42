//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
#include "ft_printf.h"

char *putnbr(int n, char *base_to)
//char *putnbr(long n, char *base_to)
{
	int str_size = 0;
	int temp_n = n;
	int sizeofbase = ft_strlen(base_to);
	//int base_position;
	char *str;

	if (n < 0) {
		n = -n;
		str_size++;
	}
/*	while (n > 0) {
		n = n / sizeofbase;
		str_size++;
	}
	n = temp_n;*/
	while (temp_n > 0) {
		temp_n = temp_n / sizeofbase;
		str_size++;
	}
	str = malloc(sizeof(char)*(str_size + 1));
	//if (!str) putnbr(n, base_to); // malloc error
	if (!str) return (NULL);
	if (n < 0) {
		n = -n;
		str[0] = '-';
	}
	while (n > 0) {
		//base_position = n % sizeofbase;
		str[--str_size] = base_to[n % sizeofbase];
		n = n / sizeofbase;
		//str_size--;
	}
	return(str);
}

int find_base_position (char c, char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return(i);
		i++;
	}
	return(-1);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int i = 0;
	int sizeofbase = ft_strlen(base_from);
	int n = 0;
	int multiplier = 1;
	int sign = 1;
	int base_position;

	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (nbr[i])
	{
		base_position = find_base_position (nbr[i], base_from);
		n = n*multiplier + base_position;
		multiplier = sizeofbase;
		i++;
	}
	n = n * sign;
	return(putnbr(n, base_to));
}

/*int main(int argc, char **argv)
{
	//char *base_from = "01";
	char *base_from = "0123456789";
	//char *base_from = "0123456789ABCDEF";
	//char *base_to = "01";
	char *base_to = "0123456789";
	//char *base_to = "0123456789ABCDEF";
	char *result;

	result = NULL;
	if (argc == 2) {
		result = ft_convert_base(argv[1], base_to, base_from);
		if (result) {
			printf("O resultado da conversão é: %s\n", result);
			free(result);
			result = NULL;
		}
		else
			printf("Erro: conversão inválida.\n");
	}
	printf("O resultado da conversão é: %s\n", result);
}*/