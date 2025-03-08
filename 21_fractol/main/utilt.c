/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:48:18 by cgross-s          #+#    #+#             */
/*   Updated: 2025/03/08 23:44:33 by cgross-s         ###   ########.fr       */
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

void	remove_newline(char *str)
{
	int	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len -1] = '\0';
}

void	julia_input(t_data *dt)
{
	char	*msg1;
	char	*inpt1;
	float	finpt1;
	char	*msg2;
	char	*inpt2;
	float	finpt2;

	msg1 = "\nVamos tentar gerar um fractal. Insira o valor real:\n";
	write(1, msg1, ft_strlen(msg1));

	inpt1 = read_line();
	remove_newline(inpt1);
	finpt1 = ft_atof(inpt1);

	msg2 = "\nAgora insira o valor imaginario (sem o i):\n";
	write(1, msg2, ft_strlen(msg2));
	
	inpt2 = read_line();
	remove_newline(inpt2);
	finpt2 = ft_atof(inpt2);

	dt->jreal = finpt1;
	dt->ji = finpt2;

	//msg1 = "(1)\tc = -0.8 + 0.156i\n(2)\tc = -0.7269 + 0.1889i\n";
	//write(1, msg1, ft_strlen(msg1));
	//msg2 = "(3)\tc = -0.1 + 0.651i\n(4)\tc = -0.4 + 0.6i\n";
	//write(1, msg2, ft_strlen(msg2));
	/*dt->jul_set = read_input();
	write(1, "Digit: ", 7);
	write(1, &dt->jul_set, 1);
	write(1, "\n", 1);
	if (dt->jul_set < '1' || dt->jul_set > '4')
	{
		write(1, "ERROR\n", 6);
		exit (1);
	}*/
	define_julia_set(dt);
}

/*void	julia_input(t_data *dt)
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
	dt->jul_set = read_input();
	write(1, "Digit: ", 7);
	write(1, &dt->jul_set, 1);
	write(1, "\n", 1);
	if (dt->jul_set < '1' || dt->jul_set > '4')
	{
		write(1, "ERROR\n", 6);
		exit (1);
	}
	define_julia_set(dt);
}*/

//void	get_input(t_data *data)
void	get_input(t_data *data, char *strarg)
{
	char	*message;
	/*char	*msg0;
	char	*msg1;

	msg0 = "Welcome to FRACTOL\nAt the beginning you must select one type of ";
	write(1, msg0, ft_strlen(msg0));
	msg1 = "fractal set.\nType the correspondent letter to select:\n";
	write(1, msg1, ft_strlen(msg1));*/
	message = "Error: Invalid fractal type: Enter julia, mandelbrot or burning_ship\n";
	//write(1, message, ft_strlen(message));

    if (ft_strcmp(strarg, "julia") == 0)
        data->set = 'J';
    else if (ft_strcmp(strarg, "mandelbrot") == 0)
        data->set = 'M';
    else if (ft_strcmp(strarg, "burning_ship") == 0)
        data->set = 'S';
	else
	{
		write(1, message, ft_strlen(message));
		exit(1);
	}
}

void	put_color_to_pixel(t_data data, int x, int y, int color)
{
	int	*buffer;

	buffer = data.addr;
	buffer[(y * data.line_len / 4) + x] = color;
}

/*void	draw_fractal(t_data *data)
{
	make_fractal(data);
}
*/

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}
