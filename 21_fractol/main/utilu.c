/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:52:27 by cgross-s          #+#    #+#             */
/*   Updated: 2025/03/09 14:04:28 by cgross-s         ###   ########.fr       */
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
	mlx_clear_window(dt->mlx, dt->win);
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img, 0, 0);
}

double	ft_atof(const char *nptr)
{
	double	int_part;
	double	frac_part;
	double	pow;
	int		sign;

	int_part = 0;
	frac_part = 0;
	sign = 1;
	pow = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	while (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -sign;
	while (*nptr != '.' && *nptr)
		int_part = (int_part * 10) + (*nptr++ - '0');
	if (*nptr == '.')
		nptr++;
	while (*nptr)
	{
		pow /= 10;
		frac_part = frac_part + (*nptr - '0') * pow;
		nptr++;
	}
	return ((int_part + frac_part) * sign);
}

void	rl_complement(t_rdline *rl)
{
	rl->buffer = rl->new_buffer;
	rl->i = 0;
	while (rl->i < rl->bytes_read)
	{
		rl->buffer[rl->total_len + rl->i] = rl->temp[rl->i];
		if (rl->temp[rl->i] == '\n')
		{
			rl->buffer[rl->total_len + rl->i + 1] = '\0';
			rl->block = true;
			return ;
		}
		rl->i++;
	}
}

char	*read_line(void)
{
	t_rdline	rl;

	rl.buffer = NULL;
	rl.total_len = 0;
	rl.bytes_read = read(0, rl.temp, BUFFER_SIZE);
	rl.block = false;
	while (rl.bytes_read > 0 && rl.block == false)
	{
		rl.temp[rl.bytes_read] = '\0';
		rl.new_buffer = realloc(rl.buffer, rl.total_len + rl.bytes_read + 1);
		if (!rl.new_buffer)
		{
			free(rl.buffer);
			return (NULL);
		}
		rl_complement(&rl);
		if (rl.block == false)
		{
			rl.total_len += rl.bytes_read;
			rl.buffer[rl.total_len] = '\0';
			rl.bytes_read = read(0, rl.temp, BUFFER_SIZE);
		}
	}
	return (rl.buffer);
}
