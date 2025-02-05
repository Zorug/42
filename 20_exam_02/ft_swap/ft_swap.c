#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;
	//printf("%d, %d\n", *a, *b);
	temp = *a;
	*a = *b;
	*b = temp;
	//printf("%d, %d\n", *a, *b);
}

/*int main()
{
	int pa, pb;

	pa = 1;
	pb = 2;

	//printf("%d, %d\n", &pa, &pb);

	ft_swap(&pa, &pb);
}
*/