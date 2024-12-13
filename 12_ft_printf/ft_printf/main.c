#include "ft_printf.h"

int main()
{
	int i;

	i = ft_printf("FT: Este é %c tes%ce de char\n", '1', 'T');
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: Este é %c tes%ce de char\n", '1', 'T');
	printf("sizeofprintf: %d\n",i);

	char *s;
	s = "!STRING PARA TESTE!";

	i = ft_printf("FT: Este é uma %s\n", s);
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: Este é uma %s\n", s);
	printf("sizeofprintf: %d\n",i);

}