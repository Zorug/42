#include "fractol.h"

int is_burning_ship(t_complex c, t_data data)
{
    t_complex z;
    double tmp_real;
    int i;

    z.real = 0;
    z.i = 0;
    i = 0;

    while (i < data.max_iterations)
    {
        tmp_real = z.real * z.real - z.i * z.i + c.real;
        z.i = fabs(2 * z.real * z.i) + c.i;  // Applying absolute value
        z.real = fabs(tmp_real);             // Applying absolute value

        if ((z.real * z.real + z.i * z.i) > 4) // Escape condition
            return i;
        i++;
    }
    return data.max_iterations;
}

int is_mandelbrot(t_complex c, t_data data)
{
    t_complex z;
    double tmp_real;

    z.real = 0;
    z.i = 0;

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

    c.real = data.jreal;
    c.i = data.ji;

    for (int i = 0; i <= data.max_iterations; ++i)
    {
        // Fórmula geral: z = z² + c
        tmp_real = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.real * z.i;
        z.real = tmp_real;

        z.real += c.real; // Adicionando o valor de c
        z.i += c.i;

        if (isnan(z.real) || isnan(z.i) || isinf(z.real) || isinf(z.i))
            return i;
    }
    return data.max_iterations;
}

/*
cc teste2.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/