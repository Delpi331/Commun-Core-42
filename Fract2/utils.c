#include "fract.h"

int	julia(double zr, double zi, double cr, double ci, int max_iter)
{
	double	zr2;
	double	zi2;
	int		iterations;

	zr2 = zr * zr;
	zi2 = zi * zi;
	iterations = 0;
	while (zr2 + zi2 < 4.0 && iterations < max_iter)
	{
		zi = 2.0 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		zr2 = zr * zr;
		zi2 = zi * zi;
		iterations++;
	}
	return (iterations);
}
int	mandelbrot(double cr, double ci)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		iterations;

	zr = 0.0;
	zi = 0.0;
	zr2 = 0.0;
	zi2 = 0.0;
	iterations = 0;
	while (zr2 + zi2 < 4.0 && iterations < 100)
	{
		zi = 2.0 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		zr2 = zr * zr;
		zi2 = zi * zi;
		iterations++;
	}
	return (iterations);
}
int	zoom(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	mouse_re = fractal->min_re + (double)x / fractal->width * (fractal->max_re
			- fractal->min_re);
	mouse_im = fractal->min_im + (double)y / fractal->height * (fractal->max_im
			- fractal->min_im);

// printf("[ZOOM] Antes: min_re=%.5f, max_re=%.5f, min_im=%.5f, max_im=%.5f\n", 
// fractal->min_re, fractal->max_re, fractal->min_im, fractal->max_im);

	if (button == 4)
		zoom_factor = 1.0 / 1.1;
	else
		zoom_factor = 1.1;
	fractal->min_re = mouse_re + (fractal->min_re - mouse_re) * zoom_factor;
	fractal->max_re = mouse_re + (fractal->max_re - mouse_re) * zoom_factor;
	fractal->min_im = mouse_im + (fractal->min_im - mouse_im) * zoom_factor;
	fractal->max_im = mouse_im + (fractal->max_im - mouse_im) * zoom_factor;
	

// printf("[ZOOM] Después: min_re=%.5f, max_re=%.5f, min_im=%.5f, max_im=%.5f\n", 
// fractal->min_re, fractal->max_re, fractal->min_im, fractal->max_im);


	return (0);
}
int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4 || button == 5)
	{
		// printf("min_re: %f, max_re: %f, min_im: %f, max_im: %f\n", fractal->min_re, fractal->max_re, fractal->min_im, fractal->max_im);
		zoom(button, x, y, fractal);
		// printf("[MOUSE] max_iter=%d\n", fractal->max_iter);
		render_fractal(fractal, fractal->type, fractal->cr, fractal->ci);
		mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
		// printf("min_re: %f, max_re: %f, min_im: %f, max_im: %f\n", fractal->min_re, fractal->max_re, fractal->min_im, fractal->max_im);
	}
	return (0);
}
int	get_color(int iterations, int max_iter)
{
	double t = (double)iterations / max_iter;
	int r = (int)(9 * (1 - t) * t * t * t * 255);
	int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	return (r << 16 | g << 8 | b);
}