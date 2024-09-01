# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:31:15 by qrolland          #+#    #+#              #
#    Updated: 2022/11/25 22:53:52 by qrolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CFLAGS		= -Wall -Wextra -Werror
FILES		= pipex.c
LIBFT		= ./libft/libft.a  	
OBJ			= $(FILES:%.c=%.o)

all: $(NAME) 

$(LIBFT):
	@make all -C libft

$(NAME): $(OBJ) $(LIBFT)
	gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o : %.c
	gcc $(CFLAGS) -o $@ -c $< 

clean:
	rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: clean fclean all re bonus
