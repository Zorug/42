#include "testlib.h"

int is_mandelbrot(t_complex c, t_data data)
{
    t_complex z;
    double tmp_real;

    z.real = 0;
    z.i = 0;

    c.real /= data.zoom; //zooming
    c.i /= data.zoom;
    //c.real = (c.real - data.x_size / 2) / data.zoom + data.offset_x;
    //c.i = (c.i - data.y_size / 2) / data.zoom + data.offset_y;
    //c.real= (c.real / data.zoom) + data.x_repos;
	//c.i = (c.i / data.zoom) + data.y_repos;
    //c.real = (c.real - data.x_size / 2) / data.zoom + data.x_center;
    //c.i = (c.i - data.y_size / 2) / data.zoom + data.y_center;

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
    //z.real = (z.real - data.x_size / 2) / data.zoom + data.offset_x;
    //z.i = (z.i - data.y_size / 2) / data.zoom + data.offset_y;

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

/*
cc teste2.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/