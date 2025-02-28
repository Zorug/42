/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:48:18 by cgross-s          #+#    #+#             */
/*   Updated: 2025/02/28 20:48:19 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	define_julia_set(t_data *data)
{
	if (data->jul_set == '1')
	{
		data->jreal = -0.8;
		data->ji = 0.156;
	}
	else if (data->jul_set == '2')
	{
		data->jreal = -0.7269;
		data->ji = 0.1889;
	}
	else if (data->jul_set == '3')
	{
		data->jreal = -0.1;
		data->ji = 0.651;
	}
	else if (data->jul_set == '4')
	{
		data->jreal = -0.4;
		data->ji = 0.6;
	}
}

void	julia_input(t_data *data)
{
	char	*msg0;
	char	*msg1;
	char	*msg2;

	msg0 = "\nYou selected Julia Set.\nSelect one of the following sets:\n";
	write(1, msg0, ft_strlen(msg0));
	msg1 = "(1)\tc = -0.8 + 0.156i\n(2)\tc = -0.7269 + 0.1889i\n";
	write(1, msg1, ft_strlen(msg1));
	msg2 = "(3)\tc = -0.1 + 0.651i\n(4)\tc = -0.4 + 0.6i\n";
	write(1, msg2, ft_strlen(msg2));
	data->jul_set = read_input();
	write(1, "Digit: ", 7);
	write(1, &data->jul_set, 1);
	write(1, "\n", 1);
	if (data->jul_set < '1' && data->jul_set > '4')
	{
		write(1, "ERROR\n", 6);
		exit (1);
	}
	define_julia_set(data);
}

void	get_input(t_data *data)
{
	char	*message;
	char	*msg0;
	char	*msg1;

	msg0 = "Welcome to FRACTOL\nAt the beginning you must select one type of ";
	write(1, msg0, ft_strlen(msg0));
	msg1 = "fractal set.\nType the correspondent letter to select:\n";
	write(1, msg1, ft_strlen(msg1));
	message = "(J)\tJulia\n(M)\tMandelbroot\n(S)\tBurning Ship\n";
	write(1, message, ft_strlen(message));
	data->set = read_input();
	write(1, "Digit: ", 7);
	write(1, &data->set, 1);
	write(1, "\n", 1);
	if (data->set != 'J' && data->set != 'M' && data->set != 'S')
	{
		write(1, "ERROR\n", 6);
		exit (1);
	}
}

void	put_color_to_pixel(t_data data, int x, int y, int color)
{
	int	*buffer;

	buffer = data.addr;
	buffer[(y * data.line_len / 4) + x] = color;
}

void	draw_fractal(t_data *data)
{
	make_fractal(data);
}
