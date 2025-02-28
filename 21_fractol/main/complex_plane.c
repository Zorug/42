/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:42:02 by cgross-s          #+#    #+#             */
/*   Updated: 2025/02/26 21:42:03 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_burning_ship(t_complex c, t_data data)
{
	t_complex	z;
	double		tmp_real;
	int			i;

	z.real = 0;
	z.i = 0;
	i = 0;
	while (i < data.max_iterations)
	{
		tmp_real = z.real * z.real - z.i * z.i + c.real;
		z.i = fabs(2 * z.real * z.i) + c.i;
		z.real = fabs(tmp_real);
		if ((z.real * z.real + z.i * z.i) > 4)
			return (i);
		i++;
	}
	return (data.max_iterations);
}

int	is_mandelbrot(t_complex c, t_data data)
{
	t_complex	z;
	double		tmp_real;
	int			i;

	z.real = 0;
	z.i = 0;
	i = 0;
	while (i <= data.max_iterations)
	{
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		z.real += c.real;
		z.i += c.i;
		data.n_iterations = i;
		if (isnan(z.real) || isnan(z.i) || isinf(z.real) || isinf(z.i))
			return (i);
		i++;
	}
	return (data.max_iterations);
}

int	is_julia(t_complex z, t_data data)
{
	t_complex	c;
	double		tmp_real;
	int			i;

	c.real = data.jreal;
	c.i = data.ji;
	i = 0;
	while (i <= data.max_iterations)
	{
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		z.real += c.real;
		z.i += c.i;
		if (isnan(z.real) || isnan(z.i) || isinf(z.real) || isinf(z.i))
			return (i);
		i++;
	}
	return (data.max_iterations);
}

/*
General formula: z = z² + c
*/