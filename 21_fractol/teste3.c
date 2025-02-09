#include "testlib.h"
#include "minilibx-linux/mlx.h"

//void make_mandelbrot(int win_size, t_data data)
void make_mandelbrot(t_data data)
{
    t_complex c;
    t_complex t;
    int scale = 150;

    //int repos = win_size/2;
	int repos = data.size/2;

    //for (c.i = 0-repos; c.i <= win_size-repos; c.i++)
	for (c.i = 0-repos; c.i <= data.size-repos; c.i++)
		//for (c.real = 0-repos; c.real <= win_size-repos; c.real++)
		for (c.real = 0-repos; c.real <= data.size-repos; c.real++)
		{
            t.real = c.real/scale;
            t.i = c.i/scale;
			if(is_mandelbrot(t))
				mlx_pixel_put(data.mlx, data.win, c.real+repos, c.i+repos, 0xFFFFFF);
		}
}

//void make_grid (int win_size, t_data data)
void make_grid (t_data data)
{
	//int x, y, repos = win_size/2;
	int x, y, repos = data.size/2;

	//for (y = 0-repos; y <= win_size-repos; y++)
	for (y = 0-repos; y <= data.size-repos; y++)
		//for (x = 0-repos; x <= win_size-repos; x++)
		for (x = 0-repos; x <= data.size-repos; x++)
		{
			if(y == 0 || x == 0)
				mlx_pixel_put(data.mlx, data.win, x+repos, y+repos, 0xFF0000);
		}
}

/*int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}*/

int main(void)
{
	t_data data;

    //int win_size = 500;
	data.size = 500;

	data.mlx = mlx_init();
	//data.win = mlx_new_window(data.mlx, win_size, win_size, "mlx 42");
	data.win = mlx_new_window(data.mlx, data.size, data.size, "mlx 42");
	//data.zoom = 1.0;

	//make_mandelbrot(win_size, data);
	make_mandelbrot(data);

	//make_grid (win_size, data);
	make_grid (data);

	mlx_loop(data.mlx);

	return (0);

}
/*
cc teste3.c complex_plane.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/