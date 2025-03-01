NAME = so_long
SRC = so_long.c so_long_check.c so_long_utils.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		so_long_libft.c so_long_check_utils.c so_long_utils_utils.c \
		so_long_libft_utils.c so_long_utils_x3.c
OBJ = $(SRC:.c=.o)
CC = gcc

CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext

FTPRINTF_DIR = ./ft_printf
FTPRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a

all: $(FTPRINTF_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FTPRINTF_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FTPRINTF_LIB):
	$(MAKE) -C $(FTPRINTF_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
