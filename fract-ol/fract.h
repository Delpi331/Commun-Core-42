#ifndef FRACT

# define FRACT
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define MAX_ITER 1000
# define ZOOM_STEP 1.1

# include "minilibx/mlx.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		zoom;
	double	offset_x;
	double	offset_y;
	int		img_width;
	int		img_height;
}			t_fractal;

int			mandelbrot(double real, double imag);
int			mouse_zoom_hook(int button, int x, int y, t_fractal *fractal);
int			key_hook(int keycode, void *param);
int			close_window(void *param);
void		draw_fractal(t_fractal *fractal);

#endif