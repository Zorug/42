#ifndef TESTLIB_H
# define TESTLIB_H

//#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_complex
{
    // x
    double real;
    // y
    double i;
} t_complex;

bool is_mandelbrot(t_complex z, t_complex c);

# endif