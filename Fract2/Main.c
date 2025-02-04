#include "fract.h"

// gcc -o fractol utils.c Main.c fractal.c window.c -Iminilibx -Lminilibx -lmlx -lX11 -lXext -lm

int strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	main(int argc, char **argv)
{
	t_fractal		fractal;
	t_fractal_type	type;
	double			cr;
	double			ci;

	cr = 0.0;
	ci = 0.0;
	if (argc < 2)
		return(0);
	if (strcmp(argv[1], "mandelbrot") == 0)
		type = MANDELBROT;
	else if (strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			return(0);
		type = JULIA;
		cr = atof(argv[2]);
		ci = atof(argv[3]);
	}
	else
		return(0);
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, fractal.width, fractal.height, "Fractol");
	fractal.width = 800;
	fractal.height = 600;
	fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height);
	fractal.addr = mlx_get_data_addr(fractal.img, &fractal.bpp,
			&fractal.line_length, &fractal.endian);
	fractal.min_re = -2.0;
	fractal.max_re = 2.0;
	fractal.min_im = -1.5;
	fractal.max_im = 1.5;
	fractal.zoom = 15.0;
	fractal.x_offset = -2.0;
	fractal.y_offset = -1.5;
	fractal.max_iter = 100;
	render_fractal(&fractal, type, cr, ci);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img, 0, 0);
	mlx_hook(fractal.win, 17, 0, close_window, NULL);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
