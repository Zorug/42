#include <stdio.h>
#include <stdlib.h>

void do_it(int v1, int v2)
{
	int result = 1;
	int i = 1, maxi;
	if (v1 <= v2)
		maxi = v1;
	else
		maxi = v2;
	while (i <= maxi)
	{
		if (!(v1%i) && !(v2%i))
		{
			result = i;
			//printf("%d\t",result);
		}
		i++;
	}
	printf("%d",result);
}

int main (int argc, char** argv)
{
	int v1, v2;

	if (argc == 3)
	{
		v1 = atoi(argv[1]);
		v2 = atoi(argv[2]);
		do_it(v1, v2);
	}	
	printf("\n");
}