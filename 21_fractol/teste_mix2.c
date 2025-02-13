#include "testlib.h"
//#include "minilibx-linux/mlx.h"

int handle_close(void *param)
{
    exit (0);
    return (0);
}

void make_julia(t_data data)
{
    t_img jul;

    mlx_clear_window(data.mlx, data.win); //limpa a janela antes de redesenhar

    jul.img = mlx_new_image(data.mlx, data.x_size, data.y_size);//creating image
    jul.addr = mlx_get_data_addr(jul.img, &jul.bpp, &jul.line_len, &jul.endian);//getting pixels adress

    t_complex c;

    for (c.i = 0 - data.y_repos; c.i <= data.y_size - data.y_repos; c.i++)
        for (c.real = 0 - data.x_repos; c.real <= data.x_size - data.x_repos; c.real++)
		{
            data.n_iterations = is_julia(c, data);
            int color = get_color(data.n_iterations, data.max_iterations);
            //mlx_pixel_put(data.mlx, data.win, c.real + data.x_repos, c.i + data.y_repos, color);
            my_mlx_pixel_put(&jul, c.real + data.x_repos, c.i + data.y_repos, color);
		}
    //show window
    mlx_put_image_to_window(data.mlx, data.win, jul.img, 0, 0);

    //printf("repos: x = %d, y = %d\n", data.x_repos, data.y_repos);
}

void make_mandelbrot(t_data data)
{
    t_img man;
    
    mlx_clear_window(data.mlx, data.win); //limpa a janela antes de redesenhar

    man.img = mlx_new_image(data.mlx, data.x_size, data.y_size); //creating new image
    man.addr = mlx_get_data_addr(man.img, &man.bpp, &man.line_len, &man.endian); //getting pixels adress

    t_complex c;

    for (c.i = 0 - data.y_repos; c.i <= data.y_size - data.y_repos; c.i++)
        for (c.real = 0 - data.x_repos; c.real <= data.x_size - data.x_repos; c.real++)
		{
            data.n_iterations = is_mandelbrot(c, data);
            int color = get_color(data.n_iterations, data.max_iterations);
            //mlx_pixel_put(data.mlx, data.win, c.real + data.x_repos, c.i + data.y_repos, color);
            my_mlx_pixel_put(&man, c.real + data.x_repos, c.i + data.y_repos, color);
		}
    //show window
    mlx_put_image_to_window(data.mlx, data.win, man.img, 0, 0);

    //printf("repos: x = %d, y = %d\n", data.x_repos, data.y_repos);
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

void center_reposition(t_data *data)
{
    int x, y;
    mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
    printf("Mouse pos: X=%d, Y=%d\n", x, y);
    //if (x > data->x_repos)
    //    data->x_repos = data->x_repos - (x - data->x_repos);
    //else if (x < data->x_repos)
    //data->x_repos = 0;
    //data->y_repos = 0;

    data->x_repos = data->x_repos - (x - data->x_repos);//zoom in working
    data->y_repos = data->y_repos - (y - data->y_repos);

    //data->x_repos = (data->x_center - (x - data->x_repos));
    //data->y_repos = (data->y_center - (y - data->y_repos));
    //printf("repos inside function: x = %d, y = %d\n", data->x_repos, data->y_repos);

    //data->x_repos = x;//posiciona o eixo no ponto do mouse
    //data->y_repos = y;
    
}

int handle_mouse(int button, int x, int y, t_data *data)
{
    int x_buffer = data->x_repos, y_buffer = data->y_repos;

    if (button == 5) // scroll para cima (zoom in)
    {
        data->zoom *= 0.5;
        printf("Zoom out: %.2f\n", data->zoom);
        //mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
        //printf("Mouse pos: X=%d, Y=%d\n", x, y);
        //data->x_repos = data->x_size/2 - x;
        //data->y_repos = data->y_size/2 - y;
        center_reposition(data);
    }
    else if (button == 4) //scroll para baixo (zoom out)
    {
        data->zoom *= 1.5;
        printf("Zoom in: %.2f\n", data->zoom);
        //mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
        //printf("Mouse pos: X=%d, Y=%d\n", x, y);
        //data->x_repos = data->x_size/2 - x;
        //data->y_repos = data->y_size/2 - y;
        center_reposition(data);
    }
    if (data->set == 'J')
        make_julia(*data);
    else if (data->set == 'M')
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

    write(1, "For Julia type J, for Mandelbroot type M:\n", 42);
    if (read(0, &data.set, 1) == -1)
    {
        write(1, "Error to read\n", 14);
        return (1);
    }
    write(1, "Digit: ", 7);
    write(1, &data.set, 1);
    write(1, "\n", 1);

    if(data.set != 'J' && data.set != 'M')
    {
        write(1, "ERROR\n", 6);
        return (1);
    }

    data_init(&data);

	if (data.set == 'J')
        make_julia(data);
    else if (data.set == 'M')
        make_mandelbrot(data);
	make_grid(data);
    mlx_hook(data.win, 17, 0, handle_close, NULL); //fecha a janela x
    mlx_key_hook(data.win, handle_keypress, &data); //fechar a janela esc

    mlx_mouse_hook(data.win, handle_mouse, &data);

	mlx_loop(data.mlx);
	return (0);

}
/*
cc teste_mix2.c complex_plane.c utils.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol_mix
*/