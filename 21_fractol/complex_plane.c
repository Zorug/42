#include "testlib.h"

int is_mandelbrot(t_complex c, t_data data)
{
    t_complex z;
    double tmp_real;

    z.real = 0;
    z.i = 0;

    c.real /= data.zoom; //zooming
    c.i /= data.zoom;

    for (int i = 0; i <= data.max_iterations; ++i)
    {
        //General formula: z = z² + c
        tmp_real = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.real * z.i;
        z.real = tmp_real;

        z.real += c.real; //Adding the c value
        z.i += c.i;

        data.n_iterations = i;

        if (isnan(z.real) || isnan(z.i) || isinf(z.real) || isinf(z.i))
            return i;
    }
    return data.max_iterations;
}

int is_julia(t_complex z, t_data data)
{
    t_complex c;
    double tmp_real;

    c.real = -0.8;
    c.i = 0.156;

    z.real /= data.zoom; //zooming
    z.i /= data.zoom;

    for (int i = 0; i <= data.max_iterations; ++i)
    {
        //General formula: z = z² + c
        tmp_real = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.real * z.i;
        z.real = tmp_real;

        z.real += c.real; //Adding the c value
        z.i += c.i;

        if (isnan(z.real) || isnan(z.i) || isinf(z.real) || isinf(z.i))
            return i;
    }

    return data.max_iterations;
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
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

/*
cc teste2.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/