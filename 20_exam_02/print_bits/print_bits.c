#include <stdio.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	//int i = 0;
	int b_size = 2, bit_size = 8;
	char *base = "01";
	char octebits[9];
	char c;

	if (octet == 0)
	{
		write(1, "00000000", 8);
		return ;
	}
	octebits[bit_size] = '\0';
	bit_size--;
	while(octet)
	{
		//printf("%d\t%d\n",octet, octet%b_size);
		c = octet%b_size + '0';
		//write (1, &c, 1);
		//printf("%c\t%d\t%c\n", c, bit_size, octebits[bit_size]);
		octebits[bit_size] = c;
		octet = octet/b_size;
		bit_size--;
	}
	while (bit_size >= 0)
	{
		octebits[bit_size] = '0';
		bit_size--;
	}
	write(1, octebits, 8);
}

/*int main()
{
	unsigned char octet;

	octet = 0;
	print_bits(octet);
	write(1, "\n", 1);

	octet = 2;
	print_bits(octet);
	write(1, "\n", 1);

	octet = 42;
	print_bits(octet);
	write(1, "\n", 1);

	octet = 255;
	print_bits(octet);
	write(1, "\n", 1);
}
*/
/*0	00000000
1	00000001
2	00000010
5	00000101
42	00101010
128	10000000
255	11111111*/