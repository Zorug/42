#include "testlib.h"

bool is_mandelbrot(t_complex c)
{
    t_complex z;
    double tmp_real;

    z.real = 0;
    z.i = 0;

    //c.real = c.real/scale;
    //c.i = c.i/scale;

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

        //printf ("iteration n -> %d\treal %.2f\timaginary %.2f\n", i, z.real, z.i);

        if (isnan(z.real) || isnan(z.i) || isinf(z.real) || isinf(z.i))
        {
            printf("\n----------CRASH!--------\n");
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