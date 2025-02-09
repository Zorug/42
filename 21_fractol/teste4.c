#include "testlib.h"
#include "minilibx-linux/mlx.h"

int handle_close(void *param)
{
    exit (0);
    return (0);
}

void make_mandelbrot(t_data data)
{
    mlx_clear_window(data.mlx, data.win); //limpa a janela antes de redesenhar
    t_complex c;
    t_complex t; //temporary for zoom

    int x_repos = data.x_size/2;
    int y_repos = data.y_size/2;

    for (c.i = 0 - y_repos; c.i <= data.y_size - y_repos; c.i++)
        for (c.real = 0 - x_repos; c.real <= data.x_size - x_repos; c.real++)
		{
            t.real = c.real/data.zoom;
            t.i = c.i/data.zoom;
			if(is_mandelbrot(t))
                mlx_pixel_put(data.mlx, data.win, c.real+x_repos, c.i+y_repos, 0xFFFFFF);
		}
}

void make_grid (t_data data)
{
	int x, y;
    int x_repos = data.x_size/2;
    int y_repos = data.y_size/2;

    for (y = 0 - y_repos; y <= data.y_size - y_repos; y++)
        for (x = 0 - x_repos; x <= data.x_size - x_repos; x++)
		{
			if(y == 0 || x == 0)
                mlx_pixel_put(data.mlx, data.win, x+x_repos, y+y_repos, 0xFF0000);
		}
}

int handle_mouse(int button, int x, int y, t_data *data)
{
    if (button == 4) // scroll para cima (zoom in)
    {
        //data->zoom *= 1.1;
        data->zoom *= 20;
        printf("Zoom in: %.2f\n", data->zoom);
    }
    else if (button == 5) //scroll para baixo (zoom out)
    {
        //data->zoom /= 1.1;
        data->zoom /= 20;
        printf("Zoom out: %.2f\n", data->zoom);
    }
    make_mandelbrot(*data);
    make_grid(*data);

    return(0);
}

int main(void)
{
	t_data data;

    data.x_size = 800;
    data.y_size = 600;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.x_size, data.y_size, "Fractol 42");
	data.zoom = 300.0;

	make_mandelbrot(data);
	make_grid(data);
    mlx_hook(data.win, 17, 0, handle_close, NULL); //fecha a janela

    mlx_hook(data.win, 4, 0, handle_mouse, &data);

	mlx_loop(data.mlx);
	return (0);

}
/*
cc teste4.c complex_plane.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/