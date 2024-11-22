NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3
INCLUDES    = -Ibesoin/mlx -Ibesoin/mlx_linux -Ibesoin/libft
LIBS        = -Lbesoin/mlx -lmlx -lX11 -lXext -lXrandr -lm \
              -Lbesoin/libft -lft
SRC         = src/init.c src/main.c src/map.c src/print.c src/check.c src/printall.c src/handle_key.c src/chemin.c \
              besoin/gnl/get_next_line.c \
			  besoin/ft_printf/ft_printf.c
OBJ         = $(SRC:.c=.o)
LIBFT       = besoin/libft/libft.a
MLX         = besoin/mlx/libmlx.a

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -C besoin/libft

$(MLX):
	@make -C besoin/mlx

$(NAME): $(OBJ)
	@echo "Linking $(NAME)"
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C besoin/libft clean
	@make -C besoin/mlx clean

fclean: clean
	rm -f $(NAME)
	@make -C besoin/libft fclean
	@make -C besoin/mlx clean

re: fclean all

.PHONY: all clean fclean re