/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_interac.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:13:56 by cgross-s          #+#    #+#             */
/*   Updated: 2025/02/28 20:13:57 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cmi_complement(t_data *data, int value, char *str)
{
	data->max_iterations = value;
	write(1, str, ft_strlen(str));
}

void	change_max_interations(t_data *data)
{
	if (data->max_iterations == 25)
		cmi_complement(data, 60, "max_iterations = 60\n");
	else if (data->max_iterations == 60)
		cmi_complement(data, 150, "max_iterations = 150\n");
	else if (data->max_iterations == 150)
		cmi_complement(data, 400, "max_iterations = 400\n");
	else if (data->max_iterations == 400)
		cmi_complement(data, 1000, "max_iterations = 1000\n");
	else if (data->max_iterations == 1000)
		cmi_complement(data, 5000, "max_iterations = 5000\n");
	else
		cmi_complement(data, 25, "max_iterations = 25\n");
}

void	gc_complement_one(int *r, int *g, int *b, t_data *data)
{
	double	t;

	t = (double)data->n_iterations / data->max_iterations;
	if (data->color == 0)
	{
		*r = 255 * t;
		*g = 255 * t;
		*b = 255 * t;
	}
	else if (data->color == 1)
	{
		*r = 255 * t;
		*g = 128 * t;
		*b = 64 * t;
	}
	else if (data->color == 2)
	{
		*r = (int)(255 * (sin(t * M_PI * 4) + 1) / 2);
		*g = (int)(255 * (cos(t * M_PI * 4) + 1) / 2);
		*b = (int)(255 * (sin(t * M_PI * 6) + 1) / 2);
	}
}

void	gc_complement_two(int *r, int *g, int *b, t_data *data)
{
	double	t;

	t = (double)data->n_iterations / data->max_iterations;
	if (data->color == 3)
	{
		*r = (int)(255 * t * 0.2);
		*g = (int)(255 * t * 0.8);
		*b = (int)(255 * t * 0.6);
	}
	else if (data->color == 4)
	{
		*r = (int)(sin(5 * t) * 127 + 128);
		*g = (int)(sin(7 * t) * 127 + 128);
		*b = (int)(sin(11 * t) * 127 + 128);
	}
	else
	{
		*r = (data->n_iterations * 9) % 256;
		*g = (data->n_iterations * 2) % 256;
		*b = (data->n_iterations * 5) % 256;
	}
}

int	get_color(t_data *data)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)data->n_iterations / data->max_iterations;
	if (data->n_iterations == data->max_iterations)
		return (0x000000);
	if (data->color < 3)
		gc_complement_one(&r, &g, &b, data);
	else
		gc_complement_two(&r, &g, &b, data);
	return ((r << 16) | (g << 8) | b);
}
