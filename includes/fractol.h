#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH		600
# define HEIGHT 	600
# define RED		"\33[1;31m"
# define YELLOW		"\x1b[33m"
# define RESET		"\33[0m"
# define MANDELBROT	1
# define JULIA		2

# include <stdlib.h>
# include <unistd.h>
# include "../srcs/minilibx/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_params
{
	void	*mlx;
	void	*win;
}	t_params;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	int			max_iter;
	t_params	mlx_params;
	t_data		img;
	t_complex	c;
	t_complex	z;
	t_complex	k;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	int			is_move;
	int			code;
}	t_fractol;

typedef struct s_color
{
	int8_t	r;
	int8_t	g;
	int8_t	b;
}	t_color;

void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(char *str1, char *str2);
void		error_occured(void);
void		init_fractol(t_fractol	*fract);
void		apply_zoom(t_fractol *fract, t_complex mouse, double zoom_factor);
t_color		set_color(int iter, int max_iter);
t_complex	init_complex(double re, double im);
void		put_pixel(t_data *data, int x, int y, t_color color);
void		mandelbrot(t_fractol *fract);
void		julia(t_fractol *fract);
int			zoom_fractal(int keycode, int x_mouse,
				int y_mouse, t_fractol *fract);
int			motion(int x, int y, t_fractol *fract);
int			is_key_pressed(int keycode, t_fractol *fract);
int			close_window(void *param);

#endif
