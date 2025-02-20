#include "testlib.h"

int handle_keypress(int keycode, void *param)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(((t_data *)param)->mlx, ((t_data *)param)->win);
        exit(0);
    }
    return (0);
}

int handle_close(void *param)
{
    exit (0);
    return (0);
}

void make_grid (t_data *data)
{
    for (int y = 0 - data->offset_y; y <= data->y_size - data->offset_y; y++)
        for (int x = 0 - data->offset_x; x <= data->x_size - data->offset_x; x++)
		{
			if(y == 0 || x == 0)
                mlx_pixel_put(data->mlx, data->win, x+data->offset_x, y+data->offset_y, 0xFF0000);
		}
}

void make_mandelbrot(t_data *data) {
    mlx_clear_window(data->mlx, data->win);
    data->img = mlx_new_image(data->mlx, data->x_size, data->y_size);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);

    t_complex c;

    for (int y = 0; y < data->y_size; y++) {
        for (int x = 0; x < data->x_size; x++) {
            c.real = (double)x / data->zoom - (double)data->x_size / (2.0 * data->zoom) + data->offset_x;
            c.i = (double)y / data->zoom - (double)data->y_size / (2.0 * data->zoom) + data->offset_y;

            data->n_iterations = is_mandelbrot(c, *data);
            int color = get_color(data->n_iterations, data->max_iterations);
            my_mlx_pixel_put(data, x, y, color); 
        }
    }

    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int handle_mouse(int button, int x, int y, t_data *data) {
    double zoom_factor = 1.5;

    double fractal_x_before_zoom = (double)x / data->zoom - (double)data->x_size / (2.0 * data->zoom) + data->offset_x;
    double fractal_y_before_zoom = (double)y / data->zoom - (double)data->y_size / (2.0 * data->zoom) + data->offset_y;


    if (button == 4) { // Zoom in
        data->zoom *= zoom_factor;
    } else if (button == 5) { // Zoom out
        data->zoom /= zoom_factor;
    } else {
        return 0; // Ignore other buttons
    }

    data->offset_x = fractal_x_before_zoom - (double)x / data->zoom + (double)data->x_size / (2.0 * data->zoom);
    data->offset_y = fractal_y_before_zoom - (double)y / data->zoom + (double)data->y_size / (2.0 * data->zoom);

    make_mandelbrot(data);  // Redraw with the new zoom and offset
    make_grid(data);

    return 0;
}

int main()
{
    t_data data;

    data_init(&data);

    make_mandelbrot(&data);

    make_grid(&data);

    mlx_hook(data.win, 17, 0, handle_close, NULL); //fecha a janela x
    mlx_key_hook(data.win, handle_keypress, &data); //fechar a janela esc

    mlx_mouse_hook(data.win, handle_mouse, &data);


    mlx_loop(data.mlx);
}
/*
cc fromzero.c complex_plane.c utils.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/