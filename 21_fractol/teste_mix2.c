#include "testlib.h"
//#include "minilibx-linux/mlx.h"

int handle_close(void *param)
{
    exit (0);
    return (0);
}

void make_julia(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    data->img = mlx_new_image(data->mlx, data->x_size, data->y_size);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);

    int x, y;
    t_complex z;
    
    for (y = 0; y < data->y_size; y++)
    {
        for (x = 0; x < data->x_size; x++)
        {
            // Converte os pixels para coordenadas no espaço do fractal
            z.real = (x - data->x_size / 2) / data->zoom + data->offset_x;
            z.i = (y - data->y_size / 2) / data->zoom + data->offset_y;

            data->n_iterations = is_julia(z, *data);
            int color = get_color(data->n_iterations, data->max_iterations);
            my_mlx_pixel_put(data, x, y, color);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void make_mandelbrot(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    data->img = mlx_new_image(data->mlx, data->x_size, data->y_size);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);

    int x, y;
    t_complex c;
    
    for (y = 0; y < data->y_size; y++)
    {
        for (x = 0; x < data->x_size; x++)
        {
            // Converte os pixels para coordenadas no espaço do fractal
            c.real = (x - data->x_size / 2) / data->zoom + data->offset_x;
            c.i = (y - data->y_size / 2) / data->zoom + data->offset_y;

            data->n_iterations = is_mandelbrot(c, *data);
            int color = get_color(data->n_iterations, data->max_iterations);
            my_mlx_pixel_put(data, x, y, color);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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
/*
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
    
}*/


int handle_mouse(int button, int x, int y, t_data *data)
{
    double zoom_factor = 1.5; // Fator de zoom
    double mouse_x, mouse_y;

    // Converte a posição do mouse para o espaço do fractal antes do zoom
    mouse_x = (x - data->x_size / 2) / data->zoom + data->offset_x;
    mouse_y = (y - data->y_size / 2) / data->zoom + data->offset_y;

    if (button == 4) // Zoom in (scroll para cima)
    {
        data->zoom *= zoom_factor;
    }
    else if (button == 5) // Zoom out (scroll para baixo)
    {
        data->zoom /= zoom_factor;
    }

    // Ajusta o offset para manter o mouse fixo após o zoom
    data->offset_x = mouse_x - (x - data->x_size / 2) / data->zoom;
    data->offset_y = mouse_y - (y - data->y_size / 2) / data->zoom;

    printf("Novo Offset: X=%.5f, Y=%.5f, Zoom=%.2f\n", data->offset_x, data->offset_y, data->zoom);

    // Redesenha o fractal com os novos valores
    if (data->set == 'J')
        make_julia(data);
    else if (data->set == 'M')
        make_mandelbrot(data);

    return (0);
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
    //else if (data.set == 'M')
    //    make_mandelbrot(data);
    
	make_grid(data);
    mlx_hook(data.win, 17, 0, handle_close, NULL); //fecha a janela x
    mlx_key_hook(data.win, handle_keypress, &data); //fechar a janela esc

    mlx_mouse_hook(data.win, handle_mouse, &data);

	mlx_loop(data.mlx);
	return (0);

}
/*
cc teste_mix2.c complex_plane.c utils.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/