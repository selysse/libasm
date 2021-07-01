# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gselyse <marvin42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 20:01:41 by gselyse           #+#    #+#              #
#    Updated: 2020/10/21 19:57:54 by gselyse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = 	srcs/ft_strlen.s \
		srcs/ft_strcmp.s \
		srcs/ft_strcpy.s \
		srcs/ft_strdup.s \
		srcs/ft_write.s \
		srcs/ft_read.s \
		srcs/ft_strdup.s 

OBJ = $(SRCS:%.s=%.o)

%.o: %.s 
		nasm -f macho64 $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)

test: all
		touch text.txt
		chmod a+rw text.txt
		$(CC) main.c $(NAME) $(FLAGS)
		./a.out

clean:
		rm -rf $(OBJ)

fclean:	clean 
		rm -rf $(NAME)
		rm -f a.out
		rm -f text.txt

re: fclean all

.PHONY: all clean fclean re test