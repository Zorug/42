//#include "minilibx-linux/mlx.h"
//#include "mlx.h"
//#include "minilibx-linux/mlx_int.h"
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}

/*
cc teste.c -L minilibx-linux -lmlx -lXext -lX11 -o fractol


       mlx_new_window      : manage windows

       mlx_pixel_put       : draw inside window

       mlx_new_image       : manipulate images

       mlx_loop            : handle keyboard or mouse events

Interactions needed:
- Zoom in and out

mandelbrot set
f(z) = z^2 + c //z and c are complex numbers
z_0 = 0
z_(n+1) = (z_n)^2 + c

*/