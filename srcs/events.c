#include "../includes/fractol.h"

int	zoom_fractal(int keycode, int x_mouse,
				int y_mouse, t_fractol *fract)
{
	t_complex	mouse;

	mouse.re = (double)x_mouse
		/ (WIDTH / (fract->max.re - fract->min.re)) + fract->min.re;
	mouse.im = (double)y_mouse
		/ (HEIGHT / (fract->max.im - fract->min.im)) * -1 + fract->max.im;
	if (keycode == 5)
	{
		apply_zoom(fract, mouse, 1.20);
		if (fract->code == MANDELBROT)
			mandelbrot(fract);
		else
			julia(fract);
	}
	if (keycode == 4)
	{
		apply_zoom(fract, mouse, 0.80);
		if (fract->code == MANDELBROT)
			mandelbrot(fract);
		else
			julia(fract);
	}
	return (0);
}

int	motion(int x, int y, t_fractol *fract)
{
	if (fract->is_move == 1)
	{
		fract->k = init_complex(
				4 * ((double)x / WIDTH - 0.5),
				4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		julia(fract);
	}
	return (0);
}

int	is_key_pressed(int keycode, t_fractol *fract)
{
	if (keycode == 49 && fract->code == JULIA)
	{
		if (fract->is_move == 0)
			fract->is_move = 1;
		else
			fract->is_move = 0;
	}
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 126 || keycode == 125)
	{
		if (keycode == 126)
			fract->max_iter *= 1.2;
		if (keycode == 125)
		{
			if (fract->max_iter > 50)
				fract->max_iter *= 0.8;
		}
		if (fract->code == MANDELBROT)
			mandelbrot(fract);
		else
			julia(fract);
	}
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}
