/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:41:47 by cgross-s          #+#    #+#             */
/*   Updated: 2025/02/26 21:41:49 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# define M_PI           3.14159265358979323846  /* pi */
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	int		x_size;
	int		y_size;
	int		x_center;
	int		y_center;
	int		n_iterations;
	char	set;
	char	jul_set;
	double	jreal;
	double	ji;

	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		max_iterations;

}	t_data;

int		is_mandelbrot(t_complex c, t_data data);
int		is_julia(t_complex z, t_data data);
int		is_burning_ship(t_complex c, t_data data);

int		get_color(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

char	read_input(void);
void	get_input(t_data *data);
void	julia_input(t_data *data);
void	data_init(t_data *data);

void	put_color_to_pixel(t_data data, int x, int y, int color);
void	init_fractal(t_data *data);
void	init_mlx(t_data *data);

void	draw_fractal(t_data *data);

void	make_fractal(t_data *data);

int		ft_strlen(char *str);
void	define_julia_set(t_data *data);

void	change_max_interations(t_data *data);
void	free_resources(t_data *data);

double	ft_atof(const char *nptr);

#endif
