#include "ft_printf.h"

int main()
{
/*	int i;

	i = ft_printf("FT: Este é %c tes%ce de char\n", '1', 'T');
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: Este é %c tes%ce de char\n", '1', 'T');
	printf("sizeofprintf: %d\n",i);

	printf("-----------------------------\n");

	char *s;
	s = "!STRING PARA TESTE!";

	i = ft_printf("FT: Este é uma %s\n", s);
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: Este é uma %s\n", s);
	printf("sizeofprintf: %d\n",i);

	printf("-----------------------------\n");

	int x = 42;
	int *ptr = &x;

	i = ft_printf("FT: O endereço de x é: %p\n", (void *)ptr);
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: O endereço de x é: %p\n", (void *)ptr);
	printf("sizeofprintf: %d\n",i);

	printf("-----------------------------\n");

	int d = -10;
	unsigned int ui= 20;

	i = ft_printf("FT: O valor decimal é %d\n", d);
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: O valor decimal é %d\n", d);
	printf("sizeofprintf: %d\n",i);

	i = ft_printf("FT: O valor inteiro é %i\n", d);
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: O valor inteiro é %i\n", d);
	printf("sizeofprintf: %d\n",i);

	i = ft_printf("FT: O valor unsigned é %u\n", ui);
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: O valor unsigned é %u\n", ui);
	printf("sizeofprintf: %d\n",i);

	printf("-----------------------------\n");

	i = ft_printf("FT: hexadecimal: %x\n", d);
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: hexadecimal: %x\n", d);
	printf("sizeofprintf: %d\n",i);

	i = ft_printf("FT: HEXADECIMAL: %X\n", d);
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: HEXADECIMAL: %X\n", d);
	printf("sizeofprintf: %d\n",i);

	printf("-----------------------------\n");

	i = ft_printf("FT: percentual: %%\n");
	printf("sizeofprintf: %d\n",i);
	i = printf("PF: percentual: %%\n");
	printf("sizeofprintf: %d\n",i);*/

	    // Character
    ft_printf("FT: Char: %c\n", 'A');
    printf("PF: Char: %c\n", 'A');

    // String
    ft_printf("FT: String: %s\n", "Hello");
    printf("PF: String: %s\n", "Hello");

    // Pointer
    int x = 42;
    ft_printf("FT: Pointer: %p\n", &x);
    printf("PF: Pointer: %p\n", &x);

    // Signed decimal
    ft_printf("FT: Decimal: %d\n", 42);
    printf("PF: Decimal: %d\n", 42);

    // Unsigned decimal
    ft_printf("FT: Unsigned: %u\n", 123);
    printf("PF: Unsigned: %u\n", 123);

    // Hexadecimal
    ft_printf("FT: Hexadecimal: %x\n", 255);
    printf("PF: Hexadecimal: %x\n", 255);

    ft_printf("FT: HEXADECIMAL: %X\n", 255);
    printf("PF: HEXADECIMAL: %X\n", 255);

    // Percent
    ft_printf("FT: Percent: %%\n");
    printf("PF: Percent: %%\n");

    return 0;
}