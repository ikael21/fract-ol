#include "../includes/fractol.h"

static double	interpolate(double start, double end, double k_inter)
{
	return (start + ((end - start) * k_inter));
}

void	apply_zoom(t_fractol *fract, t_complex mouse, double zoom_factor)
{
	double	k_inter;

	k_inter = 1.0 / zoom_factor;
	fract->min.re = interpolate(mouse.re, fract->min.re, k_inter);
	fract->min.im = interpolate(mouse.im, fract->min.im, k_inter);
	fract->max.re = interpolate(mouse.re, fract->max.re, k_inter);
	fract->max.im = interpolate(mouse.im, fract->max.im, k_inter);
}
