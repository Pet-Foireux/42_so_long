NAME = SoLong
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -Iincludes -Iminilibx-linux -Ift_printf/includes
LDFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lXrandr -lm

SRCS = srcs/main.c srcs/render.c srcs/init_map.c srcs/dispatcher.c \
       ft_printf/src/ft_printf.c ft_printf/src/ft_puthex.c \
       ft_printf/src/ft_putnbr.c ft_printf/src/ft_putnsigned.c \
       ft_printf/src/ft_putptr.c ft_printf/src/ft_putstr_fd.c

OBJ = $(SRCS:srcs/%.c=srcs/%.o) $(SRCS:ft_printf/src/%.c=ft_printf/src/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

ft_printf/src/%.o: ft_printf/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
