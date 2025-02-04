#include "fract.h"

void	render_fractal(t_fractal *fractal, t_fractal_type type, double cr,
		double ci)
{
	int		color;
	int		iterations;
	int		x;
	int		y;
	double	re;
	double	im;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			re = fractal->min_re + (double)x / fractal->width * (fractal->max_re
					- fractal->min_re);
			im = fractal->min_im + (double)y / fractal->height
				* (fractal->max_im - fractal->min_im);

			// printf("x: %d, y: %d, re: %f, im: %f\n", x, y, re, im);
			if (type == MANDELBROT)
				iterations = mandelbrot(re, im);
			else
				iterations = julia(re, im, cr, ci, fractal->max_iter);
			color = get_color(iterations, fractal->max_iter);
			my_mlx_pixel_put(fractal, x, y, color);
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char *dst;

	dst = fractal->addr + (y * fractal->line_length + x * (fractal->bpp / 8));
	*(unsigned int *)dst = color;
}