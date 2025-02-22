#include "testlib.h"
//#include "libft/libft.h"

void data_init(t_data *data)
{
    data->x_size = 800;
    data->y_size = 600;
    data->x_center = data->x_size / 2;
    data->y_center = data->y_size / 2;
    data->zoom = 250.0;
    data->max_iterations = 70;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->x_size, data->y_size, "Fractol 42");
    data->offset_x = 0.0;  // Deslocamento horizontal no plano complexo
    data->offset_y = 0.0;   // Deslocamento vertical no plano complexo
}

int get_color(int iterations, int max_iterations)
{
    if (iterations == max_iterations)
        return 0x000000;
    else
    {
        /*int r = (iterations * 255) / max_iterations;
        int g = (iterations * 255) / max_iterations;
        int b = (iterations * 255) / max_iterations;*/
        int r = (iterations * 255) / max_iterations;
        int g = (iterations * 128) / max_iterations;
        int b = (iterations * 64) / max_iterations;
        return (r << 16) | (g << 8) | b; //combina rgb em um valor de cor
    }
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return (i);
}

void get_input(t_data *data)
{
    char *message;
    message = "For Julia type J, for Mandelbroot type M, for Burning Ship type S:\n"; 
    write(1, message, ft_strlen(message));
    //ft_printf("Teste\n");
    if (read(0, &data->set, 1) == -1)
    {
        write(1, "Error to read\n", 14);
        exit (1);
    }
    write(1, "Digit: ", 7);
    write(1, &data->set, 1);
    write(1, "\n", 1);

    if(data->set != 'J' && data->set != 'M' && data->set != 'S')
    {
        write(1, "ERROR\n", 6);
        exit (1);
    }
}

void put_color_to_pixel(t_data data, int x, int y, int color)
{
    int *buffer;

    buffer = data.addr;
    buffer[(y * data.line_len / 4) + x] = color;
}

void draw_fractal(t_data *data)
{
    if (data->set == 'M')
        make_mandelbrot(data);
    else if (data->set == 'J')
        make_julia(data);
    else if (data->set == 'S')
        make_burning_ship(data);
}