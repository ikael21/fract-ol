#include "../includes/fractol.h"

t_color	set_color(int iter, int max_iter)
{
	t_color	color;
	double	t;

	t = (double)iter / (double)max_iter;
	color.r = (int8_t)(t * 255);
	color.b = (int8_t)(t * 200);
	color.g = (int8_t)(t * 10);
	return (color);
}
