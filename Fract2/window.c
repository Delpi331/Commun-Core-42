#include "fract.h"

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(0);
	}
	return (0);
}
int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}