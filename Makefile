
NAME = so_long

LIB = ./minilibx-linux
LIBA = libmlx.a
LIBFT = libft
LIBFA = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g # -fsanitize=address
RM = rm -f

SRC = *.c \


all: so_long

%.o: %.c
	$(CC) (CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(SRC) $(LIB)/$(LIBA) $(LIBFT)/$(LIBFA)
	$(CC) $(CFLAGS) $(SRC) -L$(LIB) $(LIBFT)/$(LIBFA) -lmlx -L/usr/minilibx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIB)/$(LIBA):
	@$(MAKE) -C $(LIB)

$(LIBFT)/$(LIBFA):
	@$(MAKE) -C $(LIBFT)

clean:
	make -C $(LIB) $(LIBFT) clean

fclean: clean
	make -C $(LIB) $(LIBFT) fclean
	$(RM) so_long
re: fclean all

.PHONY: all clean fclean re
