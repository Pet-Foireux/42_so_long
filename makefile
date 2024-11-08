NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -Iincludes -Iminilibx-linux
LDFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lXrandr -lm
SRCS = srcs/main.c srcs/render.c srcs/init_map.c srcs/dispatcher.c srcs/utils.c srcs/check.c ft_printf/ft_printf.c
OBJ = $(SRCS:srcs/%.c=srcs/%.o) $(SRCS:ft_printf/%.c=ft_printf/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

ft_printf/%.o: ft_printf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
