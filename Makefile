# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juramos <juramos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:43:25 by juramos           #+#    #+#              #
#    Updated: 2023/11/28 12:45:03 by juramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_write_s.c
LIBFT_PATH = libft
LIBFT_FLAG = -lft
LIBFT = libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: libft %.c
	$(CC) -c $(CFLAGS) -I$(LIBFT_PATH) $< -o $@

libft: $(LIBFT_PATH)/$(LIBFT)

$(LIBFT_PATH)/$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

so: $(OBJ)
	$(CC) -nostartfiles -fPIC $(CFLAGS) -I$(LIBFT_PATH) -c $(SRC)
	$(CC) -nostartfiles -shared -o libftprintf.so $(OBJ) -L$(LIBFT_PATH) $(LIBFT_FLAG)

.PHONY: all clean fclean re so libft
