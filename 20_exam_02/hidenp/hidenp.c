#include <stdio.h>
#include <unistd.h>

void find_in(char *nail, char *haystack)
{
	while(*haystack)
	{
		if(*nail == *haystack && *nail)
		{
			nail++;
		}
		haystack++;
	}
	if (*nail == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		find_in(argv[1], argv[2]);
	}
	write (1, "\n", 1);
}