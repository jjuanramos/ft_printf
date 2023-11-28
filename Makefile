# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juramos <juramos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:43:25 by juramos           #+#    #+#              #
#    Updated: 2023/11/28 13:49:35 by juramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_write_s.c
LIBFT_PATH = ./libft
LIBFT_FLAG = -lft
# LINK_FLAGS = -L$(LIBFT_PATH) $(LIBFT_FLAG)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@make -C $(LIBFT_PATH) all
	@$(CC) -c $(CFLAGS) $< -o $@

libft:
	@make -C $(LIBFT_PATH) all

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

so: $(OBJ)
	$(CC) -nostartfiles -fPIC $(CFLAGS) -I$(LIBFT_PATH) -c $(SRC)
	$(CC) -nostartfiles -shared -o libftprintf.so $(OBJ) $(LINK_FLAGS)

.PHONY: all clean fclean re so libft
