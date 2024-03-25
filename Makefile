
NAME = so_long


LIB = ./MLX42/build
LIBA = libmlx42.a
LIBFT = libft
LIBFA = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f

SRC = so_long.c \
maps_check.c \
maps_open.c\
maps_prep.c \
i_like_to_move_it.c \
get_next_line.c \
look_like.c \
path_check.c \

OBJ = $(SRC:.c=.o)

all: so_long

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(LIB)/$(LIBA) $(LIBFT)/$(LIBFA)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIB) $(LIBFT)/$(LIBFA) -L/usr/MLX42 -lmlx42 -ldl -lglfw -lm -lpthread -o $(NAME)

$(LIB)/$(LIBA):
	@$(MAKE) -C $(LIB)

$(LIBFT)/$(LIBFA):
	@$(MAKE) -C $(LIBFT)

clean:
	make -C $(LIB) clean
	make -C $(LIBFT) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT) fclean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
