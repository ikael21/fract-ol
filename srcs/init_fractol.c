#include "../includes/fractol.h"

void	init_fractol(t_fractol	*fract)
{
	fract->mlx_params.mlx = mlx_init();
	if (fract->mlx_params.mlx == NULL)
		error_occured();
	fract->mlx_params.win = mlx_new_window(
			fract->mlx_params.mlx, WIDTH, HEIGHT, "Fract-ol");
	if (fract->mlx_params.win == NULL)
		error_occured();
	fract->img.img = mlx_new_image(fract->mlx_params.mlx, WIDTH, HEIGHT);
	if (fract->img.img == NULL)
		error_occured();
	fract->img.addr = mlx_get_data_addr(
			fract->img.img, &fract->img.bits_per_pixel,
			&fract->img.line_length, &fract->img.endian);
}
