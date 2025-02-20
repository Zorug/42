#ifndef TESTLIB_H
# define TESTLIB_H

#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_complex
{
    double real; // x
    double i; // y
} t_complex;

typedef struct s_data
{
    void *mlx;
    void *win;
    void *img;
    void *addr; //pointer to image
    int bpp; //bits per pixel
    int line_len; //line size
    int endian;

    int x_size;
    int y_size;
    //int x_repos;  // 🔥 Adicionado para posicionamento na tela
    //int y_repos;  // 🔥 Adicionado
    int x_center; // 🔥 Adicionado
    int y_center; // 🔥 Adicionado
    int n_iterations;
    char set;

    int x;
    int y;
    double zx;
    double zy;
    double cx;
    double cy;
    int color;
    double offset_x;
    double offset_y;
    double zoom;
    char *name;
    int max_iterations;

} t_data;

int is_mandelbrot(t_complex c, t_data data);
int is_julia(t_complex z, t_data data);
int get_color(int iterations, int max_iterations);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
//void my_mlx_pixel_put(t_img *img, int x, int y, int color);

//void get_input(t_data data);
void get_input(t_data *data);
void data_init(t_data *data);

void put_color_to_pixel(t_data data, int x, int y, int color);
void init_fractal(t_data *data);
void init_mlx(t_data *data);

/*typedef struct s_img
{
    void *img;
    char *addr;
    int bpp;
    int line_len;
    int endian;
} t_img;*/

/*typedef struct s_data
{
    void *mlx; //ponteiro para conexão MiniLibX
    void *win; //Ponteiro para a janela MiniLibx

    double zoom;
    int x_size; //screen size
    int y_size; //screen size
    int x_repos; //screen size
    int y_repos; //screen size
    int x_center;
    int y_center;

    double offset_x;  // Deslocamento horizontal do fractal
    double offset_y;  // Deslocamento vertical do fractal

    int max_iterations;
    int n_iterations; //iterations to scape

    char set; //set type
} t_data;*/

# endif