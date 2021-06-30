#include "../includes/fractol.h"

static void	init_complex_plane(t_fractol *fract)
{
	fract->min = init_complex(-2.0, -2.0);
	fract->max.re = 2.0;
	fract->max.im = fract->min.im
		+ (fract->max.re - fract->min.re) * HEIGHT / WIDTH;
	fract->max_iter = 50;
	fract->k = init_complex(-0.4, 0.6);
	fract->is_move = 0;
}

static void	usage(void)
{
	ft_putstr_fd(YELLOW "Usage: ./fractol 'fractol_name'\n" RESET,
		STDOUT_FILENO);
	ft_putstr_fd(RED "Fractol names:" RESET
		YELLOW "\n1.Mandelbrot\n2.Julia\n" RESET,
		STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}

static void	which_one(t_fractol *fract, char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
	{
		fract->code = MANDELBROT;
		mandelbrot(fract);
	}
	else
	{
		fract->code = JULIA;
		julia(fract);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc != 2 || (ft_strcmp(argv[1], "Mandelbrot") != 0
			&& ft_strcmp(argv[1], "Julia") != 0))
		usage();
	init_fractol(&fract);
	init_complex_plane(&fract);
	which_one(&fract, argv[1]);
	mlx_hook(fract.mlx_params.win, 2, 1L << 0, is_key_pressed, &fract);
	mlx_hook(fract.mlx_params.win, 4, 0, zoom_fractal, &fract);
	mlx_hook(fract.mlx_params.win, 6, 0, motion, &fract);
	mlx_hook(fract.mlx_params.win, 17, 0, close_window, NULL);
	mlx_loop(fract.mlx_params.mlx);
}
