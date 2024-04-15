# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apancar <apancar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 16:48:18 by aliberk           #+#    #+#              #
#    Updated: 2024/02/03 07:37:46 by apancar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./includes/libft/libft.a

LFLAGS = -L ./includes/libft -lft

SOURCES = push_swap.c instructions/push.c instructions/reverse.c instructions/rotate.c \
	instructions/swap.c stack_settings.c stack_settings2.c sort.c utils.c upper_3.c \
	sort_utils.c case_one.c case_one_r.c case_two.c case_two_r.c calculate_price.c profitable.c \
	
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) $(LFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT): 
	make -C ./includes/libft

clean:
	rm -rf $(OBJECTS)
	make clean -C ./includes/libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./includes/libft

re: fclean all

.PHONY: all clean fclean re