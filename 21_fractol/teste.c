#include "minilibx-linux/mlx.h"
//#include "mlx.h"
//#include "minilibx-linux/mlx_int.h"

int main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Minha primeira janela");
	mlx_loop(mlx);
	return (0);
}

/*
cc teste.c -L minilibx-linux -lmlx -lXext -lX11 -o fractol
*/