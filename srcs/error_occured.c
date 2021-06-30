#include "../includes/fractol.h"

void	error_occured(void)
{
	ft_putstr_fd(RED "Error\n" RESET, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
