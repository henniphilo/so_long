
NAME = so_long

LIB = mlx_linux
LIBA = libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g # -fsanitize=address
RM = rm -f

SRC = so_long.c \


all: so_long

%.o: %.c
	$(CC) (CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(SRC) $(LIB)/$(LIBA)
	$(CC) $(CFLAGS) $(SRC) $(LIB)/$(LIBA) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIB)/$(LIBA):
	@$(MAKE) -C $(LIB)

clean:
	make -C $(LIB) clean

fclean: clean
	make -C $(LIB) fclean
	$(RM) so_long
re: fclean all

.PHONY: all clean fclean re
