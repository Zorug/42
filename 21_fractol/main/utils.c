/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:42:10 by cgross-s          #+#    #+#             */
/*   Updated: 2025/03/09 12:32:20 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	data_init(t_data *data)
{
	data->x_size = 800;
	data->y_size = 600;
	data->x_center = data->x_size / 2;
	data->y_center = data->y_size / 2;
	data->zoom = 250.0;
	data->max_iterations = 20;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x_size, data->y_size, "Frctol");
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->color = 0;
}

void	free_resources(t_data *data)
{
	if (!data)
		return ;
	if (data->img != NULL)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (data->win != NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	read_input(void)
{
	char	c;
	char	temp;

	if (read(0, &c, 1) == -1)
	{
		write(1, "Error to read\n", 14);
		exit (1);
	}
	while (read(0, &temp, 1) > 0 && temp != '\n')
		write(1, "", 1);
	return (c);
}
