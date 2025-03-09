/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:48:18 by cgross-s          #+#    #+#             */
/*   Updated: 2025/03/09 13:47:41 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	removenl_verifyin(char *str, int optionN, t_data *dt)
{
	int		len;
	char	*msg;

	len = ft_strlen(str);
	msg = "\nError: You must respect the input parameter format.\n";
	if (len > 0 && str[len - 1] == '\n' && optionN == 1)
		str[len -1] = '\0';
	else if (optionN == 2)
	{
		if (*str >= '0' && *str <= '9')
			return ;
		else if (*str == '-' || *str == '+' || *str == '.')
			return ;
		else
		{
			write(1, msg, ft_strlen(msg));
			free(str);
			free_resources(dt);
			exit(1);
		}
	}
}

void	julia_input(t_data *dt)
{
	char	*msg1;
	char	*inpt1;
	char	*msg2;
	char	*inpt2;

	msg1 = "\nTo generate Julia we need a real f value (xx.xx):\n";
	write(1, msg1, ft_strlen(msg1));
	inpt1 = read_line();
	removenl_verifyin(inpt1, 2, dt);
	removenl_verifyin(inpt1, 1, dt);
	dt->jreal = ft_atof(inpt1);
	free(inpt1);
	msg2 = "\nNow you should give a imaginary value (without i):\n";
	write(1, msg2, ft_strlen(msg2));
	inpt2 = read_line();
	removenl_verifyin(inpt2, 2, dt);
	removenl_verifyin(inpt2, 1, dt);
	dt->ji = ft_atof(inpt2);
	free(inpt2);
}

void	get_input(t_data *data, char *strarg)
{
	char	*message;

	message = "Invalid fractal type: Enter julia, mandelbrot or burning_ship\n";
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

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
void	remove_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len -1] = '\0';
}

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
}*/