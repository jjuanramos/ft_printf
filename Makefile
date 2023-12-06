# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:43:25 by juramos           #+#    #+#              #
#    Updated: 2023/12/06 12:43:36 by juramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_write_s.c ft_write_d.c ft_write_c.c \
	ft_write_ptr.c ft_write_u.c ft_write_x.c
LIBFT_PATH = ./libft
LIBFT_FLAG = -lft
# LINK_FLAGS = -L$(LIBFT_PATH) $(LIBFT_FLAG)

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

%.o: %.c
	@make -C $(LIBFT_PATH) all
	@$(CC) -c $(CFLAGS) $< -o $@

libft:
	@make -C $(LIBFT_PATH) all

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_PATH)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

so: $(OBJ)
	$(CC) -nostartfiles -fPIC $(CFLAGS) -I$(LIBFT_PATH) -c $(SRC)
	$(CC) -nostartfiles -shared -o libftprintf.so $(OBJ) $(LINK_FLAGS)

norm:
	@norminette $(SRC) include $(LIBFT_PATH) | grep -v Norme -B1 || true

.PHONY: all clean fclean re so libft norm