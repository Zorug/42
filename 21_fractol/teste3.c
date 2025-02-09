#include "testlib.h"
#include "minilibx-linux/mlx.h"

void make_mandelbrot(int win_size, void *mlx_ptr, void *win_ptr)
{
    //int x, y, 
    t_complex c;
    t_complex t;
    int scale = 150;
    int repos = win_size/2;

    for (c.i = 0-repos; c.i <= win_size-repos; c.i++)
		for (c.real = 0-repos; c.real <= win_size-repos; c.real++)
		{
            t.real = c.real/scale;
            t.i = c.i/scale;
			if(is_mandelbrot(t))
				mlx_pixel_put(mlx_ptr, win_ptr, c.real+repos, c.i+repos, 0xFFFFFF);
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

    int win_size = 500;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, win_size, win_size, "mlx 42");

    make_mandelbrot(win_size, mlx_ptr, win_ptr);

    make_grid (win_size, mlx_ptr, win_ptr);

	mlx_loop(mlx_ptr);

	return (0);

}
/*
cc teste3.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/