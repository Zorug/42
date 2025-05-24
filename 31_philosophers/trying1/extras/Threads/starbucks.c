#include <stdio.h>
#include <unistd.h>

void	make_coffee(char *name)
{
	printf("Barista %s is making coffee...\n", name);// format:
	sleep(3);// seconds:
	printf("coffee ready!\n");// format:
}

int main()
{
	make_coffee("Luca");// name:
	make_coffee("Paolo");// name:
}