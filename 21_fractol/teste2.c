#include "minilibx-linux/mlx.h"
#include <math.h>

void one_by_one (int size, void *mlx_ptr, void *win_ptr)
{
	int x, y, repos = size/2;

	for (y = 0-repos; y <= size-repos; y++)
		for (x = 0-repos; x <= size-repos; x++)
		{
			if(sqrt(pow(x,2)+pow(y,2)) <= 100)
				mlx_pixel_put(mlx_ptr, win_ptr, x+repos, y+repos, 0xFFCC00);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, x+repos, y+repos, 0xFFFFFF);
		}
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	//range de -250 a 250: -2.5 a 2.5
	// exemplo c = -0.5 e 0.2i
	//float point

	int size = 500;

	//int x0 = 0, i0 = 0;
	//int cnvrs = 250;
	//int multiply = 100;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, size, size, "mlx 42");

	one_by_one (size, mlx_ptr, win_ptr);

	//mlx_pixel_put(mlx_ptr, win_ptr, (250), (250), 0xFFFFFF);
	//mlx_pixel_put(mlx_ptr, win_ptr, (150), (150), 0xFFCC00);
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}

/*cc teste2.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol*/