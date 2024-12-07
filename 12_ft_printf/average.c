#include <stdarg.h>
#include <stdio.h>

float 	average(int num, ...)
{
	int	total;
	va_list ap;

	total = 0;
	va_start(ap, num);
	for (int i = 0; i < num; ++i)
		total += va_arg(ap, int);
	va_end(ap);
	return (float)total / num;
}

int main()
{
	printf("The average is %.2f\n",
		average(5,  3,4,5,6,78));
}