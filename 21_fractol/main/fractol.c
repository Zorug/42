/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:42:18 by cgross-s          #+#    #+#             */
/*   Updated: 2025/03/08 23:11:34 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <string.h>

int	handle_close(t_data *data)
{
	if (!data)
		return (0);
	free_resources(data);
	exit (0);
	return (0);
}

void	hm_complement(t_data *dt)
{
	char	c;
	char	*str;

	if (dt->color == 5)
		dt->color = 0;
	else
		dt->color++;
	c = dt->color + '0';
	str = "Color set: ";
	write(1, str, ft_strlen(str));
	write(1, &c, 1);
	write(1, "\n", 1);
}

int	handle_mouse(int button, int x, int y, t_data *dt)
{
	double	zoom_factor;
	double	frac_x_bfr_zoom;
	double	frac_y_bfr_zoom;

	zoom_factor = 1.5;
	frac_x_bfr_zoom = x / dt->zoom - dt->x_size / (2 * dt->zoom) + dt->offset_x;
	frac_y_bfr_zoom = y / dt->zoom - dt->y_size / (2 * dt->zoom) + dt->offset_y;
	if (button == 4)
		dt->zoom *= zoom_factor;
	else if (button == 5)
		dt->zoom /= zoom_factor;
	else if (button == 1)
		hm_complement(dt);
	else if (button == 3)
		change_max_interations(dt);
	else
		return (0);
	dt->offset_x = frac_x_bfr_zoom - x / dt->zoom + dt->x_size / (2 * dt->zoom);
	dt->offset_y = frac_y_bfr_zoom - y / dt->zoom + dt->y_size / (2 * dt->zoom);
	//draw_fractal(dt);
	make_fractal(dt);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	double	move_factor;

	move_factor = 20;
	if (keycode == 65361)
		data->offset_x -= move_factor / data->zoom;
	else if (keycode == 65362)
		data->offset_y -= move_factor / data->zoom;
	else if (keycode == 65363)
		data->offset_x += move_factor / data->zoom;
	else if (keycode == 65364)
		data->offset_y += move_factor / data->zoom;
	else if (keycode == 65307)
	{
		if (!data)
			return (0);
		free_resources(data);
		exit(0);
	}
	//draw_fractal(data);
	make_fractal(data);
	return (0);
}

//int	main(void)
int	main(int argc, char **argv)
{
	t_data	data;
	char	*msg;

	msg = "Erro";
	if (argc == 2)
	{
		memset(&data, 0, sizeof(data));
		//get_input(&data);
		get_input(&data, argv[1]);
		if (data.set == 'J')
			julia_input(&data);
		data_init(&data);
		//draw_fractal(&data);
		make_fractal(&data);
		//
		mlx_hook(data.win, 17, 0, handle_close, &data);
		mlx_key_hook(data.win, handle_keypress, &data);
		mlx_mouse_hook(data.win, handle_mouse, &data);
		mlx_loop(data.mlx);
		free_resources(&data);
		return (0);
	}
	else
		write(1, msg, ft_strlen(msg));
}
/*
cc fractol.c complex_plane.c utils.c utilt.c 
utilu.c color_interac.c -L minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
*/