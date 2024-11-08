#include "libft.h"


int main()
{
	const char *str = "teste";
	char ch = 'e';

	char *result = ft_strchr(str, ch);
	if (result != NULL)
		printf("Character '%c' found at position: %ld\n", ch, result - str);
	else
		printf("Character '%c' not found\n", ch);

	return 0;
}