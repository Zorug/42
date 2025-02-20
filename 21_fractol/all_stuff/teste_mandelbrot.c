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

    for (c.i = 0 - data.y_repos; c.i <= data.y_size - data.y_repos; c.i++)
        for (c.real = 0 - data.x_repos; c.real <= data.x_size - data.x_repos; c.real++)
		{
            /*if(is_mandelbrot(c, data))
                mlx_pixel_put(data.mlx, data.win, c.real+data.x_repos, c.i+data.y_repos, 0xFFFFFF);
            */
            data.n_iterations = is_mandelbrot(c, data);
            int color = get_color(data.n_iterations, data.max_iterations);
            mlx_pixel_put(data.mlx, data.win, c.real + data.x_repos, c.i + data.y_repos, color);
		}
}

void make_grid (t_data data)
{
	int x, y;

    for (y = 0 - data.y_repos; y <= data.y_size - data.y_repos; y++)
        for (x = 0 - data.x_repos; x <= data.x_size - data.x_repos; x++)
		{
			if(y == 0 || x == 0)
                mlx_pixel_put(data.mlx, data.win, x+data.x_repos, y+data.y_repos, 0xFF0000);
		}
}

int handle_mouse(int button, int x, int y, t_data *data)
{
    if (button == 4) // scroll para cima (zoom in)
    {
        data->zoom *= 2;
        printf("Zoom in: %.2f\n", data->zoom);
    }
    else if (button == 5) //scroll para baixo (zoom out)
    {
        data->zoom /= 2;
        printf("Zoom out: %.2f\n", data->zoom);
    }
    make_mandelbrot(*data);
    make_grid(*data);

    return(0);
}

int handle_keypress(int keycode, void *param)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(((t_data *)param)->mlx, ((t_data *)param)->win);
        exit(0);
    }
    return (0);
}

int main(void)
{
	t_data data;

    data.x_size = 800;
    data.y_size = 600;
    data.x_repos = data.x_size/2;
    data.y_repos = data.y_size/2;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.x_size, data.y_size, "Fractol 42");
	data.zoom = 300.0;
    data.max_iterations = 42;

	make_mandelbrot(data);
	make_grid(data);
    mlx_hook(data.win, 17, 0, handle_close, NULL); //fecha a janela x
    mlx_key_hook(data.win, handle_keypress, &data); //fechar a janela esc

    mlx_mouse_hook(data.win, handle_mouse, &data);

	mlx_loop(data.mlx);
	return (0);

}
/*
cc teste_mandelbrot.c complex_plane.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol_man
*/