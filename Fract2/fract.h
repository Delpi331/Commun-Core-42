#ifndef FRACT

# define FRACT
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define MAX_ITER 1000
# define ZOOM_STEP 1.1

# include "minilibx/mlx.h"
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}					t_fractal_type;

typedef struct s_fractal
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			zoom;
	int				width;
	int				height;
	int				max_iter;
	double			x_offset;
	double			y_offset;
	t_fractal_type	type;
	double			cr;
	double			ci;
}					t_fractal;


void				render_fractal(t_fractal *fractal, t_fractal_type type,
						double cr, double ci);
void				my_mlx_pixel_put(t_fractal *fractal, int x, int y,
						int color);
int					julia(double zr, double zi, double cr, double ci,
						int max_iter);
int					mandelbrot(double real, double imag);
int					mouse_hook(int button, int x, int y, t_fractal *fractal);
int					close_window(void *param);
int					get_color(int iterations, int max_iter);
int					zoom(int button, int x, int y, t_fractal *fractal);
int					key_hook(int keycode, t_fractal *fractal);

#endif