
NAME = so_long


LIB = ./MLX42/build
LIBA = libmlx42.a
LIBFT = libft
LIBFA = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g  # -fsanitize=address
RM = rm -f

SRC = 	src/so_long.c \
		src/maps_check.c \
		src/maps_open.c\
		src/maps_prep.c \
		src/i_like_to_move_it.c \
		src/get_next_line.c \
		src/get_next_line_utiles.c \
		src/look_like.c \
		src/path_check.c \

OBJ = $(SRC:.c=.o)

all: setup $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -Ilibft -I/usr/include -Imlx_linux -IMLX42/include/MLX42 -O3 -c $< -o $@

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

setup:
	git clone https://github.com/codam-coding-college/MLX42.git
	cd MLX42 && cmake -B build
	cmake --build MLX42/build -j4

.PHONY: all clean fclean re
