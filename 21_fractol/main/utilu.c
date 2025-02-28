/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:52:27 by cgross-s          #+#    #+#             */
/*   Updated: 2025/02/28 23:52:28 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mf_complement(t_data *dt, int x, int y)
{
	t_complex	c;
	int			color;

	c.real = x / dt->zoom - dt->x_size / (2 * dt->zoom) + dt->offset_x;
	c.i = y / dt->zoom - dt->y_size / (2 * dt->zoom) + dt->offset_y;
	if (dt->set == 'M')
		dt->n_iterations = is_mandelbrot(c, *dt);
	else if (dt->set == 'S')
		dt->n_iterations = is_burning_ship(c, *dt);
	else
		dt->n_iterations = is_julia(c, *dt);
	color = get_color(dt);
	my_mlx_pixel_put(dt, x, y, color);
}

void	make_fractal(t_data *dt)
{
	int			x;
	int			y;

	mlx_clear_window(dt->mlx, dt->win);
	if (dt->img != NULL)
		mlx_destroy_image(dt->mlx, dt->img);
	dt->img = mlx_new_image(dt->mlx, dt->x_size, dt->y_size);
	dt->addr = mlx_get_data_addr(dt->img, &dt->bpp, &dt->line_len, &dt->endian);
	y = 0;
	while (y <= dt->y_size)
	{
		x = 0;
		while (x <= dt->x_size)
		{
			mf_complement(dt, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img, 0, 0);
}
