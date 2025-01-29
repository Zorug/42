#include <stdio.h>
#include <unistd.h>

void write_args(int arguments)
{
	char c;
	//int i;

	if (arguments > 9)
		write_args(arguments / 10);
	c = (arguments % 10) + '0';
	write (1, &c, 1);

}

int main(int argc, char **argv)
{
	int arguments;
	arguments = argc -1;
	//printf("argc=%d\n", argc);
	write_args(arguments);
	//printf("arguments = %d", arguments);

	write(1, "\n", 1);
	//printf("\n");
}