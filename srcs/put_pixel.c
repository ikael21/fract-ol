#include "../includes/fractol.h"

void	put_pixel(t_data *data, int x, int y, t_color color)
{
	int	i;

	i = (x * data->bits_per_pixel / 8) + (y * data->line_length);
	data->addr[i] = color.b;
	data->addr[++i] = color.g;
	data->addr[++i] = color.r;
}
