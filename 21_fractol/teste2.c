#include "testlib.h"
#include "minilibx-linux/mlx.h"

void make_circle (int win_size, int ray, void *mlx_ptr, void *win_ptr)
{
	int x, y, repos = win_size/2;

	for (y = 0-repos; y <= win_size-repos; y++)
		for (x = 0-repos; x <= win_size-repos; x++)
		{
			if(sqrt(pow(x,2)+pow(y,2)) >= ray-1 && 
				sqrt(pow(x,2)+pow(y,2)) <= ray)
				mlx_pixel_put(mlx_ptr, win_ptr, x+repos, y+repos, 0xFFFFFF);
		}
}

void make_grid (int win_size, void *mlx_ptr, void *win_ptr)
{
	int x, y, repos = win_size/2;

	for (y = 0-repos; y <= win_size-repos; y++)
		for (x = 0-repos; x <= win_size-repos; x++)
		{
			if(y == 0 || x == 0)
				mlx_pixel_put(mlx_ptr, win_ptr, x+repos, y+repos, 0xFF0000);
		}
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	//range de -250 a 250: -2.5 a 2.5
	// exemplo c = -0.5 e 0.2i
	//float point

	int win_size = 500;
	int c_ray;

	//int x0 = 0, i0 = 0;
	//int cnvrs = 250;
	//int multiply = 100;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, win_size, win_size, "mlx 42");

	for (c_ray = 25; c_ray <= 200; c_ray += 25)
		make_circle (win_size, c_ray, mlx_ptr, win_ptr);
	make_grid (win_size, mlx_ptr, win_ptr);

	//mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

	//mlx_pixel_put(mlx_ptr, win_ptr, (250), (250), 0xFFFFFF);
	//mlx_pixel_put(mlx_ptr, win_ptr, (150), (150), 0xFFCC00);
	//mlx_key_hook(win_ptr, deal_key, (void *)0);


	mlx_loop(mlx_ptr);

	return (0);
}

/*
cc teste2.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/