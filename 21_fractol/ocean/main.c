#include "fractol.h"

int main(int ac, char **av)
{
	if (2 == ac !ft_strcmp(av[1], "mandelbrot", 10)
		|| 4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		//prompt correct
	}
	else
	{
		putrstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}