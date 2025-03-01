# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opopov <opopov@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 11:46:31 by opopov            #+#    #+#              #
#    Updated: 2025/02/21 16:27:27 by opopov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := libftprintf.a
SRC_DIR := srcs
SRC     := ft_printf.c pathes/ch_path.c pathes/string_path.c  \
		   pathes/decimal_path.c pathes/unsigned_decimal_path.c \
		   pathes/hexadecimal_lower_path.c pathes/hexadecimal_upper_path.c \
		   pathes/void_path.c ft_printf_libft.c

OBJ     := $(SRC:.c=.o)
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
