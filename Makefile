NAME = fractol

MAIN = srcs/main.c

MLX = srcs/minilibx/libmlx.a

FUNCS =		srcs/apply_zoom.c	srcs/error_occured.c\
			srcs/init_complex.c	srcs/init_fractol.c\
			srcs/put_pixel.c	srcs/set_color.c\
			srcs/ft_putstr_fd.c	srcs/ft_strcmp.c\
			srcs/mandelbrot.c	srcs/events.c\
			srcs/julia.c

O_FUNCS = $(patsubst %.c,%.o, $(FUNCS))
D_FILES = $(patsubst %.c,%.d, $(FUNCS))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MLX) $(O_FUNCS) $(MAIN)
	gcc $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(MAIN) $(MLX) $(O_FUNCS) -o $(NAME) -O3

$(MLX):
	make -C srcs/minilibx

%.o:%.c
	gcc $(FLAGS) -c $< -o $@ -O3 -MD

include $(wildcard $(D_FILES))

clean:
	rm -f $(O_FUNCS) $(D_FILES)
	make clean -C srcs/minilibx

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
