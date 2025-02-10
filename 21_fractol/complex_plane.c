#include "testlib.h"

bool is_mandelbrot(t_complex c, t_data data)
{
    t_complex z;
    double tmp_real;

    z.real = 0;
    z.i = 0;

    c.real = c.real/data.zoom; //zooming
    c.i = c.i/data.zoom;

    for (int i = 0; i < 42; ++i)
    {
        //General formula: z = z² + c
        tmp_real = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.real * z.i;
        z.real = tmp_real;

        z.real += c.real; //Adding the c value
        z.i += c.i;

        //printf ("iteration n -> %d\treal %.2f\timaginary %.2f\n", i, z.real, z.i);
        //printf("real=%f\ti=%f\n", c.real, c.i);

        if (isnan(z.real) || isnan(z.i) || isinf(z.real) || isinf(z.i))
        {
            //printf("\n----------CRASH!--------\n");
            return false;
        }
    }
    return true;
}

bool is_julia(t_complex z, t_data data)
{
    t_complex c;
    double tmp_real;

    c.real = -0.8;
    c.i = 0.156;

    c.real = c.real/data.zoom; //zooming
    c.i = c.i/data.zoom;

    for (int i = 0; i < 42; ++i)
    {
        //General formula: z = z² + c
        tmp_real = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.real * z.i;
        z.real = tmp_real;

        z.real += c.real; //Adding the c value
        z.i += c.i;

        //printf ("iteration n -> %d\treal %.2f\timaginary %.2f\n", i, z.real, z.i);
        //printf("real=%f\ti=%f\n", c.real, c.i);

        if (isnan(z.real) || isnan(z.i) || isinf(z.real) || isinf(z.i))
        {
            //printf("\n----------CRASH!--------\n");
            return false;
        }
    }
    return true;
}

/*int main()
{
    // point 
    t_complex c;

    c.real = 5;
    c.i = 2;

    if (is_mandelbrot(c))
        printf("True\n");
    else
        printf("False\n");

}*/
/*
cc teste2.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/