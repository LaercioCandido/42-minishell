# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 21:10:53 by lcandido          #+#    #+#              #
#    Updated: 2021/09/29 18:13:05 by lcandido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes/minishell.h libraries/libft/libft.h
#LIBFT = libft
LIBFT = libraries/libft
#PRINTF = libraries/ft_printf


SRC = main.c\

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT)
		gcc $(CFLAGS) -fsanitize=address -g -o $(NAME) $(SRC) -L$(LIBFT) -lft -lreadline -lncurses -I includes

%.o: %.c
		gcc -c $< -I includes

git:
	@git add .
	@git commit -m "$m"
	@git push
#make git m="blablabla"

clean:
		make clean -C $(LIBFT)
		rm -f $(OBJ)

fclean: clean
		make fclean -C $(LIBFT)
		rm -f $(NAME) $(OBJ)

re: fclean all
