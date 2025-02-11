#ifndef TESTLIB_H
# define TESTLIB_H

//#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_complex
{
    double real; // x
    double i; // y
} t_complex;

typedef struct s_data
{
    void *mlx; //ponteiro para conexão MiniLibX
    void *win; //Ponteiro para a janela MiniLibx
    double zoom;
    int x_size; //screen size
    int y_size; //screen size
    int x_repos; //screen size
    int y_repos; //screen size
    int max_iterations;
    int n_iterations; //iterations to scape
} t_data;

//bool is_mandelbrot(t_complex c, t_data data);
int is_mandelbrot(t_complex c, t_data data);
//bool is_julia(t_complex z, t_data data);
int is_julia(t_complex z, t_data data);
int get_color(int iterations, int max_iterations);

# endif