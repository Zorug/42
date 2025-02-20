#include "testlib.h"

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
    //data->offset_x = -0.5;  // Deslocamento horizontal no plano complexo
    //data->offset_y = 300;   // Deslocamento vertical no plano complexo
    data->offset_y = 0.0;   // Deslocamento vertical no plano complexo
}

/*void init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->x_size, data->y_size, "Fract-ol");
    data->img = mlx_new_image(data->mlx, data->x_size, data->y_size);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, 
        &data->endian);
}*/

/*void init_fractal(t_data *data)
{
    data->x = 0;
    data->y = 0;
    data->color = 0xFCBE11;
    data->zoom = 300;
    data->offset_x = -1.21;
    data->offset_y = -1.21;
    data->max_iterations = 42;
}*/

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

//function to put a pixel in the image
/*void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}*/

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

void get_input(t_data *data)
{
    write(1, "For Julia type J, for Mandelbroot type M:\n", 42);
    if (read(0, &data->set, 1) == -1)
    {
        write(1, "Error to read\n", 14);
        exit (1);
    }
    write(1, "Digit: ", 7);
    write(1, &data->set, 1);
    write(1, "\n", 1);

    if(data->set != 'J' && data->set != 'M')
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