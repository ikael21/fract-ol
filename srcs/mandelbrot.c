#include "../includes/fractol.h"

static int	computation_mandel(t_fractol *fract, int x, int y)
{
	int		iter;
	double	z_re;
	double	z_im;

	fract->c = init_complex(
			fract->min.re + x * fract->factor.re,
			fract->max.im - y * fract->factor.im);
	fract->z = init_complex(fract->c.re, fract->c.im);
	iter = 0;
	z_re = fract->z.re * fract->z.re;
	z_im = fract->z.im * fract->z.im;
	while (z_re + z_im <= 4 && iter < fract->max_iter)
	{
		fract->z = init_complex(
				z_re - z_im + fract->c.re,
				2.0 * fract->z.re * fract->z.im + fract->c.im);
		z_re = fract->z.re * fract->z.re;
		z_im = fract->z.im * fract->z.im;
		iter++;
	}
	return (iter);
}

void	mandelbrot(t_fractol *fract)
{
	int		x;
	int		y;

	fract->factor = init_complex(
			(fract->max.re - fract->min.re) / (WIDTH - 1),
			(fract->max.im - fract->min.im) / (HEIGHT - 1));
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(&fract->img, x, y,
				set_color(computation_mandel(fract, x, y), fract->max_iter));
			x++;
		}
		y++;
	}
	mlx_clear_window(fract->mlx_params.mlx, fract->mlx_params.win);
	mlx_put_image_to_window(fract->mlx_params.mlx,
		fract->mlx_params.win, fract->img.img, 0, 0);
}
