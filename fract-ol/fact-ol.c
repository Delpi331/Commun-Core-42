/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact-ol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:43:34 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/01/07 17:37:19 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	generate_fractal(t_fractal *fractal)
{
	int	iteration;
	int	color;
	int	i;

	int x, y;
	double real, imag;
	fractal->img = mlx_new_image(fractal->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fractal->data = mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->size_line, &fractal->endian);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			real = (x - WINDOW_WIDTH / 2) / fractal->zoom + fractal->offset_x;
			imag = (y - WINDOW_HEIGHT / 2) / fractal->zoom + fractal->offset_y;
			iteration = mandelbrot(real, imag);
			if (iteration == MAX_ITER)
				color = 0x000000;
			else
				color = 0xFFFFFF * iteration / MAX_ITER;
			i = (y * fractal->size_line) + (x * (fractal->bpp / 8));
			*(int *)(fractal->data + i) = color;
			y++;
		}
		x++;
	}
}

void	draw_fractal(t_fractal *fractal)
{
	mlx_clear_window(fractal->mlx, fractal->win);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
int	main(void)
{
	void *mlx;
	void *win;
	t_fractal fractal;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Mandelbrot Fractal");
	if (!win)
		return (1);

	fractal.mlx = mlx_init();
	if (!fractal.mlx)
	{
		fprintf(stderr, "Error initializing mlx\n");
		return (1);
	}
	fractal.win = mlx_new_window(fractal.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Fractal");
	if (!fractal.win)
	{
		fprintf(stderr, "Error creating window\n");
		return (1);
	}
	fractal.zoom = 200.0;
	fractal.offset_x = -0.5;
	fractal.offset_y = 0.0;

	fractal.img = mlx_new_image(fractal.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!fractal.img)
	{
		fprintf(stderr, "Error creating image\n");
		return (1);
	}
	fractal.img = mlx_xpm_file_to_image(fractal.mlx, "path_to_image.xpm",
			&fractal.img_width, &fractal.img_height);
	if (!fractal.img)
	{
		fprintf(stderr, "Error loading image\n");
		return (1);
	}
	fractal.img = mlx_new_image(fractal.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!fractal.img)
	{
		fprintf(stderr, "Error creating image\n");
		return (1);
	}
	draw_fractal(&fractal);
	mlx_key_hook(win, key_hook, &fractal);
	mlx_hook(win, 17, 0, close_window, &fractal);
	mlx_mouse_hook(win, mouse_zoom_hook, &fractal);

	mlx_loop(mlx);
	return (0);
}