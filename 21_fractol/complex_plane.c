#include "testlib.h"

bool is_mandelbrot(t_complex z, t_complex c)
{
    double tmp_real;

    for (int i = 0; i < 42; ++i)
    {
        //General formula
        // z = z² + c
        tmp_real = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.real * z.i;
        z.real = tmp_real;

        //Adding the c value
        z.real += c.real;
        z.i += c.i;

        printf ("iteration n -> %d\treal %.2f\timaginary %.2f\n", i, z.real, z.i);

        if (isnan(z.real) || isnan(z.i) || isinf(z.real) || isinf(z.i))
        {
            printf("\n----------CRASH!--------\n");
            return false;
        }
    }
    return true;
}

int main()
{
    t_complex z;
    // point 
    t_complex c;

    z.real = 0;
    z.i = 0;

    c.real = 5;
    c.i = 2;

    if (is_mandelbrot(z, c))
        printf("True\n");
    else
        printf("False\n");

}
/*
cc teste2.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/