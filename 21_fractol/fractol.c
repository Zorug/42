#include "fractol.h"

int handle_close(t_data *data)
//int handle_close(void *param)
{
    //(void)param; // Cast to void to suppress the warning
    //(void)data; // Cast to void to suppress the warning
    if (!data) //verifica se data é NULL
        return (0);

    free_resources(data);
    exit (0);
    return (0);
}


void make_fractal(t_data *data) {

    mlx_clear_window(data->mlx, data->win);
    ///////////////
    //if (data->img) //novo comando para limpar mem
    if (data->img != NULL) // Check for NULL before destroying!
        mlx_destroy_image(data->mlx, data->img);
    //////////////
    data->img = mlx_new_image(data->mlx, data->x_size, data->y_size);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);

    t_complex c;

    for (int y = 0; y <= data->y_size; y++) {
        for (int x = 0; x <= data->x_size; x++) {
            c.real = (double)x / data->zoom - (double)data->x_size / (2.0 * data->zoom) + data->offset_x;
            c.i = (double)y / data->zoom - (double)data->y_size / (2.0 * data->zoom) + data->offset_y;

            if (data->set == 'M')
                data->n_iterations = is_mandelbrot(c, *data);
            else if(data->set == 'S')
                data->n_iterations = is_burning_ship(c, *data);
            else
                data->n_iterations = is_julia(c, *data);
            //int color = get_color(data->n_iterations, data->max_iterations);
            int color = get_color(data);
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
    } else if (button == 1) { // esquerdo do mouse: mudar a cor
        if (data->color == 5)
            data->color = 0;
        else
            data->color++;
        char c = data->color + '0';
        char *str = "Color set: ";
        write(1, str, ft_strlen(str));
        write(1, &c, 1);
        write(1, "\n", 1);
    } 
    else if(button == 3) { //change iteraction number
        change_max_interations(data);
    }
    else {
        return 0; // Ignore other buttons
    }

    data->offset_x = fractal_x_before_zoom - (double)x / data->zoom + (double)data->x_size / (2.0 * data->zoom);
    data->offset_y = fractal_y_before_zoom - (double)y / data->zoom + (double)data->y_size / (2.0 * data->zoom);

    draw_fractal(data);

    return 0;
}

//int handle_keypress(int keycode, void *param)
int handle_keypress(int keycode, t_data *data)
{

    //t_data *data = (t_data *)param;
    double move_factor = 20;

    if (keycode == 65361) // Left arrow
        data->offset_x -= move_factor / data->zoom;
    else if (keycode == 65362) // Up arrow
        data->offset_y -= move_factor / data->zoom;
    else if (keycode == 65363) // Right arrow
        data->offset_x += move_factor / data->zoom;
    else if (keycode == 65364) // Down arrow
        data->offset_y += move_factor / data->zoom;
    else if (keycode == 65307) // ESC key
    {
        mlx_destroy_window(data->mlx, data->win);
        /////////
        free_resources(data);
        //////////
        exit(0);
    }

    draw_fractal(data);

    return (0);
}

int main()
{
    t_data data = {0}; // Inicializa todos os campos com 0 ou NULL
    get_input(&data);

    if (data.set == 'J')
        julia_input(&data);
        
    data_init(&data);

    draw_fractal(&data);

    //mlx_hook(data.win, 17, 0, handle_close, NULL); //fecha a janela x
    mlx_hook(data.win, 17, 0, handle_close, &data); // Passa o ponteiro correto

    mlx_key_hook(data.win, handle_keypress, &data); //fechar a janela esc

    mlx_mouse_hook(data.win, handle_mouse, &data);

    mlx_loop(data.mlx);

    // Garantir que free_resources seja chamada ao sair
    free_resources(&data);
    return 0;
}
/*
cc fractol.c complex_plane.c utils.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/