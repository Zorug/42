# include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	unsigned int pow;

	pow = 2;
	//printf("num: %u\n", n);
	//printf("num: %i\n", n);
	if((int)n < 0)
		return (0);
	if((int)n == 1)
		return (1);
	while (pow <= n)
	{
		if (pow == n)
			return (1);
		else
			pow = pow * 2;
	}
	return (0);
}

/*int main ()
{
	printf("%d\n\n", is_power_of_2(2));
	printf("%d\n\n", is_power_of_2(3));
	printf("%d\n\n", is_power_of_2(-2));
	printf("%d\n\n", is_power_of_2(16));
	printf("%d\n\n", is_power_of_2(0));
	printf("%d\n\n", is_power_of_2(1));
	printf("%d\n\n", is_power_of_2(1024));
}*/