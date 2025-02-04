/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:44:34 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/12/19 16:08:23 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	mouse_zoom_hook(int button, int x, int y, t_fractal *fractal)
{
	double	old_zoom;
	double	zoom_factor;

	old_zoom = fractal->zoom;
	if (button == 4)
		fractal->zoom *= ZOOM_STEP;
	else if (button == 5)
		fractal->zoom /= ZOOM_STEP;
	zoom_factor = fractal->zoom / old_zoom;
	fractal->offset_x += (x - WINDOW_WIDTH / 2) / old_zoom - (x - WINDOW_WIDTH
			/ 2) / fractal->zoom;
	fractal->offset_y += (y - WINDOW_HEIGHT / 2) / old_zoom - (y - WINDOW_HEIGHT
			/ 2) / fractal->zoom;
	draw_fractal(fractal);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keycode == 65307)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(0);
	}
	draw_fractal(fractal);
	return (0);
}

int	close_window(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
	return (0);
}