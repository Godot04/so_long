NAME	:= so_long.a
SRC_DIR	:= srcs
SRC		:= so_long.c
OBJ		:= $(SRC:.c=.o)
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror

MLX_DIR	:= minilibx-linux
MLX_LIB	:= -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

%.o: $(SRC_DIR)/%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
