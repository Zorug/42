#include <stdio.h>

typedef struct s_complex
{
    // x
    double real;
    // y
    double i;
} t_complex;

int main()
{
    t_complex z;
    // point 
    t_complex c;
    double tmp_real;

    z.real = 0;
    z.i = 0;

    c.real = 0.25;
    c.i = 0.4;

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

        printf ("iteration n -> %d real %f imaginary %f\n", i, z.real, z.i);
    }
}