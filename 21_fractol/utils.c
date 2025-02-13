#include "testlib.h"

void data_init(t_data *data)
{
    data->x_size = 800;
    data->y_size = 600;
    data->x_center = data->x_size/2;
    data->y_center = data->y_size/2;
    data->x_repos = data->x_center;
    data->y_repos = data->y_center;
    data->zoom = 300.0;
    data->max_iterations = 42;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x_size, data->y_size, "Fractol 42");
    data->offset_x = -0.5;  // Para centralizar o Mandelbrot
    data->offset_y = 0.0;   // Ajuste para centralização vertical
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