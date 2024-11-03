NAME = ftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/ft_printf.c src/ft_puthex.c src/ft_putnbr.c src/ft_putnsigned.c src/ft_putptr.c src/ft_putstr_fd.c
OBJ = $(SRC:.c=.o)
INCLUDE = -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

tester:
	${CC} ${CFLAGS} ${SRC} test.c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all